
#include "big-int.h"
#include <napi.h>

namespace nodelinuxcec {

BigInt BigInt::New(napi_env env, uint64_t val) {
  napi_value value;
  napi_status status = napi_create_bigint_uint64(env, val, &value);
  if (status != napi_ok) throw Napi::Error::New(env);
  return BigInt(env, value);
}

BigInt::BigInt() : Napi::Value() {}

BigInt::BigInt(napi_env env, napi_value value) : Napi::Value(env, value) {}

BigInt::operator uint64_t() const { return Value(); }

uint64_t BigInt::Value() const {
  uint64_t value;
  bool lossless;
  napi_status status =
      napi_get_value_bigint_uint64(_env, _value, &value, &lossless);
  if (status != napi_ok || !lossless) throw Napi::Error::New(_env);
  return value;
}

}  // namespace nodelinuxcec
