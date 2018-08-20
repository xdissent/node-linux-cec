
#ifndef NODE_LINUX_CEC_TSFN_H_
#define NODE_LINUX_CEC_TSFN_H_

#include <napi.h>

namespace nodelinuxcec {

template <typename T>
class Tsfn {
 public:
  typedef void (T::*ExecuteCallback)(void* data, bool closing);
  typedef void (T::*FinalizeCallback)(void* data);

  Tsfn(const Napi::Object& receiver, const Napi::Function& callback,
       ExecuteCallback execute, FinalizeCallback finalize, int queue_size = 20,
       int thread_count = 1, void* finalize_data = nullptr);
  Tsfn(const Napi::Object& receiver, const Napi::Function& callback,
       const char* resource_name, const Napi::Object& resource, T* target,
       ExecuteCallback execute, FinalizeCallback finalize, int queue_size = 20,
       int thread_count = 1, void* finalize_data = nullptr);

  Napi::Env Env() const;
  Napi::ObjectReference& Receiver();
  Napi::FunctionReference& Callback();
  void Acquire();
  void Release();
  void Abort();
  void Call(void* data);

 private:
  static void OnExecute(napi_env env, napi_value callback, void* this_pointer,
                        void* data);
  static void OnFinalize(napi_env env, void* data, void* this_pointer);

  napi_env _env;
  Napi::ObjectReference _receiver;
  Napi::FunctionReference _callback;
  napi_threadsafe_function _tsfn;
  T* _target;
  ExecuteCallback _execute;
  FinalizeCallback _finalize;
};

}  // namespace nodelinuxcec

#include "tsfn-inl.h"

#endif  // NODE_LINUX_CEC_TSFN_H_
