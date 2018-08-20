
#ifndef NODE_LINUX_CEC_WORKER_H_
#define NODE_LINUX_CEC_WORKER_H_

#include <napi.h>

namespace nodelinuxcec {

class WorkerInfo {
 public:
  WorkerInfo(const Napi::Object& receiver,
             const Napi::Promise::Deferred& deferred, void* data);

  Napi::Env Env() const;
  Napi::ObjectReference& Receiver();
  Napi::Promise::Deferred& Deferred();
  void* Data() const;
  void SetData(void* data);

 private:
  napi_env _env;
  Napi::ObjectReference _receiver;
  Napi::Promise::Deferred _deferred;
  void* _data;
};

template <typename T>
class Worker : public Napi::AsyncWorker {
 public:
  typedef void (T::*InitCallback)(WorkerInfo* info,
                                  const Napi::CallbackInfo& cb_info);
  typedef void (T::*Callback)(WorkerInfo* info);
  typedef void (T::*ErrorCallback)(const Napi::Error& e, WorkerInfo* info);

  struct MethodDescriptor {
    InitCallback init;
    Callback execute;
    Callback ok;
    ErrorCallback error;
    Callback finalize;
    void* data;
  };

  static Napi::ClassPropertyDescriptor<T> InstanceMethod(
      const char* name, InitCallback init = nullptr, Callback execute = nullptr,
      Callback ok = nullptr, ErrorCallback error = nullptr,
      Callback finalize = nullptr, void* data = nullptr,
      napi_property_attributes attributes = napi_default);

  static napi_value MethodWrapper(napi_env env, napi_callback_info info);

  Worker(const Napi::Object& receiver, const Napi::Promise::Deferred& deferred,
         Callback execute = nullptr, Callback ok = nullptr,
         ErrorCallback error = nullptr, Callback finalize = nullptr,
         void* data = nullptr);

  ~Worker();

  WorkerInfo& Info() { return _info; }

 protected:
  void Execute();
  void OnOK();
  void OnError(const Napi::Error& e);

  T* _target;
  Callback _execute;
  Callback _ok;
  ErrorCallback _error;
  Callback _finalize;
  WorkerInfo _info;

 private:
  static void Noop(const Napi::CallbackInfo& info) {}
};

}  // namespace nodelinuxcec

#include "worker-inl.h"

#endif  // NODE_LINUX_CEC_WORKER_H_
