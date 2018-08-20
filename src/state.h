
#ifndef NODE_LINUX_CEC_STATE_H_
#define NODE_LINUX_CEC_STATE_H_

#include <uv.h>
#include <exception>

namespace nodelinuxcec {

template <typename T>
class State {
 public:
  State();
  ~State();

  void Lock();
  void Unlock();
  void Set(const T& state, bool lock = true, bool unlock = true);
  void Set(const T& state, const std::exception_ptr& error, bool lock = true,
           bool unlock = true);
  T Get(bool lock = true, bool unlock = true);
  void SetError(const std::exception_ptr& error, bool lock = true,
                bool unlock = true);
  void ClearError(bool lock = true, bool unlock = true);
  std::exception_ptr GetError(bool lock = true, bool unlock = true);
  bool Is(const T& state, bool lock = true, bool unlock = true);
  T Wait(bool lock = true, bool unlock = true);
  T Transition(const T& current, const T& next, bool lock = true,
               bool unlock = true);

 private:
  uv_mutex_t _mtx;
  uv_cond_t _cv;
  T _state;
  std::exception_ptr _error;
};

}  // namespace nodelinuxcec

#include "state-inl.h"

#endif  // NODE_LINUX_CEC_STATE_H_
