
#include <napi.h>
#include "worker.h"

namespace nodelinuxcec {

inline WorkerInfo::WorkerInfo(const Napi::Object& receiver,
                              const Napi::Promise::Deferred& deferred,
                              void* data)
    : _env(receiver.Env()),
      _receiver(Napi::Persistent(receiver)),
      _deferred(deferred),
      _data(data) {}

inline Napi::Env WorkerInfo::Env() const { return Napi::Env(_env); }

inline Napi::ObjectReference& WorkerInfo::Receiver() { return _receiver; }

inline void* WorkerInfo::Data() const { return _data; }

inline void WorkerInfo::SetData(void* data) { _data = data; }

inline Napi::Promise::Deferred& WorkerInfo::Deferred() { return _deferred; }

template <typename T>
inline Napi::ClassPropertyDescriptor<T> Worker<T>::InstanceMethod(
    const char* name, InitCallback init, Callback execute, Callback ok,
    ErrorCallback error, Callback finalize, void* data,
    napi_property_attributes attributes) {
  napi_property_descriptor desc = napi_property_descriptor();
  desc.utf8name = name;
  desc.method = &MethodWrapper;
  desc.data = new MethodDescriptor{init, execute, ok, error, finalize, data};
  desc.attributes = attributes;
  return desc;
}

template <typename T>
inline napi_value Worker<T>::MethodWrapper(napi_env env,
                                           napi_callback_info cb_info) {
  return Napi::details::WrapCallback([&] {
    Napi::CallbackInfo info(env, cb_info);
    MethodDescriptor* desc = reinterpret_cast<MethodDescriptor*>(info.Data());
    info.SetData(desc->data);
    T* instance = T::Unwrap(info.This().As<Napi::Object>());
    Napi::Promise::Deferred deferred = Napi::Promise::Deferred::New(info.Env());
    Worker<T>* worker = nullptr;
    try {
      worker =
          new Worker<T>(info.This().As<Napi::Object>(), deferred, desc->execute,
                        desc->ok, desc->error, desc->finalize);
      if (desc->init) (instance->*desc->init)(&worker->Info(), info);
      worker->Queue();
    } catch (const Napi::Error& e) {
      if (worker) delete worker;
      deferred.Reject(e.Value());
    }
    return deferred.Promise();
  });
}

template <typename T>
inline Worker<T>::Worker(const Napi::Object& receiver,
                         const Napi::Promise::Deferred& deferred,
                         Callback execute, Callback ok, ErrorCallback error,
                         Callback finalize, void* data)
    : Napi::AsyncWorker(receiver, Napi::Function::New(receiver.Env(), &Noop)),
      _target(T::Unwrap(receiver)),
      _execute(execute),
      _ok(ok),
      _error(error),
      _finalize(finalize),
      _info(receiver, deferred, data) {}

template <typename T>
inline Worker<T>::~Worker() {
  if (_finalize) (_target->*_finalize)(&_info);
}

template <typename T>
inline void Worker<T>::Execute() {
  if (_execute) (_target->*_execute)(&_info);
}

template <typename T>
inline void Worker<T>::OnOK() {
  if (_ok) return (_target->*_ok)(&_info);
  _info.Deferred().Resolve(Env().Undefined());
}

template <typename T>
inline void Worker<T>::OnError(const Napi::Error& e) {
  if (_error) return (_target->*_error)(e, &_info);
  _info.Deferred().Reject(e.Value());
}

}  // namespace nodelinuxcec
