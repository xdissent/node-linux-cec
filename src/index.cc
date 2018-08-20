
#include <napi.h>
#include "cec.h"
#include "device.h"

namespace nodelinuxcec {

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  exports = Device::Init(env, exports);
  return Cec::Init(env, exports);
}

NODE_API_MODULE(NODE_GYP_MODULE_NAME, Init)

}  // namespace nodelinuxcec
