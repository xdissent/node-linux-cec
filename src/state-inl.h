
#include <uv.h>
#include <exception>
#include <system_error>
#include "state.h"

namespace nodelinuxcec {

template <typename T>
inline State<T>::State() {
  int ret = uv_mutex_init(&_mtx);
  if (ret < 0) throw std::system_error(-ret, std::generic_category());
  ret = uv_cond_init(&_cv);
  if (ret < 0) {
    uv_mutex_destroy(&_mtx);
    throw std::system_error(-ret, std::generic_category());
  }
}

template <typename T>
inline State<T>::~State() {
  uv_mutex_destroy(&_mtx);
  uv_cond_destroy(&_cv);
}

template <typename T>
inline void State<T>::Lock() {
  uv_mutex_lock(&_mtx);
}

template <typename T>
inline void State<T>::Unlock() {
  uv_mutex_unlock(&_mtx);
}

template <typename T>
inline void State<T>::Set(const T& state, bool lock, bool unlock) {
  if (lock) Lock();
  _state = state;
  ClearError(false, false);
  uv_cond_broadcast(&_cv);
  if (unlock) Unlock();
}

template <typename T>
inline void State<T>::Set(const T& state, const std::exception_ptr& error,
                          bool lock, bool unlock) {
  if (lock) Lock();
  _state = state;
  SetError(error, false, false);
  uv_cond_broadcast(&_cv);
  if (unlock) Unlock();
}

template <typename T>
inline T State<T>::Get(bool lock, bool unlock) {
  if (lock) Lock();
  T state = _state;
  if (unlock) Unlock();
  return state;
}

template <typename T>
inline void State<T>::ClearError(bool lock, bool unlock) {
  if (lock) Lock();
  _error = nullptr;
  if (unlock) Unlock();
}

template <typename T>
inline void State<T>::SetError(const std::exception_ptr& error, bool lock,
                               bool unlock) {
  if (lock) Lock();
  _error = error;
  if (unlock) Unlock();
}

template <typename T>
inline std::exception_ptr State<T>::GetError(bool lock, bool unlock) {
  std::exception_ptr error;
  if (lock) Lock();
  error = _error;
  if (unlock) Unlock();
  return error;
}

template <typename T>
inline bool State<T>::Is(const T& state, bool lock, bool unlock) {
  if (lock) Lock();
  bool result = state == _state;
  if (unlock) Unlock();
  return result;
}

template <typename T>
inline T State<T>::Wait(bool lock, bool unlock) {
  if (lock) Lock();
  T state = _state;
  while (state == _state) uv_cond_wait(&_cv, &_mtx);
  state = _state;
  if (unlock) Unlock();
  return state;
}

template <typename T>
inline T State<T>::Transition(const T& current, const T& next, bool lock,
                              bool unlock) {
  if (lock) Lock();
  if (_state == current) {
    Set(next, false, false);
  } else if (_state == next) {
    Wait(false, false);
  }
  T state = _state;
  if (unlock) Unlock();
  return state;
}

}  // namespace nodelinuxcec
