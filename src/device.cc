
#include "device.h"
#include <linux/cec.h>
#include <napi.h>
#include <time.h>
#include <exception>
#include <stdexcept>
#include "big-int.h"
#include "small-int.h"
#include "types.h"
#include "worker.h"

namespace nodelinuxcec {

Napi::Object Device::Init(Napi::Env env, Napi::Object exports) {
  Napi::HandleScope scope(env);
  Napi::Function cls = DefineClass(
      env, "Device",
      {
          Worker<Device>::InstanceMethod("open", &Device::OpenInit,
                                         &Device::OpenExecute, &Device::OpenOk,
                                         nullptr, &Device::OpenFinalize),
          Worker<Device>::InstanceMethod("close", nullptr,
                                         &Device::CloseExecute),
          IoctlInstanceMethod<cec_event, Cec::Event>("dequeueEvent",
                                                     CEC_DQEVENT),
          IoctlInstanceMethod<cec_caps, Cec::Caps>("getCaps", CEC_ADAP_G_CAPS),
          IoctlInstanceMethod<__u16, SmallInt>("getPhysAddr",
                                               CEC_ADAP_G_PHYS_ADDR),
          IoctlInstanceMethod<__u16, SmallInt>("setPhysAddr",
                                               CEC_ADAP_S_PHYS_ADDR, true),
          IoctlInstanceMethod<cec_log_addrs, Cec::LogAddrs>(
              "getLogAddrs", CEC_ADAP_G_LOG_ADDRS),
          IoctlInstanceMethod<cec_log_addrs, Cec::LogAddrs>(
              "setLogAddrs", CEC_ADAP_S_LOG_ADDRS, true),
          IoctlInstanceMethod<cec_msg, Cec::Msg>("receive", CEC_RECEIVE),
          IoctlInstanceMethod<cec_msg, Cec::Msg>("transmit", CEC_TRANSMIT,
                                                 true),
          IoctlInstanceMethod<__u32, Napi::Number>("getMode", CEC_G_MODE),
          IoctlInstanceMethod<__u32, Napi::Number>("setMode", CEC_S_MODE, true),
          InstanceMethod("now", &Device::Now),
      });
  exports.Set("Device", cls);
  return exports;
}

template <typename P, typename V>
Napi::ClassPropertyDescriptor<Device> Device::IoctlInstanceMethod(
    const char* name, unsigned long int request, bool write) {
  return Worker<Device>::InstanceMethod(
      name, &Device::IoctlInit<P, V>, &Device::IoctlExecute<P, V>,
      &Device::IoctlOk<P, V>, nullptr, &Device::IoctlFinalize<P, V>,
      new IoctlMethodData{request, write});
}

Device::Device(const Napi::CallbackInfo& info)
    : Napi::ObjectWrap<Device>(info),
      _opened(false),
      _tsfn(nullptr),
      _thread(nullptr),
      _ctlr(nullptr) {
  if (info.Length() < 1 || !info[0].IsString())
    throw Napi::TypeError::New(info.Env(), "Invalid device path");
  _path = info[0].As<Napi::String>();
  _state.Set(States::Closed);
}

void Device::TsfnExecute(void* data, bool closing) {
  TsfnData* tsfn_data = static_cast<TsfnData*>(data);
  if (!closing) {
    switch (tsfn_data->event) {
      case Events::Open:
        _opened = true;
        _state.Set(States::Open);
        _tsfn->Callback().Call(_tsfn->Receiver().Value(),
                               {Napi::String::New(Env(), "open")});
        break;
      case Events::Event:
        _tsfn->Callback().Call(_tsfn->Receiver().Value(),
                               {Napi::String::New(Env(), "event"),
                                Cec::Event::New(Env(), tsfn_data->cec.event)});
        break;
      case Events::Message:
        _tsfn->Callback().Call(_tsfn->Receiver().Value(),
                               {Napi::String::New(Env(), "message"),
                                Cec::Msg::New(Env(), tsfn_data->cec.msg)});
        break;
    }
  }
  delete tsfn_data;
}

void Device::TsfnFinalize(void* data) {
  if (_thread) {
    _thread->Join();
    delete _thread;
    _thread = nullptr;
  }
  if (_ctlr) {
    delete _ctlr;
    _ctlr = nullptr;
  }
  _state.Set(States::Closed);
  if (_opened)
    _tsfn->Callback().Call(_tsfn->Receiver().Value(),
                           {Napi::String::New(Env(), "close")});
  _opened = false;
  _tsfn = nullptr;
}

void Device::ThreadExecute() {
  TsfnData* data = nullptr;
  bool aquired = false;

  _state.Lock();
  try {
    _ctlr->Open();
    _tsfn->Acquire();
    aquired = true;
    _tsfn->Call(data = new TsfnData{Events::Open, {}});
    data = nullptr;
  } catch (...) {
    if (data) delete data;
    if (aquired) _tsfn->Release();
    _state.Set(States::Closing, std::current_exception(), false);
    return;
  }

  if (_state.Wait(false) != States::Open) return;

  while (true) {
    Controller::Event event = _ctlr->Poll();
    _state.Lock();
    try {
      if (_state.Is(States::Closing, false, false)) break;
      if (!_state.Is(States::Open, false, false))
        throw std::runtime_error("No longer open");
      if (event.interrupt)
        throw std::runtime_error("Unexpected ctlr interrupt");
      if (event.prioritize) {
        data = new TsfnData{Events::Event, {}};
        _ctlr->Ioctl(CEC_DQEVENT, &data->cec.event);
        _tsfn->Call(data);
      }
      if (event.read) {
        data = new TsfnData{Events::Message, {}};
        _ctlr->Ioctl(CEC_RECEIVE, &data->cec.msg);
        _tsfn->Call(data);
      }
      data = nullptr;
    } catch (...) {
      if (data) delete data;
      _tsfn->Abort();
      if (!_state.Is(States::Closing, false, false))
        _state.Set(States::Closing, std::current_exception(), false, false);
      _state.Unlock();
      return;
    }
    _state.Unlock();
  }

  if (data) delete data;
  _tsfn->Release();
  _state.Unlock();
}

void Device::OpenInit(WorkerInfo* info, const Napi::CallbackInfo& cb_info) {
  info->SetData(new OpenData{});
}

void Device::OpenExecute(WorkerInfo* info) {
  OpenData* data = reinterpret_cast<OpenData*>(info->Data());
  data->state = _state.Transition(States::Closed, States::Opening);
  if (data->state != States::Opening && data->state != States::Open)
    throw std::runtime_error("Device is closing");
}

void Device::OpenOk(WorkerInfo* info) {
  Napi::HandleScope scope(info->Env());
  OpenData* data = reinterpret_cast<OpenData*>(info->Data());
  if (data->state == States::Open)
    return info->Deferred().Resolve(info->Env().Undefined());
  Napi::Object device;
  try {
    device = info->Receiver().Value().As<Napi::Object>();
    _tsfn = new Tsfn<Device>(device, device.Get("emit").As<Napi::Function>(),
                             &Device::TsfnExecute, &Device::TsfnFinalize);
  } catch (const Napi::Error& e) {
    // TODO: set error
    _state.Set(States::Closed);
    return info->Deferred().Reject(e.Value());
  }
  Worker<Device>* worker = nullptr;
  try {
    worker =
        new Worker<Device>(device, info->Deferred(), &Device::OpeningExecute);
    worker->Queue();
  } catch (const Napi::Error& e) {
    if (worker) delete worker;
    // TODO: set error
    _state.Set(States::Closing);
    _tsfn->Release();
    return info->Deferred().Reject(e.Value());
  }
}

void Device::OpenFinalize(WorkerInfo* info) {
  delete reinterpret_cast<OpenData*>(info->Data());
}

void Device::OpeningExecute(WorkerInfo* info) {
  States state;
  _state.Lock();
  try {
    _thread = new Thread<Device>(this, &Device::ThreadExecute);
    _ctlr = new Controller(_path);
  } catch (...) {
    // NOTE: Thread and ctlr are freed by tsfn finalize
    std::exception_ptr error = std::current_exception();
    _state.Set(States::Closing, error, false);
    _tsfn->Release();
    std::rethrow_exception(error);
  }
  state = _state.Wait(false, false);
  if (state != States::Open) {
    std::exception_ptr error = _state.GetError(false);
    if (state == States::Closing) _tsfn->Release();
    if (error) std::rethrow_exception(error);
    throw std::runtime_error("Opening failed: unknown error");
  }
  _state.Unlock();
}

void Device::CloseExecute(WorkerInfo* info) {
  States state = _state.Transition(States::Open, States::Closing);
  if (state == States::Closed) return;
  if (state != States::Closing) throw std::runtime_error("Device is opening");
  _state.Lock();
  try {
    _ctlr->Interrupt();
    _tsfn->Release();
  } catch (...) {
    // TODO: Set state back to Open? Probably just fatal err
    _state.Unlock();
    std::rethrow_exception(std::current_exception());
  }
  state = _state.Wait(false);
  if (state != States::Closed)
    throw std::runtime_error("Closing failed: unknown error");
}

template <typename P, typename V>
void Device::IoctlInit(WorkerInfo* info, const Napi::CallbackInfo& cb_info) {
  IoctlMethodData* data = reinterpret_cast<IoctlMethodData*>(cb_info.Data());
  info->SetData(data->write
                    ? new IoctlData<P, V>{data->request, cb_info[0].As<V>()}
                    : new IoctlData<P, V>{data->request, {}});
}

template <typename P, typename V>
void Device::IoctlExecute(WorkerInfo* info) {
  IoctlData<P, V>* data = reinterpret_cast<IoctlData<P, V>*>(info->Data());
  _state.Lock();
  if (!_state.Is(States::Open, false, false)) {
    _state.Unlock();
    throw std::runtime_error("Device not open");
  }
  try {
    _ctlr->Ioctl(data->request, &data->param);
  } catch (...) {
    // TODO: Close if dev error (set state to closing, ctlr interrupt, tsfn
    // release)
    _state.Unlock();
    std::rethrow_exception(std::current_exception());
  }
  _state.Unlock();
}

template <typename P, typename V>
void Device::IoctlOk(WorkerInfo* info) {
  IoctlData<P, V>* data = reinterpret_cast<IoctlData<P, V>*>(info->Data());
  info->Deferred().Resolve(V::New(info->Env(), data->param));
}

template <typename P, typename V>
void Device::IoctlFinalize(WorkerInfo* info) {
  delete reinterpret_cast<IoctlData<P, V>*>(info->Data());
}

Napi::Value Device::Now(const Napi::CallbackInfo& info) {
  timespec ts;
  if (clock_gettime(CLOCK_MONOTONIC, &ts) < 0)
    throw Napi::Error::New(info.Env());
  return BigInt::New(info.Env(), ts.tv_sec * 1000000000ull + ts.tv_nsec);
}

}  // namespace nodelinuxcec
