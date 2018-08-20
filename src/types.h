
#ifndef NODE_LINUX_CEC_TYPES_H_
#define NODE_LINUX_CEC_TYPES_H_

#include <sys/ioctl.h>  // Must load before linux/cec

#include <linux/cec-funcs.h>
#include <linux/cec.h>
#include <napi.h>

namespace nodelinuxcec {
namespace Cec {

class Event : public Napi::Object {
 public:
  static Event New(napi_env env, const cec_event& event);

  Event() : Object() {}
  Event(napi_env env, napi_value value) : Object(env, value) {}

  operator cec_event() const { return Value(); }
  cec_event Value() const;
};

class Msg : public Napi::Object {
 public:
  static Msg New(napi_env env, const cec_msg& msg);

  Msg() : Object() {}
  Msg(napi_env env, napi_value value) : Object(env, value) {}

  operator cec_msg() const { return Value(); }
  cec_msg Value() const;
};

class Caps : public Napi::Object {
 public:
  static Caps New(napi_env env, const cec_caps& caps);

  Caps() : Object() {}
  Caps(napi_env env, napi_value value) : Object(env, value) {}

  operator cec_caps() const { return Value(); }
  cec_caps Value() const;
};

class LogAddrs : public Napi::Object {
 public:
  static LogAddrs New(napi_env env, const cec_log_addrs& log_addrs);

  LogAddrs() : Object() {}
  LogAddrs(napi_env env, napi_value value) : Object(env, value) {}

  operator cec_log_addrs() const { return Value(); }
  cec_log_addrs Value() const;
};

class OpUiCommand : public Napi::Object {
 public:
  static OpUiCommand New(napi_env env, const cec_op_ui_command& op_ui_command);

  OpUiCommand() : Object() {}
  OpUiCommand(napi_env env, napi_value value) : Object(env, value) {}

  operator cec_op_ui_command() const { return Value(); }
  cec_op_ui_command Value() const;
};

class OpDigitalServiceId : public Napi::Object {
 public:
  static OpDigitalServiceId New(
      napi_env env, const cec_op_digital_service_id& op_digital_service_id);

  OpDigitalServiceId() : Object() {}
  OpDigitalServiceId(napi_env env, napi_value value) : Object(env, value) {}

  operator cec_op_digital_service_id() const { return Value(); }
  cec_op_digital_service_id Value() const;
};

class OpTunerDeviceInfo : public Napi::Object {
 public:
  static OpTunerDeviceInfo New(
      napi_env env, const cec_op_tuner_device_info& op_tuner_device_info);

  OpTunerDeviceInfo() : Object() {}
  OpTunerDeviceInfo(napi_env env, napi_value value) : Object(env, value) {}

  operator cec_op_tuner_device_info() const { return Value(); }
  cec_op_tuner_device_info Value() const;
};

class OpRecordSrc : public Napi::Object {
 public:
  static OpRecordSrc New(napi_env env, const cec_op_record_src& op_record_src);

  OpRecordSrc() : Object() {}
  OpRecordSrc(napi_env env, napi_value value) : Object(env, value) {}

  operator cec_op_record_src() const { return Value(); }
  cec_op_record_src Value() const;
};

}  // namespace Cec
}  // namespace nodelinuxcec

#endif  // NODE_LINUX_CEC_TYPES_H_
