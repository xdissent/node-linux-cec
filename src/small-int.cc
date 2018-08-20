
#include "small-int.h"
#include <napi.h>

#define UINT8_MASK 0xffffff00
#define UINT16_MASK 0xffff0000

namespace nodelinuxcec {

SmallInt SmallInt::New(napi_env env, uint16_t val) {
  napi_value value;
  napi_status status = napi_create_uint32(env, val, &value);
  if (status != napi_ok) throw Napi::Error::New(env);
  return SmallInt(env, value);
}

SmallInt::SmallInt() : Napi::Value() {}

SmallInt::SmallInt(napi_env env, napi_value value) : Napi::Value(env, value) {}

SmallInt::operator uint8_t() const { return Uint8Value(); }
SmallInt::operator uint16_t() const { return Uint16Value(); }

uint8_t SmallInt::Uint8Value() const {
  uint32_t value;
  napi_status status = napi_get_value_uint32(_env, _value, &value);
  if (status != napi_ok || value & UINT8_MASK) throw Napi::Error::New(_env);
  return (uint8_t)value;
}

uint16_t SmallInt::Uint16Value() const {
  uint32_t value;
  napi_status status = napi_get_value_uint32(_env, _value, &value);
  if (status != napi_ok || value & UINT16_MASK) throw Napi::Error::New(_env);
  return (uint16_t)value;
}

}  // namespace nodelinuxcec
