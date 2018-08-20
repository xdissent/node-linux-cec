
#ifndef NODE_LINUX_CEC_SMALL_INT_H_
#define NODE_LINUX_CEC_SMALL_INT_H_

#include <napi.h>

namespace nodelinuxcec {

class SmallInt : public Napi::Value {
 public:
  static SmallInt New(napi_env env, uint16_t val);

  SmallInt();
  SmallInt(napi_env env, napi_value value);

  operator uint8_t() const;
  operator uint16_t() const;

  uint8_t Uint8Value() const;
  uint16_t Uint16Value() const;
};

}  // namespace nodelinuxcec

#endif  // NODE_LINUX_CEC_SMALL_INT_H_
