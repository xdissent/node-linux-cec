
#include "thread.h"
#include <uv.h>
#include <exception>
#include <system_error>

namespace nodelinuxcec {

template <typename T>
Thread<T>::Thread(T* receiver, Callback callback)
    : _target(receiver), _execute(callback) {
  int ret = uv_thread_create(&_thread, OnExecute, this);
  if (ret < 0) throw std::system_error(-ret, std::generic_category());
}

template <typename T>
void Thread<T>::Join() {
  uv_thread_join(&_thread);
}

template <typename T>
void Thread<T>::OnExecute(void* this_pointer) {
  Thread* self = static_cast<Thread*>(this_pointer);
  (self->_target->*self->_execute)();
}

}  // namespace nodelinuxcec
