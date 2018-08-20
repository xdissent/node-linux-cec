
#ifndef NODE_LINUX_CEC_THREAD_H_
#define NODE_LINUX_CEC_THREAD_H_

#include <uv.h>

namespace nodelinuxcec {

template <typename T>
class Thread {
 public:
  typedef void (T::*Callback)();

  Thread(T* receiver, Callback callback);
  virtual ~Thread() {}

  void Join();

 private:
  static void OnExecute(void* this_pointer);

  uv_thread_t _thread;
  T* _target;
  Callback _execute;
};

}  // namespace nodelinuxcec

#include "thread-inl.h"

#endif  // NODE_LINUX_CEC_THREAD_H_
