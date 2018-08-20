
#include <napi.h>
#include <stdexcept>
#include "tsfn.h"

namespace nodelinuxcec {

template <typename T>
Tsfn<T>::Tsfn(const Napi::Object& receiver, const Napi::Function& callback,
              ExecuteCallback execute, FinalizeCallback finalize,
              int queue_size, int thread_count, void* finalize_data)
    : Tsfn<T>(receiver, callback, "Tsfn", Napi::Object::New(receiver.Env()),
              T::Unwrap(receiver), execute, finalize, queue_size, thread_count,
              finalize_data) {}

template <typename T>
Tsfn<T>::Tsfn(const Napi::Object& receiver, const Napi::Function& callback,
              const char* resource_name, const Napi::Object& resource,
              T* target, ExecuteCallback execute, FinalizeCallback finalize,
              int queue_size, int thread_count, void* finalize_data)
    : _env(receiver.Env()),
      _receiver(Napi::Persistent(receiver)),
      _callback(Napi::Persistent(callback)),
      _target(target),
      _execute(execute),
      _finalize(finalize) {
  napi_value resource_id;
  napi_status status = napi_create_string_latin1(
      _env, resource_name, NAPI_AUTO_LENGTH, &resource_id);
  if (status != napi_ok) throw Napi::Error::New(_env, "Tsfn create failed");
  status = napi_create_threadsafe_function(
      _env, _callback.Value(), resource, resource_id, queue_size, thread_count,
      finalize_data, OnFinalize, this, OnExecute, &_tsfn);
  if (status != napi_ok) throw Napi::Error::New(_env, "Tsfn create failed");
}

template <typename T>
Napi::Env Tsfn<T>::Env() const {
  return Napi::Env(_env);
}

template <typename T>
Napi::ObjectReference& Tsfn<T>::Receiver() {
  return _receiver;
}

template <typename T>
Napi::FunctionReference& Tsfn<T>::Callback() {
  return _callback;
}

template <typename T>
void Tsfn<T>::OnExecute(napi_env env, napi_value callback, void* this_pointer,
                        void* data) {
  Tsfn<T>* self = static_cast<Tsfn<T>*>(this_pointer);
  (self->_target->*self->_execute)(data, !(env && callback));
}

template <typename T>
void Tsfn<T>::OnFinalize(napi_env env, void* data, void* this_pointer) {
  Tsfn<T>* self = static_cast<Tsfn<T>*>(this_pointer);
  (self->_target->*self->_finalize)(data);
  delete self;
}

template <typename T>
void Tsfn<T>::Acquire() {
  napi_status status = napi_acquire_threadsafe_function(_tsfn);
  if (status != napi_ok) throw std::runtime_error("Tsfn acquire failed");
}

template <typename T>
void Tsfn<T>::Release() {
  napi_release_threadsafe_function(_tsfn, napi_tsfn_release);
}

template <typename T>
void Tsfn<T>::Abort() {
  napi_release_threadsafe_function(_tsfn, napi_tsfn_abort);
}

template <typename T>
void Tsfn<T>::Call(void* data) {
  napi_status status =
      napi_call_threadsafe_function(_tsfn, data, napi_tsfn_blocking);
  if (status != napi_ok) throw std::runtime_error("Tsfn call failed");
}

}  // namespace nodelinuxcec
