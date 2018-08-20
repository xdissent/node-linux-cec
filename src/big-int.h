
#ifndef NODE_LINUX_CEC_BIG_INT_H_
#define NODE_LINUX_CEC_BIG_INT_H_

#include <napi.h>

namespace nodelinuxcec {

class BigInt : public Napi::Value {
 public:
  static BigInt New(napi_env env, uint64_t val);

  BigInt();
  BigInt(napi_env env, napi_value value);

  operator uint64_t() const;

  uint64_t Value() const;
};

}  // namespace nodelinuxcec

#endif  // NODE_LINUX_CEC_BIG_INT_H_
