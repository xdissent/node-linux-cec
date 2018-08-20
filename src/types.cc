
#include "types.h"
#include <linux/cec-funcs.h>
#include <linux/cec.h>
#include <napi.h>
#include <string>
#include "big-int.h"
#include "small-int.h"

namespace nodelinuxcec {
namespace Cec {

Event Event::New(napi_env env, const cec_event& event) {
  Napi::Object value = Napi::Object::New(env);
  value["ts"] = BigInt::New(env, event.ts);
  value["event"] = Napi::Number::New(env, event.event);
  value["flags"] = Napi::Number::New(env, event.flags);

  switch (event.event) {
    case CEC_EVENT_STATE_CHANGE: {
      Napi::Object state_change = Napi::Object::New(env);
      state_change["physAddr"] =
          SmallInt::New(env, event.state_change.phys_addr);
      state_change["logAddrMask"] =
          SmallInt::New(env, event.state_change.log_addr_mask);
      value["stateChange"] = state_change;
      break;
    }
    case CEC_EVENT_LOST_MSGS: {
      Napi::Object lost_msgs = Napi::Object::New(env);
      lost_msgs["lostMsgs"] = Napi::Number::New(env, event.lost_msgs.lost_msgs);
      value["lostMsgs"] = lost_msgs;
      break;
    }
  }
  return Event(env, value);
}

cec_event Event::Value() const {
  cec_event event = {};
  Napi::Object value = Napi::Value(_env, _value).As<Napi::Object>();
  event.ts = value.Get("ts").As<BigInt>();
  event.event = value.Get("event").As<Napi::Number>();
  event.flags = value.Get("flags").As<Napi::Number>();
  switch (event.event) {
    case CEC_EVENT_STATE_CHANGE: {
      Napi::Object state_change = value.Get("stateChange").As<Napi::Object>();
      event.state_change.phys_addr =
          state_change.Get("physAddr").As<SmallInt>();
      event.state_change.log_addr_mask =
          state_change.Get("logAddrMask").As<SmallInt>();
      break;
    }
    case CEC_EVENT_LOST_MSGS: {
      Napi::Object lost_msgs = value.Get("lostMsgs").As<Napi::Object>();
      event.lost_msgs.lost_msgs = lost_msgs.Get("lostMsgs").As<Napi::Number>();
      break;
    }
  }
  return event;
}

Msg Msg::New(napi_env env, const cec_msg& msg) {
  Napi::Object value = Napi::Object::New(env);
  value["txTs"] = BigInt::New(env, msg.tx_ts);
  value["rxTs"] = BigInt::New(env, msg.rx_ts);
  value["len"] = Napi::Number::New(env, msg.len);
  value["timeout"] = Napi::Number::New(env, msg.timeout);
  value["sequence"] = Napi::Number::New(env, msg.sequence);
  value["flags"] = Napi::Number::New(env, msg.flags);

  Napi::Array msg_arr = Napi::Array::New(env);
  for (size_t i = 0; i < CEC_MAX_MSG_SIZE; i++)
    msg_arr[i] = SmallInt::New(env, msg.msg[i]);
  value["msg"] = msg_arr;

  value["reply"] = SmallInt::New(env, msg.reply);
  value["rxStatus"] = SmallInt::New(env, msg.rx_status);
  value["txStatus"] = SmallInt::New(env, msg.tx_status);
  value["txArbLostCnt"] = SmallInt::New(env, msg.tx_arb_lost_cnt);
  value["txNackCnt"] = SmallInt::New(env, msg.tx_nack_cnt);
  value["txLowDriveCnt"] = SmallInt::New(env, msg.tx_low_drive_cnt);
  value["txErrorCnt"] = SmallInt::New(env, msg.tx_error_cnt);
  return Msg(env, value);
}

cec_msg Msg::Value() const {
  cec_msg msg = {};
  Napi::Object value = Napi::Value(_env, _value).As<Napi::Object>();
  msg.tx_ts = value.Get("txTs").As<BigInt>();
  msg.rx_ts = value.Get("rxTs").As<BigInt>();
  msg.len = value.Get("len").As<Napi::Number>();
  msg.timeout = value.Get("timeout").As<Napi::Number>();
  msg.sequence = value.Get("sequence").As<Napi::Number>();
  msg.flags = value.Get("flags").As<Napi::Number>();

  Napi::Array msg_arr = value.Get("msg").As<Napi::Array>();
  for (size_t i = 0; i < CEC_MAX_MSG_SIZE; i++)
    msg.msg[i] = msg_arr.Get(i).As<SmallInt>();

  msg.reply = value.Get("reply").As<SmallInt>();
  msg.rx_status = value.Get("rxStatus").As<SmallInt>();
  msg.tx_status = value.Get("txStatus").As<SmallInt>();
  msg.tx_arb_lost_cnt = value.Get("txArbLostCnt").As<SmallInt>();
  msg.tx_nack_cnt = value.Get("txNackCnt").As<SmallInt>();
  msg.tx_low_drive_cnt = value.Get("txLowDriveCnt").As<SmallInt>();
  msg.tx_error_cnt = value.Get("txErrorCnt").As<SmallInt>();
  return msg;
}

Caps Caps::New(napi_env env, const cec_caps& caps) {
  Napi::Object value = Napi::Object::New(env);
  value["driver"] = Napi::String::New(env, caps.driver);
  value["name"] = Napi::String::New(env, caps.name);
  value["availableLogAddrs"] = Napi::Number::New(env, caps.available_log_addrs);
  value["capabilities"] = Napi::Number::New(env, caps.capabilities);
  value["version"] = Napi::Number::New(env, caps.version);
  return Caps(env, value);
}

cec_caps Caps::Value() const {
  cec_caps caps = {};
  Napi::Object value = Napi::Value(_env, _value).As<Napi::Object>();

  std::string driver = value.Get("driver").As<Napi::String>();
  if (driver.size() > 31) throw Napi::Error::New(_env);
  driver.copy(caps.driver, 31);

  std::string name = value.Get("name").As<Napi::String>();
  if (name.size() > 31) throw Napi::Error::New(_env);
  name.copy(caps.name, 31);

  caps.available_log_addrs = value.Get("availableLogAddrs").As<Napi::Number>();
  caps.capabilities = value.Get("capabilities").As<Napi::Number>();
  caps.version = value.Get("version").As<Napi::Number>();
  return caps;
}

LogAddrs LogAddrs::New(napi_env env, const cec_log_addrs& log_addrs) {
  Napi::Object value = Napi::Object::New(env);

  Napi::Array log_addr_arr = Napi::Array::New(env);
  for (size_t i = 0; i < CEC_MAX_LOG_ADDRS; i++)
    log_addr_arr[i] = SmallInt::New(env, log_addrs.log_addr[i]);
  value["logAddr"] = log_addr_arr;

  value["logAddrMask"] = SmallInt::New(env, log_addrs.log_addr_mask);
  value["cecVersion"] = SmallInt::New(env, log_addrs.cec_version);
  value["numLogAddrs"] = SmallInt::New(env, log_addrs.num_log_addrs);
  value["vendorId"] = Napi::Number::New(env, log_addrs.vendor_id);
  value["flags"] = Napi::Number::New(env, log_addrs.flags);
  value["osdName"] = Napi::String::New(env, log_addrs.osd_name);

  Napi::Array primary_device_type_arr = Napi::Array::New(env);
  for (size_t i = 0; i < CEC_MAX_LOG_ADDRS; i++)
    primary_device_type_arr[i] =
        SmallInt::New(env, log_addrs.primary_device_type[i]);
  value["primaryDeviceType"] = primary_device_type_arr;

  Napi::Array log_addr_type_arr = Napi::Array::New(env);
  for (size_t i = 0; i < CEC_MAX_LOG_ADDRS; i++)
    log_addr_type_arr[i] = SmallInt::New(env, log_addrs.log_addr_type[i]);
  value["logAddrType"] = log_addr_type_arr;

  Napi::Array all_device_types_arr = Napi::Array::New(env);
  for (size_t i = 0; i < CEC_MAX_LOG_ADDRS; i++)
    all_device_types_arr[i] = SmallInt::New(env, log_addrs.all_device_types[i]);
  value["allDeviceTypes"] = all_device_types_arr;

  Napi::Array features_arr = Napi::Array::New(env);
  for (size_t i = 0; i < CEC_MAX_LOG_ADDRS; i++) {
    Napi::Array features = Napi::Array::New(env);
    for (size_t j = 0; j < 12; j++)
      features[j] = SmallInt::New(env, log_addrs.features[i][j]);
    features_arr[i] = features;
  }
  value["features"] = features_arr;

  return LogAddrs(env, value);
}

cec_log_addrs LogAddrs::Value() const {
  cec_log_addrs log_addrs = {};
  Napi::Object value = Napi::Value(_env, _value).As<Napi::Object>();

  Napi::Array log_addr_arr = value.Get("logAddr").As<Napi::Array>();
  for (size_t i = 0; i < CEC_MAX_LOG_ADDRS; i++)
    log_addrs.log_addr[i] = log_addr_arr.Get(i).As<SmallInt>();

  log_addrs.log_addr_mask = value.Get("logAddrMask").As<SmallInt>();
  log_addrs.cec_version = value.Get("cecVersion").As<SmallInt>();
  log_addrs.num_log_addrs = value.Get("numLogAddrs").As<SmallInt>();
  log_addrs.vendor_id = value.Get("vendorId").As<Napi::Number>();
  log_addrs.flags = value.Get("flags").As<Napi::Number>();

  std::string osd_name = value.Get("osdName").As<Napi::String>();
  if (osd_name.size() > 14) throw Napi::Error::New(_env);
  osd_name.copy(log_addrs.osd_name, 14);

  Napi::Array primary_device_type_arr =
      value.Get("primaryDeviceType").As<Napi::Array>();
  for (size_t i = 0; i < CEC_MAX_LOG_ADDRS; i++)
    log_addrs.primary_device_type[i] =
        primary_device_type_arr.Get(i).As<SmallInt>();

  Napi::Array log_addr_type_arr = value.Get("logAddrType").As<Napi::Array>();
  for (size_t i = 0; i < CEC_MAX_LOG_ADDRS; i++)
    log_addrs.log_addr_type[i] = log_addr_type_arr.Get(i).As<SmallInt>();

  Napi::Array all_device_types_arr =
      value.Get("allDeviceTypes").As<Napi::Array>();
  for (size_t i = 0; i < CEC_MAX_LOG_ADDRS; i++)
    log_addrs.all_device_types[i] = all_device_types_arr.Get(i).As<SmallInt>();

  Napi::Array features_arr = value.Get("features").As<Napi::Array>();
  for (size_t i = 0; i < CEC_MAX_LOG_ADDRS; i++) {
    Napi::Array features = features_arr.Get(i).As<Napi::Array>();
    for (size_t j = 0; j < 12; j++) {
      log_addrs.features[i][j] = features.Get(j).As<SmallInt>();
    }
  }

  return log_addrs;
}

OpUiCommand OpUiCommand::New(napi_env env,
                             const cec_op_ui_command& op_ui_command) {
  Napi::Object value = Napi::Object::New(env);
  value["uiCmd"] = SmallInt::New(env, op_ui_command.ui_cmd);
  value["hasOptArg"] = Napi::Boolean::New(env, op_ui_command.has_opt_arg);
  if (!op_ui_command.has_opt_arg) return OpUiCommand(env, value);
  switch (op_ui_command.ui_cmd) {
    case 0x56:
      value["uiBroadcastType"] =
          SmallInt::New(env, op_ui_command.ui_broadcast_type);
      break;
    case 0x57:
      value["uiSoundPresentationControl"] =
          SmallInt::New(env, op_ui_command.ui_sound_presentation_control);
      break;
    case 0x60:
      value["playMode"] = SmallInt::New(env, op_ui_command.play_mode);
      break;
    case 0x68:
      value["uiFunctionMedia"] =
          SmallInt::New(env, op_ui_command.ui_function_media);
      break;
    case 0x69:
      value["uiFunctionSelectAvInput"] =
          SmallInt::New(env, op_ui_command.ui_function_select_av_input);
      break;
    case 0x6a:
      value["uiFunctionSelectAudioInput"] =
          SmallInt::New(env, op_ui_command.ui_function_select_audio_input);
      break;
    case 0x67: {
      Napi::Object channel_identifier = Napi::Object::New(env);
      channel_identifier["channelNumberFmt"] = SmallInt::New(
          env, op_ui_command.channel_identifier.channel_number_fmt);
      channel_identifier["major"] =
          SmallInt::New(env, op_ui_command.channel_identifier.major);
      channel_identifier["minor"] =
          SmallInt::New(env, op_ui_command.channel_identifier.minor);
      value["channelIdentifier"] = channel_identifier;
      break;
    }
  }
  return OpUiCommand(env, value);
}

cec_op_ui_command OpUiCommand::Value() const {
  cec_op_ui_command op_ui_command = {};
  Napi::Object value = Napi::Value(_env, _value).As<Napi::Object>();
  op_ui_command.ui_cmd = value.Get("uiCmd").As<SmallInt>();
  op_ui_command.has_opt_arg = value.Get("hasOptArg").As<Napi::Boolean>();
  if (!op_ui_command.has_opt_arg) return op_ui_command;
  switch (op_ui_command.ui_cmd) {
    case 0x56:
      op_ui_command.ui_broadcast_type =
          value.Get("uiBroadcastType").As<SmallInt>();
      break;
    case 0x57:
      op_ui_command.ui_sound_presentation_control =
          value.Get("uiSoundPresentationControl").As<SmallInt>();
      break;
    case 0x60:
      op_ui_command.play_mode = value.Get("playMode").As<SmallInt>();
      break;
    case 0x68:
      op_ui_command.ui_function_media =
          value.Get("uiFunctionMedia").As<SmallInt>();
      break;
    case 0x69:
      op_ui_command.ui_function_select_av_input =
          value.Get("uiFunctionSelectAvInput").As<SmallInt>();
      break;
    case 0x6a:
      op_ui_command.ui_function_select_audio_input =
          value.Get("uiFunctionSelectAudioInput").As<SmallInt>();
      break;
    case 0x67: {
      Napi::Object channel_identifier =
          value.Get("channelIdentifier").As<Object>();
      op_ui_command.channel_identifier.channel_number_fmt =
          channel_identifier.Get("channelNumberFmt").As<SmallInt>();
      op_ui_command.channel_identifier.major =
          channel_identifier.Get("major").As<SmallInt>();
      op_ui_command.channel_identifier.minor =
          channel_identifier.Get("minor").As<SmallInt>();
      break;
    }
  }
  return op_ui_command;
}

OpDigitalServiceId OpDigitalServiceId::New(
    napi_env env, const cec_op_digital_service_id& op_digital_service_id) {
  Napi::Object value = Napi::Object::New(env);
  value["serviceIdMethod"] =
      SmallInt::New(env, op_digital_service_id.service_id_method);
  value["digBcastSystem"] =
      SmallInt::New(env, op_digital_service_id.dig_bcast_system);
  if (op_digital_service_id.service_id_method ==
      CEC_OP_SERVICE_ID_METHOD_BY_CHANNEL) {
    Napi::Object channel = Napi::Object::New(env);
    channel["channelNumberFmt"] =
        SmallInt::New(env, op_digital_service_id.channel.channel_number_fmt);
    channel["major"] = SmallInt::New(env, op_digital_service_id.channel.major);
    channel["minor"] = SmallInt::New(env, op_digital_service_id.channel.minor);
    value["channel"] = channel;
    return OpDigitalServiceId(env, value);
  }
  switch (op_digital_service_id.dig_bcast_system) {
    case CEC_OP_DIG_SERVICE_BCAST_SYSTEM_ATSC_GEN:
    case CEC_OP_DIG_SERVICE_BCAST_SYSTEM_ATSC_CABLE:
    case CEC_OP_DIG_SERVICE_BCAST_SYSTEM_ATSC_SAT:
    case CEC_OP_DIG_SERVICE_BCAST_SYSTEM_ATSC_T: {
      Napi::Object atsc = Napi::Object::New(env);
      atsc["transportId"] =
          SmallInt::New(env, op_digital_service_id.atsc.transport_id);
      atsc["programNumber"] =
          SmallInt::New(env, op_digital_service_id.atsc.program_number);
      value["atsc"] = atsc;
      break;
    }
    default: {
      Napi::Object dvb = Napi::Object::New(env);
      dvb["transportId"] =
          SmallInt::New(env, op_digital_service_id.dvb.transport_id);
      dvb["serviceId"] =
          SmallInt::New(env, op_digital_service_id.dvb.service_id);
      dvb["origNetworkId"] =
          SmallInt::New(env, op_digital_service_id.dvb.orig_network_id);
      value["dvb"] = dvb;
      break;
    }
  }
  return OpDigitalServiceId(env, value);
}

cec_op_digital_service_id OpDigitalServiceId::Value() const {
  cec_op_digital_service_id op_digital_service_id = {};
  Napi::Object value = Napi::Value(_env, _value).As<Napi::Object>();
  op_digital_service_id.service_id_method =
      value.Get("serviceIdMethod").As<SmallInt>();
  op_digital_service_id.dig_bcast_system =
      value.Get("digBcastSystem").As<SmallInt>();
  if (op_digital_service_id.service_id_method ==
      CEC_OP_SERVICE_ID_METHOD_BY_CHANNEL) {
    Napi::Object channel = value.Get("channel").As<Object>();
    op_digital_service_id.channel.channel_number_fmt =
        channel.Get("channelNumberFmt").As<SmallInt>();
    op_digital_service_id.channel.major = channel.Get("major").As<SmallInt>();
    op_digital_service_id.channel.minor = channel.Get("minor").As<SmallInt>();
    return op_digital_service_id;
  }
  switch (op_digital_service_id.dig_bcast_system) {
    case CEC_OP_DIG_SERVICE_BCAST_SYSTEM_ATSC_GEN:
    case CEC_OP_DIG_SERVICE_BCAST_SYSTEM_ATSC_CABLE:
    case CEC_OP_DIG_SERVICE_BCAST_SYSTEM_ATSC_SAT:
    case CEC_OP_DIG_SERVICE_BCAST_SYSTEM_ATSC_T: {
      Napi::Object atsc = value.Get("atsc").As<Object>();
      op_digital_service_id.atsc.transport_id =
          atsc.Get("transportId").As<SmallInt>();
      op_digital_service_id.atsc.program_number =
          atsc.Get("programNumber").As<SmallInt>();
      break;
    }
    default: {
      Napi::Object dvb = value.Get("dvb").As<Object>();
      op_digital_service_id.dvb.transport_id =
          dvb.Get("transportId").As<SmallInt>();
      op_digital_service_id.dvb.service_id =
          dvb.Get("serviceId").As<SmallInt>();
      op_digital_service_id.dvb.orig_network_id =
          dvb.Get("origNetworkId").As<SmallInt>();
      break;
    }
  }
  return op_digital_service_id;
}

OpTunerDeviceInfo OpTunerDeviceInfo::New(
    napi_env env, const cec_op_tuner_device_info& op_tuner_device_info) {
  Napi::Object value = Napi::Object::New(env);
  value["recFlag"] = SmallInt::New(env, op_tuner_device_info.rec_flag);
  value["tunerDisplayInfo"] =
      SmallInt::New(env, op_tuner_device_info.tuner_display_info);
  value["isAnalog"] = Napi::Boolean::New(env, op_tuner_device_info.is_analog);
  if (!op_tuner_device_info.is_analog) {
    value["digital"] =
        OpDigitalServiceId::New(env, op_tuner_device_info.digital);
    return OpTunerDeviceInfo(env, value);
  }
  Napi::Object analog = Napi::Object::New(env);
  analog["anaBcastType"] =
      SmallInt::New(env, op_tuner_device_info.analog.ana_bcast_type);
  analog["anaFreq"] = SmallInt::New(env, op_tuner_device_info.analog.ana_freq);
  analog["bcastSystem"] =
      SmallInt::New(env, op_tuner_device_info.analog.bcast_system);
  value["analog"] = analog;
  return OpTunerDeviceInfo(env, value);
}

cec_op_tuner_device_info OpTunerDeviceInfo::Value() const {
  cec_op_tuner_device_info op_tuner_device_info = {};
  Napi::Object value = Napi::Value(_env, _value).As<Napi::Object>();
  op_tuner_device_info.rec_flag = value.Get("recFlag").As<SmallInt>();
  op_tuner_device_info.tuner_display_info =
      value.Get("tunerDisplayInfo").As<SmallInt>();
  op_tuner_device_info.is_analog = value.Get("isAnalog").As<Napi::Boolean>();
  if (!op_tuner_device_info.is_analog) {
    op_tuner_device_info.digital =
        value.Get("digital").As<OpDigitalServiceId>();
    return op_tuner_device_info;
  }

  Napi::Object analog = value.Get("analog").As<Napi::Object>();
  op_tuner_device_info.analog.ana_bcast_type =
      analog.Get("anaBcastType").As<SmallInt>();
  op_tuner_device_info.analog.ana_freq = analog.Get("anaFreq").As<SmallInt>();
  op_tuner_device_info.analog.bcast_system =
      analog.Get("bcastSystem").As<SmallInt>();

  return op_tuner_device_info;
}

OpRecordSrc OpRecordSrc::New(napi_env env,
                             const cec_op_record_src& op_record_src) {
  Napi::Object value = Napi::Object::New(env);
  value["type"] = SmallInt::New(env, op_record_src.type);
  switch (op_record_src.type) {
    case CEC_OP_RECORD_SRC_DIGITAL:
      value["digital"] = OpDigitalServiceId::New(env, op_record_src.digital);
      break;
    case CEC_OP_RECORD_SRC_ANALOG: {
      Napi::Object analog = Napi::Object::New(env);
      analog["anaBcastType"] =
          SmallInt::New(env, op_record_src.analog.ana_bcast_type);
      analog["anaFreq"] = SmallInt::New(env, op_record_src.analog.ana_freq);
      analog["bcastSystem"] =
          SmallInt::New(env, op_record_src.analog.bcast_system);
      value["analog"] = analog;
      break;
    }
    case CEC_OP_RECORD_SRC_EXT_PLUG: {
      Napi::Object ext_plug = Napi::Object::New(env);
      ext_plug["plug"] = SmallInt::New(env, op_record_src.ext_plug.plug);
      value["extPlug"] = ext_plug;
      break;
    }
    case CEC_OP_RECORD_SRC_EXT_PHYS_ADDR: {
      Napi::Object ext_phys_addr = Napi::Object::New(env);
      ext_phys_addr["physAddr"] =
          SmallInt::New(env, op_record_src.ext_phys_addr.phys_addr);
      value["extPhysAddr"] = ext_phys_addr;
      break;
    }
    case CEC_OP_RECORD_SRC_OWN:
    default:
      break;
  }
  return OpRecordSrc(env, value);
}

cec_op_record_src OpRecordSrc::Value() const {
  cec_op_record_src op_record_src = {};
  Napi::Object value = Napi::Value(_env, _value).As<Napi::Object>();
  op_record_src.type = value.Get("type").As<SmallInt>();
  switch (op_record_src.type) {
    case CEC_OP_RECORD_SRC_DIGITAL:
      op_record_src.digital = value.Get("digital").As<OpDigitalServiceId>();
      break;
    case CEC_OP_RECORD_SRC_ANALOG: {
      Napi::Object analog = value.Get("analog").As<Napi::Object>();
      op_record_src.analog.ana_bcast_type =
          analog.Get("anaBcastType").As<SmallInt>();
      op_record_src.analog.ana_freq = analog.Get("anaFreq").As<SmallInt>();
      op_record_src.analog.bcast_system =
          analog.Get("bcastSystem").As<SmallInt>();
      break;
    }
    case CEC_OP_RECORD_SRC_EXT_PLUG: {
      Napi::Object ext_plug = value.Get("extPlug").As<Napi::Object>();
      op_record_src.ext_plug.plug = ext_plug.Get("plug").As<SmallInt>();
      break;
    }
    case CEC_OP_RECORD_SRC_EXT_PHYS_ADDR: {
      Napi::Object ext_phys_addr = value.Get("extPhysAddr").As<Napi::Object>();
      op_record_src.ext_phys_addr.phys_addr =
          ext_phys_addr.Get("physAddr").As<SmallInt>();
      break;
    }
    case CEC_OP_RECORD_SRC_OWN:
    default:
      break;
  }
  return op_record_src;
}

}  // namespace Cec
}  // namespace nodelinuxcec
