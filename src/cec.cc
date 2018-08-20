
#include "cec.h"
#include <linux/cec-funcs.h>
#include <linux/cec.h>
#include <napi.h>
#include "small-int.h"
#include "types.h"

namespace nodelinuxcec {
namespace Cec {

Napi::Value MsgInitiator(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  return SmallInt::New(info.Env(), cec_msg_initiator(&msg));
}

Napi::Value MsgDestination(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  return SmallInt::New(info.Env(), cec_msg_destination(&msg));
}

Napi::Value MsgOpcode(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  return Napi::Number::New(info.Env(), cec_msg_opcode(&msg));
}

Napi::Value MsgIsBroadcast(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  return Napi::Boolean::New(info.Env(), cec_msg_is_broadcast(&msg));
}

Napi::Value MsgInit(const Napi::CallbackInfo& info) {
  cec_msg msg;
  __u8 initiator = info[0].As<SmallInt>();
  __u8 destination = info[1].As<SmallInt>();
  cec_msg_init(&msg, initiator, destination);
  return Msg::New(info.Env(), msg);
}

Napi::Value MsgSetReplyTo(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  cec_msg orig = info[1].As<Msg>();
  cec_msg_set_reply_to(&msg, &orig);
  return Msg::New(info.Env(), msg);
}

Napi::Value MsgStatusIsOk(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  return Napi::Boolean::New(info.Env(), cec_msg_status_is_ok(&msg));
}

Napi::Value HasTv(const Napi::CallbackInfo& info) {
  __u16 log_addr_mask = info[0].As<SmallInt>();
  return Napi::Boolean::New(info.Env(), cec_has_tv(log_addr_mask));
}

Napi::Value HasRecord(const Napi::CallbackInfo& info) {
  __u16 log_addr_mask = info[0].As<SmallInt>();
  return Napi::Boolean::New(info.Env(), cec_has_record(log_addr_mask));
}

Napi::Value HasTuner(const Napi::CallbackInfo& info) {
  __u16 log_addr_mask = info[0].As<SmallInt>();
  return Napi::Boolean::New(info.Env(), cec_has_tuner(log_addr_mask));
}

Napi::Value HasPlayback(const Napi::CallbackInfo& info) {
  __u16 log_addr_mask = info[0].As<SmallInt>();
  return Napi::Boolean::New(info.Env(), cec_has_playback(log_addr_mask));
}

Napi::Value HasAudiosystem(const Napi::CallbackInfo& info) {
  __u16 log_addr_mask = info[0].As<SmallInt>();
  return Napi::Boolean::New(info.Env(), cec_has_audiosystem(log_addr_mask));
}

Napi::Value HasBackup(const Napi::CallbackInfo& info) {
  __u16 log_addr_mask = info[0].As<SmallInt>();
  return Napi::Boolean::New(info.Env(), cec_has_backup(log_addr_mask));
}

Napi::Value HasSpecific(const Napi::CallbackInfo& info) {
  __u16 log_addr_mask = info[0].As<SmallInt>();
  return Napi::Boolean::New(info.Env(), cec_has_specific(log_addr_mask));
}

Napi::Value IsUnregistered(const Napi::CallbackInfo& info) {
  __u16 log_addr_mask = info[0].As<SmallInt>();
  return Napi::Boolean::New(info.Env(), cec_is_unregistered(log_addr_mask));
}

Napi::Value IsUnconfigured(const Napi::CallbackInfo& info) {
  __u16 log_addr_mask = info[0].As<SmallInt>();
  return Napi::Boolean::New(info.Env(), cec_is_unconfigured(log_addr_mask));
}

Napi::Value Is2ndTv(const Napi::CallbackInfo& info) {
  cec_log_addrs las = info[0].As<LogAddrs>();
  return Napi::Boolean::New(info.Env(), cec_is_2nd_tv(&las));
}

Napi::Value IsProcessor(const Napi::CallbackInfo& info) {
  cec_log_addrs las = info[0].As<LogAddrs>();
  return Napi::Boolean::New(info.Env(), cec_is_processor(&las));
}

Napi::Value IsSwitch(const Napi::CallbackInfo& info) {
  cec_log_addrs las = info[0].As<LogAddrs>();
  return Napi::Boolean::New(info.Env(), cec_is_switch(&las));
}

Napi::Value IsCdcOnly(const Napi::CallbackInfo& info) {
  cec_log_addrs las = info[0].As<LogAddrs>();
  return Napi::Boolean::New(info.Env(), cec_is_cdc_only(&las));
}

Napi::Value MsgActiveSource(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  __u16 phys_addr = info[1].As<SmallInt>();
  cec_msg_active_source(&msg, phys_addr);
  return Msg::New(info.Env(), msg);
}

Napi::Value OpsActiveSource(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  __u16 phys_addr = 0;
  cec_ops_active_source(&msg, &phys_addr);
  Napi::Value ret = SmallInt::New(info.Env(), phys_addr);
  return ret;
}

Napi::Value MsgImageViewOn(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  cec_msg_image_view_on(&msg);
  return Msg::New(info.Env(), msg);
}

Napi::Value MsgTextViewOn(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  cec_msg_text_view_on(&msg);
  return Msg::New(info.Env(), msg);
}

Napi::Value MsgInactiveSource(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  __u16 phys_addr = info[1].As<SmallInt>();
  cec_msg_inactive_source(&msg, phys_addr);
  return Msg::New(info.Env(), msg);
}

Napi::Value OpsInactiveSource(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  __u16 phys_addr = 0;
  cec_ops_inactive_source(&msg, &phys_addr);
  Napi::Value ret = SmallInt::New(info.Env(), phys_addr);
  return ret;
}

Napi::Value MsgRequestActiveSource(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  int reply = info[1].As<Napi::Boolean>();
  cec_msg_request_active_source(&msg, reply);
  return Msg::New(info.Env(), msg);
}

Napi::Value MsgRoutingInformation(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  __u16 phys_addr = info[1].As<SmallInt>();
  cec_msg_routing_information(&msg, phys_addr);
  return Msg::New(info.Env(), msg);
}

Napi::Value OpsRoutingInformation(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  __u16 phys_addr = 0;
  cec_ops_routing_information(&msg, &phys_addr);
  Napi::Value ret = SmallInt::New(info.Env(), phys_addr);
  return ret;
}

Napi::Value MsgRoutingChange(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  int reply = info[1].As<Napi::Boolean>();
  __u16 orig_phys_addr = info[2].As<SmallInt>();
  __u16 new_phys_addr = info[3].As<SmallInt>();
  cec_msg_routing_change(&msg, reply, orig_phys_addr, new_phys_addr);
  return Msg::New(info.Env(), msg);
}

Napi::Value OpsRoutingChange(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  __u16 orig_phys_addr = 0;
  __u16 new_phys_addr = 0;
  cec_ops_routing_change(&msg, &orig_phys_addr, &new_phys_addr);
  Napi::Object ret = Napi::Object::New(info.Env());
  ret["origPhysAddr"] = SmallInt::New(info.Env(), orig_phys_addr);
  ret["newPhysAddr"] = SmallInt::New(info.Env(), new_phys_addr);
  return ret;
}

Napi::Value MsgSetStreamPath(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  __u16 phys_addr = info[1].As<SmallInt>();
  cec_msg_set_stream_path(&msg, phys_addr);
  return Msg::New(info.Env(), msg);
}

Napi::Value OpsSetStreamPath(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  __u16 phys_addr = 0;
  cec_ops_set_stream_path(&msg, &phys_addr);
  Napi::Value ret = SmallInt::New(info.Env(), phys_addr);
  return ret;
}

Napi::Value MsgStandby(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  cec_msg_standby(&msg);
  return Msg::New(info.Env(), msg);
}

Napi::Value MsgRecordOff(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  int reply = info[1].As<Napi::Boolean>();
  cec_msg_record_off(&msg, reply);
  return Msg::New(info.Env(), msg);
}

Napi::Value SetDigitalServiceId(const Napi::CallbackInfo& info) {
  __u8 msg[CEC_MAX_MSG_SIZE] = {0};
  cec_op_digital_service_id digital = info[0].As<OpDigitalServiceId>();
  cec_set_digital_service_id(msg, &digital);
  Napi::Array msg_arr = Napi::Array::New(info.Env());
  uint32_t msg_i;
  for (msg_i = 0; msg_i < CEC_MAX_MSG_SIZE; msg_i++)
    msg_arr[msg_i] = SmallInt::New(info.Env(), msg[msg_i]);
  Napi::Value ret = msg_arr;
  return ret;
}

Napi::Value GetDigitalServiceId(const Napi::CallbackInfo& info) {
  Napi::Array msg_arr = info[0].As<Napi::Array>();
  uint32_t msg_len = msg_arr.Length();
  uint32_t msg_i;
  __u8 msg[msg_len] = {0};
  for (msg_i = 0; msg_i < msg_len; msg_i++)
    msg[msg_i] = msg_arr.Get(msg_i).As<SmallInt>();
  cec_op_digital_service_id digital = {};
  cec_get_digital_service_id(msg, &digital);
  Napi::Value ret = OpDigitalServiceId::New(info.Env(), digital);
  return ret;
}

Napi::Value MsgRecordOnOwn(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  cec_msg_record_on_own(&msg);
  return Msg::New(info.Env(), msg);
}

Napi::Value MsgRecordOnDigital(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  cec_op_digital_service_id digital = info[1].As<OpDigitalServiceId>();
  cec_msg_record_on_digital(&msg, &digital);
  return Msg::New(info.Env(), msg);
}

Napi::Value MsgRecordOnAnalog(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  __u8 ana_bcast_type = info[1].As<SmallInt>();
  __u16 ana_freq = info[2].As<SmallInt>();
  __u8 bcast_system = info[3].As<SmallInt>();
  cec_msg_record_on_analog(&msg, ana_bcast_type, ana_freq, bcast_system);
  return Msg::New(info.Env(), msg);
}

Napi::Value MsgRecordOnPlug(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  __u8 plug = info[1].As<SmallInt>();
  cec_msg_record_on_plug(&msg, plug);
  return Msg::New(info.Env(), msg);
}

Napi::Value MsgRecordOnPhysAddr(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  __u16 phys_addr = info[1].As<SmallInt>();
  cec_msg_record_on_phys_addr(&msg, phys_addr);
  return Msg::New(info.Env(), msg);
}

Napi::Value MsgRecordOn(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  int reply = info[1].As<Napi::Boolean>();
  cec_op_record_src rec_src = info[2].As<OpRecordSrc>();
  cec_msg_record_on(&msg, reply, &rec_src);
  return Msg::New(info.Env(), msg);
}

Napi::Value OpsRecordOn(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  cec_op_record_src rec_src = {};
  cec_ops_record_on(&msg, &rec_src);
  Napi::Value ret = OpRecordSrc::New(info.Env(), rec_src);
  return ret;
}

Napi::Value MsgRecordStatus(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  __u8 rec_status = info[1].As<SmallInt>();
  cec_msg_record_status(&msg, rec_status);
  return Msg::New(info.Env(), msg);
}

Napi::Value OpsRecordStatus(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  __u8 rec_status = 0;
  cec_ops_record_status(&msg, &rec_status);
  Napi::Value ret = SmallInt::New(info.Env(), rec_status);
  return ret;
}

Napi::Value MsgRecordTvScreen(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  int reply = info[1].As<Napi::Boolean>();
  cec_msg_record_tv_screen(&msg, reply);
  return Msg::New(info.Env(), msg);
}

Napi::Value MsgTimerStatus(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  __u8 timer_overlap_warning = info[1].As<SmallInt>();
  __u8 media_info = info[2].As<SmallInt>();
  __u8 prog_info = info[3].As<SmallInt>();
  __u8 prog_error = info[4].As<SmallInt>();
  __u8 duration_hr = info[5].As<SmallInt>();
  __u8 duration_min = info[6].As<SmallInt>();
  cec_msg_timer_status(&msg, timer_overlap_warning, media_info, prog_info,
                       prog_error, duration_hr, duration_min);
  return Msg::New(info.Env(), msg);
}

Napi::Value OpsTimerStatus(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  __u8 timer_overlap_warning = 0;
  __u8 media_info = 0;
  __u8 prog_info = 0;
  __u8 prog_error = 0;
  __u8 duration_hr = 0;
  __u8 duration_min = 0;
  cec_ops_timer_status(&msg, &timer_overlap_warning, &media_info, &prog_info,
                       &prog_error, &duration_hr, &duration_min);
  Napi::Object ret = Napi::Object::New(info.Env());
  ret["timerOverlapWarning"] = SmallInt::New(info.Env(), timer_overlap_warning);
  ret["mediaInfo"] = SmallInt::New(info.Env(), media_info);
  ret["progInfo"] = SmallInt::New(info.Env(), prog_info);
  ret["progError"] = SmallInt::New(info.Env(), prog_error);
  ret["durationHr"] = SmallInt::New(info.Env(), duration_hr);
  ret["durationMin"] = SmallInt::New(info.Env(), duration_min);
  return ret;
}

Napi::Value MsgTimerClearedStatus(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  __u8 timer_cleared_status = info[1].As<SmallInt>();
  cec_msg_timer_cleared_status(&msg, timer_cleared_status);
  return Msg::New(info.Env(), msg);
}

Napi::Value OpsTimerClearedStatus(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  __u8 timer_cleared_status = 0;
  cec_ops_timer_cleared_status(&msg, &timer_cleared_status);
  Napi::Value ret = SmallInt::New(info.Env(), timer_cleared_status);
  return ret;
}

Napi::Value MsgClearAnalogueTimer(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  int reply = info[1].As<Napi::Boolean>();
  __u8 day = info[2].As<SmallInt>();
  __u8 month = info[3].As<SmallInt>();
  __u8 start_hr = info[4].As<SmallInt>();
  __u8 start_min = info[5].As<SmallInt>();
  __u8 duration_hr = info[6].As<SmallInt>();
  __u8 duration_min = info[7].As<SmallInt>();
  __u8 recording_seq = info[8].As<SmallInt>();
  __u8 ana_bcast_type = info[9].As<SmallInt>();
  __u16 ana_freq = info[10].As<SmallInt>();
  __u8 bcast_system = info[11].As<SmallInt>();
  cec_msg_clear_analogue_timer(&msg, reply, day, month, start_hr, start_min,
                               duration_hr, duration_min, recording_seq,
                               ana_bcast_type, ana_freq, bcast_system);
  return Msg::New(info.Env(), msg);
}

Napi::Value OpsClearAnalogueTimer(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  __u8 day = 0;
  __u8 month = 0;
  __u8 start_hr = 0;
  __u8 start_min = 0;
  __u8 duration_hr = 0;
  __u8 duration_min = 0;
  __u8 recording_seq = 0;
  __u8 ana_bcast_type = 0;
  __u16 ana_freq = 0;
  __u8 bcast_system = 0;
  cec_ops_clear_analogue_timer(&msg, &day, &month, &start_hr, &start_min,
                               &duration_hr, &duration_min, &recording_seq,
                               &ana_bcast_type, &ana_freq, &bcast_system);
  Napi::Object ret = Napi::Object::New(info.Env());
  ret["day"] = SmallInt::New(info.Env(), day);
  ret["month"] = SmallInt::New(info.Env(), month);
  ret["startHr"] = SmallInt::New(info.Env(), start_hr);
  ret["startMin"] = SmallInt::New(info.Env(), start_min);
  ret["durationHr"] = SmallInt::New(info.Env(), duration_hr);
  ret["durationMin"] = SmallInt::New(info.Env(), duration_min);
  ret["recordingSeq"] = SmallInt::New(info.Env(), recording_seq);
  ret["anaBcastType"] = SmallInt::New(info.Env(), ana_bcast_type);
  ret["anaFreq"] = SmallInt::New(info.Env(), ana_freq);
  ret["bcastSystem"] = SmallInt::New(info.Env(), bcast_system);
  return ret;
}

Napi::Value MsgClearDigitalTimer(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  int reply = info[1].As<Napi::Boolean>();
  __u8 day = info[2].As<SmallInt>();
  __u8 month = info[3].As<SmallInt>();
  __u8 start_hr = info[4].As<SmallInt>();
  __u8 start_min = info[5].As<SmallInt>();
  __u8 duration_hr = info[6].As<SmallInt>();
  __u8 duration_min = info[7].As<SmallInt>();
  __u8 recording_seq = info[8].As<SmallInt>();
  cec_op_digital_service_id digital = info[9].As<OpDigitalServiceId>();
  cec_msg_clear_digital_timer(&msg, reply, day, month, start_hr, start_min,
                              duration_hr, duration_min, recording_seq,
                              &digital);
  return Msg::New(info.Env(), msg);
}

Napi::Value OpsClearDigitalTimer(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  __u8 day = 0;
  __u8 month = 0;
  __u8 start_hr = 0;
  __u8 start_min = 0;
  __u8 duration_hr = 0;
  __u8 duration_min = 0;
  __u8 recording_seq = 0;
  cec_op_digital_service_id digital = {};
  cec_ops_clear_digital_timer(&msg, &day, &month, &start_hr, &start_min,
                              &duration_hr, &duration_min, &recording_seq,
                              &digital);
  Napi::Object ret = Napi::Object::New(info.Env());
  ret["day"] = SmallInt::New(info.Env(), day);
  ret["month"] = SmallInt::New(info.Env(), month);
  ret["startHr"] = SmallInt::New(info.Env(), start_hr);
  ret["startMin"] = SmallInt::New(info.Env(), start_min);
  ret["durationHr"] = SmallInt::New(info.Env(), duration_hr);
  ret["durationMin"] = SmallInt::New(info.Env(), duration_min);
  ret["recordingSeq"] = SmallInt::New(info.Env(), recording_seq);
  ret["digital"] = OpDigitalServiceId::New(info.Env(), digital);
  return ret;
}

Napi::Value MsgClearExtTimer(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  int reply = info[1].As<Napi::Boolean>();
  __u8 day = info[2].As<SmallInt>();
  __u8 month = info[3].As<SmallInt>();
  __u8 start_hr = info[4].As<SmallInt>();
  __u8 start_min = info[5].As<SmallInt>();
  __u8 duration_hr = info[6].As<SmallInt>();
  __u8 duration_min = info[7].As<SmallInt>();
  __u8 recording_seq = info[8].As<SmallInt>();
  __u8 ext_src_spec = info[9].As<SmallInt>();
  __u8 plug = info[10].As<SmallInt>();
  __u16 phys_addr = info[11].As<SmallInt>();
  cec_msg_clear_ext_timer(&msg, reply, day, month, start_hr, start_min,
                          duration_hr, duration_min, recording_seq,
                          ext_src_spec, plug, phys_addr);
  return Msg::New(info.Env(), msg);
}

Napi::Value OpsClearExtTimer(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  __u8 day = 0;
  __u8 month = 0;
  __u8 start_hr = 0;
  __u8 start_min = 0;
  __u8 duration_hr = 0;
  __u8 duration_min = 0;
  __u8 recording_seq = 0;
  __u8 ext_src_spec = 0;
  __u8 plug = 0;
  __u16 phys_addr = 0;
  cec_ops_clear_ext_timer(&msg, &day, &month, &start_hr, &start_min,
                          &duration_hr, &duration_min, &recording_seq,
                          &ext_src_spec, &plug, &phys_addr);
  Napi::Object ret = Napi::Object::New(info.Env());
  ret["day"] = SmallInt::New(info.Env(), day);
  ret["month"] = SmallInt::New(info.Env(), month);
  ret["startHr"] = SmallInt::New(info.Env(), start_hr);
  ret["startMin"] = SmallInt::New(info.Env(), start_min);
  ret["durationHr"] = SmallInt::New(info.Env(), duration_hr);
  ret["durationMin"] = SmallInt::New(info.Env(), duration_min);
  ret["recordingSeq"] = SmallInt::New(info.Env(), recording_seq);
  ret["extSrcSpec"] = SmallInt::New(info.Env(), ext_src_spec);
  ret["plug"] = SmallInt::New(info.Env(), plug);
  ret["physAddr"] = SmallInt::New(info.Env(), phys_addr);
  return ret;
}

Napi::Value MsgSetAnalogueTimer(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  int reply = info[1].As<Napi::Boolean>();
  __u8 day = info[2].As<SmallInt>();
  __u8 month = info[3].As<SmallInt>();
  __u8 start_hr = info[4].As<SmallInt>();
  __u8 start_min = info[5].As<SmallInt>();
  __u8 duration_hr = info[6].As<SmallInt>();
  __u8 duration_min = info[7].As<SmallInt>();
  __u8 recording_seq = info[8].As<SmallInt>();
  __u8 ana_bcast_type = info[9].As<SmallInt>();
  __u16 ana_freq = info[10].As<SmallInt>();
  __u8 bcast_system = info[11].As<SmallInt>();
  cec_msg_set_analogue_timer(&msg, reply, day, month, start_hr, start_min,
                             duration_hr, duration_min, recording_seq,
                             ana_bcast_type, ana_freq, bcast_system);
  return Msg::New(info.Env(), msg);
}

Napi::Value OpsSetAnalogueTimer(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  __u8 day = 0;
  __u8 month = 0;
  __u8 start_hr = 0;
  __u8 start_min = 0;
  __u8 duration_hr = 0;
  __u8 duration_min = 0;
  __u8 recording_seq = 0;
  __u8 ana_bcast_type = 0;
  __u16 ana_freq = 0;
  __u8 bcast_system = 0;
  cec_ops_set_analogue_timer(&msg, &day, &month, &start_hr, &start_min,
                             &duration_hr, &duration_min, &recording_seq,
                             &ana_bcast_type, &ana_freq, &bcast_system);
  Napi::Object ret = Napi::Object::New(info.Env());
  ret["day"] = SmallInt::New(info.Env(), day);
  ret["month"] = SmallInt::New(info.Env(), month);
  ret["startHr"] = SmallInt::New(info.Env(), start_hr);
  ret["startMin"] = SmallInt::New(info.Env(), start_min);
  ret["durationHr"] = SmallInt::New(info.Env(), duration_hr);
  ret["durationMin"] = SmallInt::New(info.Env(), duration_min);
  ret["recordingSeq"] = SmallInt::New(info.Env(), recording_seq);
  ret["anaBcastType"] = SmallInt::New(info.Env(), ana_bcast_type);
  ret["anaFreq"] = SmallInt::New(info.Env(), ana_freq);
  ret["bcastSystem"] = SmallInt::New(info.Env(), bcast_system);
  return ret;
}

Napi::Value MsgSetDigitalTimer(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  int reply = info[1].As<Napi::Boolean>();
  __u8 day = info[2].As<SmallInt>();
  __u8 month = info[3].As<SmallInt>();
  __u8 start_hr = info[4].As<SmallInt>();
  __u8 start_min = info[5].As<SmallInt>();
  __u8 duration_hr = info[6].As<SmallInt>();
  __u8 duration_min = info[7].As<SmallInt>();
  __u8 recording_seq = info[8].As<SmallInt>();
  cec_op_digital_service_id digital = info[9].As<OpDigitalServiceId>();
  cec_msg_set_digital_timer(&msg, reply, day, month, start_hr, start_min,
                            duration_hr, duration_min, recording_seq, &digital);
  return Msg::New(info.Env(), msg);
}

Napi::Value OpsSetDigitalTimer(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  __u8 day = 0;
  __u8 month = 0;
  __u8 start_hr = 0;
  __u8 start_min = 0;
  __u8 duration_hr = 0;
  __u8 duration_min = 0;
  __u8 recording_seq = 0;
  cec_op_digital_service_id digital = {};
  cec_ops_set_digital_timer(&msg, &day, &month, &start_hr, &start_min,
                            &duration_hr, &duration_min, &recording_seq,
                            &digital);
  Napi::Object ret = Napi::Object::New(info.Env());
  ret["day"] = SmallInt::New(info.Env(), day);
  ret["month"] = SmallInt::New(info.Env(), month);
  ret["startHr"] = SmallInt::New(info.Env(), start_hr);
  ret["startMin"] = SmallInt::New(info.Env(), start_min);
  ret["durationHr"] = SmallInt::New(info.Env(), duration_hr);
  ret["durationMin"] = SmallInt::New(info.Env(), duration_min);
  ret["recordingSeq"] = SmallInt::New(info.Env(), recording_seq);
  ret["digital"] = OpDigitalServiceId::New(info.Env(), digital);
  return ret;
}

Napi::Value MsgSetExtTimer(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  int reply = info[1].As<Napi::Boolean>();
  __u8 day = info[2].As<SmallInt>();
  __u8 month = info[3].As<SmallInt>();
  __u8 start_hr = info[4].As<SmallInt>();
  __u8 start_min = info[5].As<SmallInt>();
  __u8 duration_hr = info[6].As<SmallInt>();
  __u8 duration_min = info[7].As<SmallInt>();
  __u8 recording_seq = info[8].As<SmallInt>();
  __u8 ext_src_spec = info[9].As<SmallInt>();
  __u8 plug = info[10].As<SmallInt>();
  __u16 phys_addr = info[11].As<SmallInt>();
  cec_msg_set_ext_timer(&msg, reply, day, month, start_hr, start_min,
                        duration_hr, duration_min, recording_seq, ext_src_spec,
                        plug, phys_addr);
  return Msg::New(info.Env(), msg);
}

Napi::Value OpsSetExtTimer(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  __u8 day = 0;
  __u8 month = 0;
  __u8 start_hr = 0;
  __u8 start_min = 0;
  __u8 duration_hr = 0;
  __u8 duration_min = 0;
  __u8 recording_seq = 0;
  __u8 ext_src_spec = 0;
  __u8 plug = 0;
  __u16 phys_addr = 0;
  cec_ops_set_ext_timer(&msg, &day, &month, &start_hr, &start_min, &duration_hr,
                        &duration_min, &recording_seq, &ext_src_spec, &plug,
                        &phys_addr);
  Napi::Object ret = Napi::Object::New(info.Env());
  ret["day"] = SmallInt::New(info.Env(), day);
  ret["month"] = SmallInt::New(info.Env(), month);
  ret["startHr"] = SmallInt::New(info.Env(), start_hr);
  ret["startMin"] = SmallInt::New(info.Env(), start_min);
  ret["durationHr"] = SmallInt::New(info.Env(), duration_hr);
  ret["durationMin"] = SmallInt::New(info.Env(), duration_min);
  ret["recordingSeq"] = SmallInt::New(info.Env(), recording_seq);
  ret["extSrcSpec"] = SmallInt::New(info.Env(), ext_src_spec);
  ret["plug"] = SmallInt::New(info.Env(), plug);
  ret["physAddr"] = SmallInt::New(info.Env(), phys_addr);
  return ret;
}

Napi::Value MsgSetTimerProgramTitle(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  std::string prog_title = info[1].As<Napi::String>();
  cec_msg_set_timer_program_title(&msg, prog_title.c_str());
  return Msg::New(info.Env(), msg);
}

Napi::Value OpsSetTimerProgramTitle(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  char prog_title[CEC_MAX_MSG_SIZE] = {0};
  cec_ops_set_timer_program_title(&msg, prog_title);
  Napi::Value ret = Napi::String::New(info.Env(), prog_title);
  return ret;
}

Napi::Value MsgCecVersion(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  __u8 cec_version = info[1].As<SmallInt>();
  cec_msg_cec_version(&msg, cec_version);
  return Msg::New(info.Env(), msg);
}

Napi::Value OpsCecVersion(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  __u8 cec_version = 0;
  cec_ops_cec_version(&msg, &cec_version);
  Napi::Value ret = SmallInt::New(info.Env(), cec_version);
  return ret;
}

Napi::Value MsgGetCecVersion(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  int reply = info[1].As<Napi::Boolean>();
  cec_msg_get_cec_version(&msg, reply);
  return Msg::New(info.Env(), msg);
}

Napi::Value MsgReportPhysicalAddr(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  __u16 phys_addr = info[1].As<SmallInt>();
  __u8 prim_devtype = info[2].As<SmallInt>();
  cec_msg_report_physical_addr(&msg, phys_addr, prim_devtype);
  return Msg::New(info.Env(), msg);
}

Napi::Value OpsReportPhysicalAddr(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  __u16 phys_addr = 0;
  __u8 prim_devtype = 0;
  cec_ops_report_physical_addr(&msg, &phys_addr, &prim_devtype);
  Napi::Object ret = Napi::Object::New(info.Env());
  ret["physAddr"] = SmallInt::New(info.Env(), phys_addr);
  ret["primDevtype"] = SmallInt::New(info.Env(), prim_devtype);
  return ret;
}

Napi::Value MsgGivePhysicalAddr(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  int reply = info[1].As<Napi::Boolean>();
  cec_msg_give_physical_addr(&msg, reply);
  return Msg::New(info.Env(), msg);
}

Napi::Value MsgSetMenuLanguage(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  std::string language = info[1].As<Napi::String>();
  cec_msg_set_menu_language(&msg, language.c_str());
  return Msg::New(info.Env(), msg);
}

Napi::Value OpsSetMenuLanguage(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  char language[CEC_MAX_MSG_SIZE] = {0};
  cec_ops_set_menu_language(&msg, language);
  Napi::Value ret = Napi::String::New(info.Env(), language);
  return ret;
}

Napi::Value MsgGetMenuLanguage(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  int reply = info[1].As<Napi::Boolean>();
  cec_msg_get_menu_language(&msg, reply);
  return Msg::New(info.Env(), msg);
}

Napi::Value MsgReportFeatures(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  __u8 cec_version = info[1].As<SmallInt>();
  __u8 all_device_types = info[2].As<SmallInt>();
  __u8 rc_profile = info[3].As<SmallInt>();
  __u8 dev_features = info[4].As<SmallInt>();
  cec_msg_report_features(&msg, cec_version, all_device_types, rc_profile,
                          dev_features);
  return Msg::New(info.Env(), msg);
}

Napi::Value OpsReportFeatures(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  __u8 cec_version = 0;
  __u8 all_device_types = 0;
  const __u8* rc_profile = NULL;
  const __u8* dev_features = NULL;
  cec_ops_report_features(&msg, &cec_version, &all_device_types, &rc_profile,
                          &dev_features);
  Napi::Object ret = Napi::Object::New(info.Env());
  ret["cecVersion"] = SmallInt::New(info.Env(), cec_version);
  ret["allDeviceTypes"] = SmallInt::New(info.Env(), all_device_types);
  if (rc_profile == NULL) {
    ret["rcProfile"] = info.Env().Undefined();
  } else {
    Napi::Array rc_profile_arr = Napi::Array::New(info.Env());
    uint32_t rc_profile_len = (msg.msg + CEC_MAX_MSG_SIZE) - rc_profile;
    uint32_t rc_profile_i;
    for (rc_profile_i = 0; rc_profile_i < rc_profile_len; rc_profile_i++)
      rc_profile_arr[rc_profile_i] =
          SmallInt::New(info.Env(), rc_profile[rc_profile_i]);
    ret["rcProfile"] = rc_profile_arr;
  }
  if (dev_features == NULL) {
    ret["devFeatures"] = info.Env().Undefined();
  } else {
    Napi::Array dev_features_arr = Napi::Array::New(info.Env());
    uint32_t dev_features_len = (msg.msg + CEC_MAX_MSG_SIZE) - dev_features;
    uint32_t dev_features_i;
    for (dev_features_i = 0; dev_features_i < dev_features_len;
         dev_features_i++)
      dev_features_arr[dev_features_i] =
          SmallInt::New(info.Env(), dev_features[dev_features_i]);
    ret["devFeatures"] = dev_features_arr;
  }
  return ret;
}

Napi::Value MsgGiveFeatures(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  int reply = info[1].As<Napi::Boolean>();
  cec_msg_give_features(&msg, reply);
  return Msg::New(info.Env(), msg);
}

Napi::Value MsgDeckControl(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  __u8 deck_control_mode = info[1].As<SmallInt>();
  cec_msg_deck_control(&msg, deck_control_mode);
  return Msg::New(info.Env(), msg);
}

Napi::Value OpsDeckControl(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  __u8 deck_control_mode = 0;
  cec_ops_deck_control(&msg, &deck_control_mode);
  Napi::Value ret = SmallInt::New(info.Env(), deck_control_mode);
  return ret;
}

Napi::Value MsgDeckStatus(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  __u8 deck_info = info[1].As<SmallInt>();
  cec_msg_deck_status(&msg, deck_info);
  return Msg::New(info.Env(), msg);
}

Napi::Value OpsDeckStatus(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  __u8 deck_info = 0;
  cec_ops_deck_status(&msg, &deck_info);
  Napi::Value ret = SmallInt::New(info.Env(), deck_info);
  return ret;
}

Napi::Value MsgGiveDeckStatus(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  int reply = info[1].As<Napi::Boolean>();
  __u8 status_req = info[2].As<SmallInt>();
  cec_msg_give_deck_status(&msg, reply, status_req);
  return Msg::New(info.Env(), msg);
}

Napi::Value OpsGiveDeckStatus(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  __u8 status_req = 0;
  cec_ops_give_deck_status(&msg, &status_req);
  Napi::Value ret = SmallInt::New(info.Env(), status_req);
  return ret;
}

Napi::Value MsgPlay(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  __u8 play_mode = info[1].As<SmallInt>();
  cec_msg_play(&msg, play_mode);
  return Msg::New(info.Env(), msg);
}

Napi::Value OpsPlay(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  __u8 play_mode = 0;
  cec_ops_play(&msg, &play_mode);
  Napi::Value ret = SmallInt::New(info.Env(), play_mode);
  return ret;
}

Napi::Value MsgTunerDeviceStatusAnalog(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  __u8 rec_flag = info[1].As<SmallInt>();
  __u8 tuner_display_info = info[2].As<SmallInt>();
  __u8 ana_bcast_type = info[3].As<SmallInt>();
  __u16 ana_freq = info[4].As<SmallInt>();
  __u8 bcast_system = info[5].As<SmallInt>();
  cec_msg_tuner_device_status_analog(&msg, rec_flag, tuner_display_info,
                                     ana_bcast_type, ana_freq, bcast_system);
  return Msg::New(info.Env(), msg);
}

Napi::Value MsgTunerDeviceStatusDigital(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  __u8 rec_flag = info[1].As<SmallInt>();
  __u8 tuner_display_info = info[2].As<SmallInt>();
  cec_op_digital_service_id digital = info[3].As<OpDigitalServiceId>();
  cec_msg_tuner_device_status_digital(&msg, rec_flag, tuner_display_info,
                                      &digital);
  return Msg::New(info.Env(), msg);
}

Napi::Value MsgTunerDeviceStatus(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  cec_op_tuner_device_info tuner_dev_info = info[1].As<OpTunerDeviceInfo>();
  cec_msg_tuner_device_status(&msg, &tuner_dev_info);
  return Msg::New(info.Env(), msg);
}

Napi::Value OpsTunerDeviceStatus(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  cec_op_tuner_device_info tuner_dev_info = {};
  cec_ops_tuner_device_status(&msg, &tuner_dev_info);
  Napi::Value ret = OpTunerDeviceInfo::New(info.Env(), tuner_dev_info);
  return ret;
}

Napi::Value MsgGiveTunerDeviceStatus(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  int reply = info[1].As<Napi::Boolean>();
  __u8 status_req = info[2].As<SmallInt>();
  cec_msg_give_tuner_device_status(&msg, reply, status_req);
  return Msg::New(info.Env(), msg);
}

Napi::Value OpsGiveTunerDeviceStatus(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  __u8 status_req = 0;
  cec_ops_give_tuner_device_status(&msg, &status_req);
  Napi::Value ret = SmallInt::New(info.Env(), status_req);
  return ret;
}

Napi::Value MsgSelectAnalogueService(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  __u8 ana_bcast_type = info[1].As<SmallInt>();
  __u16 ana_freq = info[2].As<SmallInt>();
  __u8 bcast_system = info[3].As<SmallInt>();
  cec_msg_select_analogue_service(&msg, ana_bcast_type, ana_freq, bcast_system);
  return Msg::New(info.Env(), msg);
}

Napi::Value OpsSelectAnalogueService(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  __u8 ana_bcast_type = 0;
  __u16 ana_freq = 0;
  __u8 bcast_system = 0;
  cec_ops_select_analogue_service(&msg, &ana_bcast_type, &ana_freq,
                                  &bcast_system);
  Napi::Object ret = Napi::Object::New(info.Env());
  ret["anaBcastType"] = SmallInt::New(info.Env(), ana_bcast_type);
  ret["anaFreq"] = SmallInt::New(info.Env(), ana_freq);
  ret["bcastSystem"] = SmallInt::New(info.Env(), bcast_system);
  return ret;
}

Napi::Value MsgSelectDigitalService(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  cec_op_digital_service_id digital = info[1].As<OpDigitalServiceId>();
  cec_msg_select_digital_service(&msg, &digital);
  return Msg::New(info.Env(), msg);
}

Napi::Value OpsSelectDigitalService(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  cec_op_digital_service_id digital = {};
  cec_ops_select_digital_service(&msg, &digital);
  Napi::Value ret = OpDigitalServiceId::New(info.Env(), digital);
  return ret;
}

Napi::Value MsgTunerStepDecrement(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  cec_msg_tuner_step_decrement(&msg);
  return Msg::New(info.Env(), msg);
}

Napi::Value MsgTunerStepIncrement(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  cec_msg_tuner_step_increment(&msg);
  return Msg::New(info.Env(), msg);
}

Napi::Value MsgDeviceVendorId(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  __u32 vendor_id = info[1].As<Napi::Number>();
  cec_msg_device_vendor_id(&msg, vendor_id);
  return Msg::New(info.Env(), msg);
}

Napi::Value OpsDeviceVendorId(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  __u32 vendor_id = 0;
  cec_ops_device_vendor_id(&msg, &vendor_id);
  Napi::Value ret = Napi::Number::New(info.Env(), vendor_id);
  return ret;
}

Napi::Value MsgGiveDeviceVendorId(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  int reply = info[1].As<Napi::Boolean>();
  cec_msg_give_device_vendor_id(&msg, reply);
  return Msg::New(info.Env(), msg);
}

Napi::Value MsgVendorCommand(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  __u8 size = info[1].As<SmallInt>();
  Napi::Array vendor_cmd_arr = info[2].As<Napi::Array>();
  uint32_t vendor_cmd_len = vendor_cmd_arr.Length();
  uint32_t vendor_cmd_i;
  __u8 vendor_cmd[vendor_cmd_len] = {0};
  for (vendor_cmd_i = 0; vendor_cmd_i < vendor_cmd_len; vendor_cmd_i++)
    vendor_cmd[vendor_cmd_i] = vendor_cmd_arr.Get(vendor_cmd_i).As<SmallInt>();
  cec_msg_vendor_command(&msg, size, vendor_cmd);
  return Msg::New(info.Env(), msg);
}

Napi::Value OpsVendorCommand(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  __u8 size = 0;
  const __u8* vendor_cmd = NULL;
  cec_ops_vendor_command(&msg, &size, &vendor_cmd);
  Napi::Object ret = Napi::Object::New(info.Env());
  ret["size"] = SmallInt::New(info.Env(), size);
  if (vendor_cmd == NULL) {
    ret["vendorCmd"] = info.Env().Undefined();
  } else {
    Napi::Array vendor_cmd_arr = Napi::Array::New(info.Env());
    uint32_t vendor_cmd_len = (msg.msg + CEC_MAX_MSG_SIZE) - vendor_cmd;
    uint32_t vendor_cmd_i;
    for (vendor_cmd_i = 0; vendor_cmd_i < vendor_cmd_len; vendor_cmd_i++)
      vendor_cmd_arr[vendor_cmd_i] =
          SmallInt::New(info.Env(), vendor_cmd[vendor_cmd_i]);
    ret["vendorCmd"] = vendor_cmd_arr;
  }
  return ret;
}

Napi::Value MsgVendorCommandWithId(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  __u32 vendor_id = info[1].As<Napi::Number>();
  __u8 size = info[2].As<SmallInt>();
  Napi::Array vendor_cmd_arr = info[3].As<Napi::Array>();
  uint32_t vendor_cmd_len = vendor_cmd_arr.Length();
  uint32_t vendor_cmd_i;
  __u8 vendor_cmd[vendor_cmd_len] = {0};
  for (vendor_cmd_i = 0; vendor_cmd_i < vendor_cmd_len; vendor_cmd_i++)
    vendor_cmd[vendor_cmd_i] = vendor_cmd_arr.Get(vendor_cmd_i).As<SmallInt>();
  cec_msg_vendor_command_with_id(&msg, vendor_id, size, vendor_cmd);
  return Msg::New(info.Env(), msg);
}

Napi::Value OpsVendorCommandWithId(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  __u32 vendor_id = 0;
  __u8 size = 0;
  const __u8* vendor_cmd = NULL;
  cec_ops_vendor_command_with_id(&msg, &vendor_id, &size, &vendor_cmd);
  Napi::Object ret = Napi::Object::New(info.Env());
  ret["vendorId"] = Napi::Number::New(info.Env(), vendor_id);
  ret["size"] = SmallInt::New(info.Env(), size);
  if (vendor_cmd == NULL) {
    ret["vendorCmd"] = info.Env().Undefined();
  } else {
    Napi::Array vendor_cmd_arr = Napi::Array::New(info.Env());
    uint32_t vendor_cmd_len = (msg.msg + CEC_MAX_MSG_SIZE) - vendor_cmd;
    uint32_t vendor_cmd_i;
    for (vendor_cmd_i = 0; vendor_cmd_i < vendor_cmd_len; vendor_cmd_i++)
      vendor_cmd_arr[vendor_cmd_i] =
          SmallInt::New(info.Env(), vendor_cmd[vendor_cmd_i]);
    ret["vendorCmd"] = vendor_cmd_arr;
  }
  return ret;
}

Napi::Value MsgVendorRemoteButtonDown(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  __u8 size = info[1].As<SmallInt>();
  Napi::Array rc_code_arr = info[2].As<Napi::Array>();
  uint32_t rc_code_len = rc_code_arr.Length();
  uint32_t rc_code_i;
  __u8 rc_code[rc_code_len] = {0};
  for (rc_code_i = 0; rc_code_i < rc_code_len; rc_code_i++)
    rc_code[rc_code_i] = rc_code_arr.Get(rc_code_i).As<SmallInt>();
  cec_msg_vendor_remote_button_down(&msg, size, rc_code);
  return Msg::New(info.Env(), msg);
}

Napi::Value OpsVendorRemoteButtonDown(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  __u8 size = 0;
  const __u8* rc_code = NULL;
  cec_ops_vendor_remote_button_down(&msg, &size, &rc_code);
  Napi::Object ret = Napi::Object::New(info.Env());
  ret["size"] = SmallInt::New(info.Env(), size);
  if (rc_code == NULL) {
    ret["rcCode"] = info.Env().Undefined();
  } else {
    Napi::Array rc_code_arr = Napi::Array::New(info.Env());
    uint32_t rc_code_len = (msg.msg + CEC_MAX_MSG_SIZE) - rc_code;
    uint32_t rc_code_i;
    for (rc_code_i = 0; rc_code_i < rc_code_len; rc_code_i++)
      rc_code_arr[rc_code_i] = SmallInt::New(info.Env(), rc_code[rc_code_i]);
    ret["rcCode"] = rc_code_arr;
  }
  return ret;
}

Napi::Value MsgVendorRemoteButtonUp(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  cec_msg_vendor_remote_button_up(&msg);
  return Msg::New(info.Env(), msg);
}

Napi::Value MsgSetOsdString(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  __u8 disp_ctl = info[1].As<SmallInt>();
  std::string osd = info[2].As<Napi::String>();
  cec_msg_set_osd_string(&msg, disp_ctl, osd.c_str());
  return Msg::New(info.Env(), msg);
}

Napi::Value OpsSetOsdString(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  __u8 disp_ctl = 0;
  char osd[CEC_MAX_MSG_SIZE] = {0};
  cec_ops_set_osd_string(&msg, &disp_ctl, osd);
  Napi::Object ret = Napi::Object::New(info.Env());
  ret["dispCtl"] = SmallInt::New(info.Env(), disp_ctl);
  ret["osd"] = Napi::String::New(info.Env(), osd);
  return ret;
}

Napi::Value MsgSetOsdName(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  std::string name = info[1].As<Napi::String>();
  cec_msg_set_osd_name(&msg, name.c_str());
  return Msg::New(info.Env(), msg);
}

Napi::Value OpsSetOsdName(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  char name[CEC_MAX_MSG_SIZE] = {0};
  cec_ops_set_osd_name(&msg, name);
  Napi::Value ret = Napi::String::New(info.Env(), name);
  return ret;
}

Napi::Value MsgGiveOsdName(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  int reply = info[1].As<Napi::Boolean>();
  cec_msg_give_osd_name(&msg, reply);
  return Msg::New(info.Env(), msg);
}

Napi::Value MsgMenuStatus(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  __u8 menu_state = info[1].As<SmallInt>();
  cec_msg_menu_status(&msg, menu_state);
  return Msg::New(info.Env(), msg);
}

Napi::Value OpsMenuStatus(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  __u8 menu_state = 0;
  cec_ops_menu_status(&msg, &menu_state);
  Napi::Value ret = SmallInt::New(info.Env(), menu_state);
  return ret;
}

Napi::Value MsgMenuRequest(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  int reply = info[1].As<Napi::Boolean>();
  __u8 menu_req = info[2].As<SmallInt>();
  cec_msg_menu_request(&msg, reply, menu_req);
  return Msg::New(info.Env(), msg);
}

Napi::Value OpsMenuRequest(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  __u8 menu_req = 0;
  cec_ops_menu_request(&msg, &menu_req);
  Napi::Value ret = SmallInt::New(info.Env(), menu_req);
  return ret;
}

Napi::Value MsgUserControlPressed(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  cec_op_ui_command ui_cmd = info[1].As<OpUiCommand>();
  cec_msg_user_control_pressed(&msg, &ui_cmd);
  return Msg::New(info.Env(), msg);
}

Napi::Value OpsUserControlPressed(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  cec_op_ui_command ui_cmd = {};
  cec_ops_user_control_pressed(&msg, &ui_cmd);
  Napi::Value ret = OpUiCommand::New(info.Env(), ui_cmd);
  return ret;
}

Napi::Value MsgUserControlReleased(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  cec_msg_user_control_released(&msg);
  return Msg::New(info.Env(), msg);
}

Napi::Value MsgReportPowerStatus(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  __u8 pwr_state = info[1].As<SmallInt>();
  cec_msg_report_power_status(&msg, pwr_state);
  return Msg::New(info.Env(), msg);
}

Napi::Value OpsReportPowerStatus(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  __u8 pwr_state = 0;
  cec_ops_report_power_status(&msg, &pwr_state);
  Napi::Value ret = SmallInt::New(info.Env(), pwr_state);
  return ret;
}

Napi::Value MsgGiveDevicePowerStatus(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  int reply = info[1].As<Napi::Boolean>();
  cec_msg_give_device_power_status(&msg, reply);
  return Msg::New(info.Env(), msg);
}

Napi::Value MsgFeatureAbort(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  __u8 abort_msg = info[1].As<SmallInt>();
  __u8 reason = info[2].As<SmallInt>();
  cec_msg_feature_abort(&msg, abort_msg, reason);
  return Msg::New(info.Env(), msg);
}

Napi::Value OpsFeatureAbort(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  __u8 abort_msg = 0;
  __u8 reason = 0;
  cec_ops_feature_abort(&msg, &abort_msg, &reason);
  Napi::Object ret = Napi::Object::New(info.Env());
  ret["abortMsg"] = SmallInt::New(info.Env(), abort_msg);
  ret["reason"] = SmallInt::New(info.Env(), reason);
  return ret;
}

Napi::Value MsgReplyFeatureAbort(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  __u8 reason = info[1].As<SmallInt>();
  cec_msg_reply_feature_abort(&msg, reason);
  return Msg::New(info.Env(), msg);
}

Napi::Value MsgAbort(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  cec_msg_abort(&msg);
  return Msg::New(info.Env(), msg);
}

Napi::Value MsgReportAudioStatus(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  __u8 aud_mute_status = info[1].As<SmallInt>();
  __u8 aud_vol_status = info[2].As<SmallInt>();
  cec_msg_report_audio_status(&msg, aud_mute_status, aud_vol_status);
  return Msg::New(info.Env(), msg);
}

Napi::Value OpsReportAudioStatus(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  __u8 aud_mute_status = 0;
  __u8 aud_vol_status = 0;
  cec_ops_report_audio_status(&msg, &aud_mute_status, &aud_vol_status);
  Napi::Object ret = Napi::Object::New(info.Env());
  ret["audMuteStatus"] = SmallInt::New(info.Env(), aud_mute_status);
  ret["audVolStatus"] = SmallInt::New(info.Env(), aud_vol_status);
  return ret;
}

Napi::Value MsgGiveAudioStatus(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  int reply = info[1].As<Napi::Boolean>();
  cec_msg_give_audio_status(&msg, reply);
  return Msg::New(info.Env(), msg);
}

Napi::Value MsgSetSystemAudioMode(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  __u8 sys_aud_status = info[1].As<SmallInt>();
  cec_msg_set_system_audio_mode(&msg, sys_aud_status);
  return Msg::New(info.Env(), msg);
}

Napi::Value OpsSetSystemAudioMode(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  __u8 sys_aud_status = 0;
  cec_ops_set_system_audio_mode(&msg, &sys_aud_status);
  Napi::Value ret = SmallInt::New(info.Env(), sys_aud_status);
  return ret;
}

Napi::Value MsgSystemAudioModeRequest(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  int reply = info[1].As<Napi::Boolean>();
  __u16 phys_addr = info[2].As<SmallInt>();
  cec_msg_system_audio_mode_request(&msg, reply, phys_addr);
  return Msg::New(info.Env(), msg);
}

Napi::Value OpsSystemAudioModeRequest(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  __u16 phys_addr = 0;
  cec_ops_system_audio_mode_request(&msg, &phys_addr);
  Napi::Value ret = SmallInt::New(info.Env(), phys_addr);
  return ret;
}

Napi::Value MsgSystemAudioModeStatus(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  __u8 sys_aud_status = info[1].As<SmallInt>();
  cec_msg_system_audio_mode_status(&msg, sys_aud_status);
  return Msg::New(info.Env(), msg);
}

Napi::Value OpsSystemAudioModeStatus(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  __u8 sys_aud_status = 0;
  cec_ops_system_audio_mode_status(&msg, &sys_aud_status);
  Napi::Value ret = SmallInt::New(info.Env(), sys_aud_status);
  return ret;
}

Napi::Value MsgGiveSystemAudioModeStatus(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  int reply = info[1].As<Napi::Boolean>();
  cec_msg_give_system_audio_mode_status(&msg, reply);
  return Msg::New(info.Env(), msg);
}

Napi::Value MsgReportShortAudioDescriptor(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  __u8 num_descriptors = info[1].As<SmallInt>();
  Napi::Array descriptors_arr = info[2].As<Napi::Array>();
  uint32_t descriptors_len = descriptors_arr.Length();
  uint32_t descriptors_i;
  __u32 descriptors[descriptors_len] = {0};
  for (descriptors_i = 0; descriptors_i < descriptors_len; descriptors_i++)
    descriptors[descriptors_i] =
        descriptors_arr.Get(descriptors_i).As<Napi::Number>();
  cec_msg_report_short_audio_descriptor(&msg, num_descriptors, descriptors);
  return Msg::New(info.Env(), msg);
}

Napi::Value OpsReportShortAudioDescriptor(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  __u8 num_descriptors = 0;
  __u32 descriptors = 0;
  cec_ops_report_short_audio_descriptor(&msg, &num_descriptors, &descriptors);
  Napi::Object ret = Napi::Object::New(info.Env());
  ret["numDescriptors"] = SmallInt::New(info.Env(), num_descriptors);
  ret["descriptors"] = Napi::Number::New(info.Env(), descriptors);
  return ret;
}

Napi::Value MsgRequestShortAudioDescriptor(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  int reply = info[1].As<Napi::Boolean>();
  __u8 num_descriptors = info[2].As<SmallInt>();
  Napi::Array audio_format_id_arr = info[3].As<Napi::Array>();
  uint32_t audio_format_id_len = audio_format_id_arr.Length();
  uint32_t audio_format_id_i;
  __u8 audio_format_id[audio_format_id_len] = {0};
  for (audio_format_id_i = 0; audio_format_id_i < audio_format_id_len;
       audio_format_id_i++)
    audio_format_id[audio_format_id_i] =
        audio_format_id_arr.Get(audio_format_id_i).As<SmallInt>();
  Napi::Array audio_format_code_arr = info[4].As<Napi::Array>();
  uint32_t audio_format_code_len = audio_format_code_arr.Length();
  uint32_t audio_format_code_i;
  __u8 audio_format_code[audio_format_code_len] = {0};
  for (audio_format_code_i = 0; audio_format_code_i < audio_format_code_len;
       audio_format_code_i++)
    audio_format_code[audio_format_code_i] =
        audio_format_code_arr.Get(audio_format_code_i).As<SmallInt>();
  cec_msg_request_short_audio_descriptor(&msg, reply, num_descriptors,
                                         audio_format_id, audio_format_code);
  return Msg::New(info.Env(), msg);
}

Napi::Value OpsRequestShortAudioDescriptor(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  __u8 num_descriptors = 0;
  __u8 audio_format_id = 0;
  __u8 audio_format_code = 0;
  cec_ops_request_short_audio_descriptor(&msg, &num_descriptors,
                                         &audio_format_id, &audio_format_code);
  Napi::Object ret = Napi::Object::New(info.Env());
  ret["numDescriptors"] = SmallInt::New(info.Env(), num_descriptors);
  ret["audioFormatId"] = SmallInt::New(info.Env(), audio_format_id);
  ret["audioFormatCode"] = SmallInt::New(info.Env(), audio_format_code);
  return ret;
}

Napi::Value MsgSetAudioRate(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  __u8 audio_rate = info[1].As<SmallInt>();
  cec_msg_set_audio_rate(&msg, audio_rate);
  return Msg::New(info.Env(), msg);
}

Napi::Value OpsSetAudioRate(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  __u8 audio_rate = 0;
  cec_ops_set_audio_rate(&msg, &audio_rate);
  Napi::Value ret = SmallInt::New(info.Env(), audio_rate);
  return ret;
}

Napi::Value MsgReportArcInitiated(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  cec_msg_report_arc_initiated(&msg);
  return Msg::New(info.Env(), msg);
}

Napi::Value MsgInitiateArc(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  int reply = info[1].As<Napi::Boolean>();
  cec_msg_initiate_arc(&msg, reply);
  return Msg::New(info.Env(), msg);
}

Napi::Value MsgRequestArcInitiation(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  int reply = info[1].As<Napi::Boolean>();
  cec_msg_request_arc_initiation(&msg, reply);
  return Msg::New(info.Env(), msg);
}

Napi::Value MsgReportArcTerminated(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  cec_msg_report_arc_terminated(&msg);
  return Msg::New(info.Env(), msg);
}

Napi::Value MsgTerminateArc(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  int reply = info[1].As<Napi::Boolean>();
  cec_msg_terminate_arc(&msg, reply);
  return Msg::New(info.Env(), msg);
}

Napi::Value MsgRequestArcTermination(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  int reply = info[1].As<Napi::Boolean>();
  cec_msg_request_arc_termination(&msg, reply);
  return Msg::New(info.Env(), msg);
}

Napi::Value MsgReportCurrentLatency(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  __u16 phys_addr = info[1].As<SmallInt>();
  __u8 video_latency = info[2].As<SmallInt>();
  __u8 low_latency_mode = info[3].As<SmallInt>();
  __u8 audio_out_compensated = info[4].As<SmallInt>();
  __u8 audio_out_delay = info[5].As<SmallInt>();
  cec_msg_report_current_latency(&msg, phys_addr, video_latency,
                                 low_latency_mode, audio_out_compensated,
                                 audio_out_delay);
  return Msg::New(info.Env(), msg);
}

Napi::Value OpsReportCurrentLatency(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  __u16 phys_addr = 0;
  __u8 video_latency = 0;
  __u8 low_latency_mode = 0;
  __u8 audio_out_compensated = 0;
  __u8 audio_out_delay = 0;
  cec_ops_report_current_latency(&msg, &phys_addr, &video_latency,
                                 &low_latency_mode, &audio_out_compensated,
                                 &audio_out_delay);
  Napi::Object ret = Napi::Object::New(info.Env());
  ret["physAddr"] = SmallInt::New(info.Env(), phys_addr);
  ret["videoLatency"] = SmallInt::New(info.Env(), video_latency);
  ret["lowLatencyMode"] = SmallInt::New(info.Env(), low_latency_mode);
  ret["audioOutCompensated"] = SmallInt::New(info.Env(), audio_out_compensated);
  ret["audioOutDelay"] = SmallInt::New(info.Env(), audio_out_delay);
  return ret;
}

Napi::Value MsgRequestCurrentLatency(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  int reply = info[1].As<Napi::Boolean>();
  __u16 phys_addr = info[2].As<SmallInt>();
  cec_msg_request_current_latency(&msg, reply, phys_addr);
  return Msg::New(info.Env(), msg);
}

Napi::Value OpsRequestCurrentLatency(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  __u16 phys_addr = 0;
  cec_ops_request_current_latency(&msg, &phys_addr);
  Napi::Value ret = SmallInt::New(info.Env(), phys_addr);
  return ret;
}

Napi::Value MsgCdcHecInquireState(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  __u16 phys_addr1 = info[1].As<SmallInt>();
  __u16 phys_addr2 = info[2].As<SmallInt>();
  cec_msg_cdc_hec_inquire_state(&msg, phys_addr1, phys_addr2);
  return Msg::New(info.Env(), msg);
}

Napi::Value OpsCdcHecInquireState(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  __u16 phys_addr = 0;
  __u16 phys_addr1 = 0;
  __u16 phys_addr2 = 0;
  cec_ops_cdc_hec_inquire_state(&msg, &phys_addr, &phys_addr1, &phys_addr2);
  Napi::Object ret = Napi::Object::New(info.Env());
  ret["physAddr"] = SmallInt::New(info.Env(), phys_addr);
  ret["physAddr1"] = SmallInt::New(info.Env(), phys_addr1);
  ret["physAddr2"] = SmallInt::New(info.Env(), phys_addr2);
  return ret;
}

Napi::Value MsgCdcHecReportState(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  __u16 target_phys_addr = info[1].As<SmallInt>();
  __u8 hec_func_state = info[2].As<SmallInt>();
  __u8 host_func_state = info[3].As<SmallInt>();
  __u8 enc_func_state = info[4].As<SmallInt>();
  __u8 cdc_errcode = info[5].As<SmallInt>();
  __u8 has_field = info[6].As<Napi::Boolean>();
  __u16 hec_field = info[7].As<SmallInt>();
  cec_msg_cdc_hec_report_state(&msg, target_phys_addr, hec_func_state,
                               host_func_state, enc_func_state, cdc_errcode,
                               has_field, hec_field);
  return Msg::New(info.Env(), msg);
}

Napi::Value OpsCdcHecReportState(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  __u16 phys_addr = 0;
  __u16 target_phys_addr = 0;
  __u8 hec_func_state = 0;
  __u8 host_func_state = 0;
  __u8 enc_func_state = 0;
  __u8 cdc_errcode = 0;
  __u8 has_field = 0;
  __u16 hec_field = 0;
  cec_ops_cdc_hec_report_state(
      &msg, &phys_addr, &target_phys_addr, &hec_func_state, &host_func_state,
      &enc_func_state, &cdc_errcode, &has_field, &hec_field);
  Napi::Object ret = Napi::Object::New(info.Env());
  ret["physAddr"] = SmallInt::New(info.Env(), phys_addr);
  ret["targetPhysAddr"] = SmallInt::New(info.Env(), target_phys_addr);
  ret["hecFuncState"] = SmallInt::New(info.Env(), hec_func_state);
  ret["hostFuncState"] = SmallInt::New(info.Env(), host_func_state);
  ret["encFuncState"] = SmallInt::New(info.Env(), enc_func_state);
  ret["cdcErrcode"] = SmallInt::New(info.Env(), cdc_errcode);
  ret["hasField"] = Napi::Boolean::New(info.Env(), has_field);
  ret["hecField"] = SmallInt::New(info.Env(), hec_field);
  return ret;
}

Napi::Value MsgCdcHecSetState(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  __u16 phys_addr1 = info[1].As<SmallInt>();
  __u16 phys_addr2 = info[2].As<SmallInt>();
  __u8 hec_set_state = info[3].As<SmallInt>();
  __u16 phys_addr3 = info[4].As<SmallInt>();
  __u16 phys_addr4 = info[5].As<SmallInt>();
  __u16 phys_addr5 = info[6].As<SmallInt>();
  cec_msg_cdc_hec_set_state(&msg, phys_addr1, phys_addr2, hec_set_state,
                            phys_addr3, phys_addr4, phys_addr5);
  return Msg::New(info.Env(), msg);
}

Napi::Value OpsCdcHecSetState(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  __u16 phys_addr = 0;
  __u16 phys_addr1 = 0;
  __u16 phys_addr2 = 0;
  __u8 hec_set_state = 0;
  __u16 phys_addr3 = 0;
  __u16 phys_addr4 = 0;
  __u16 phys_addr5 = 0;
  cec_ops_cdc_hec_set_state(&msg, &phys_addr, &phys_addr1, &phys_addr2,
                            &hec_set_state, &phys_addr3, &phys_addr4,
                            &phys_addr5);
  Napi::Object ret = Napi::Object::New(info.Env());
  ret["physAddr"] = SmallInt::New(info.Env(), phys_addr);
  ret["physAddr1"] = SmallInt::New(info.Env(), phys_addr1);
  ret["physAddr2"] = SmallInt::New(info.Env(), phys_addr2);
  ret["hecSetState"] = SmallInt::New(info.Env(), hec_set_state);
  ret["physAddr3"] = SmallInt::New(info.Env(), phys_addr3);
  ret["physAddr4"] = SmallInt::New(info.Env(), phys_addr4);
  ret["physAddr5"] = SmallInt::New(info.Env(), phys_addr5);
  return ret;
}

Napi::Value MsgCdcHecSetStateAdjacent(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  __u16 phys_addr1 = info[1].As<SmallInt>();
  __u8 hec_set_state = info[2].As<SmallInt>();
  cec_msg_cdc_hec_set_state_adjacent(&msg, phys_addr1, hec_set_state);
  return Msg::New(info.Env(), msg);
}

Napi::Value OpsCdcHecSetStateAdjacent(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  __u16 phys_addr = 0;
  __u16 phys_addr1 = 0;
  __u8 hec_set_state = 0;
  cec_ops_cdc_hec_set_state_adjacent(&msg, &phys_addr, &phys_addr1,
                                     &hec_set_state);
  Napi::Object ret = Napi::Object::New(info.Env());
  ret["physAddr"] = SmallInt::New(info.Env(), phys_addr);
  ret["physAddr1"] = SmallInt::New(info.Env(), phys_addr1);
  ret["hecSetState"] = SmallInt::New(info.Env(), hec_set_state);
  return ret;
}

Napi::Value MsgCdcHecRequestDeactivation(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  __u16 phys_addr1 = info[1].As<SmallInt>();
  __u16 phys_addr2 = info[2].As<SmallInt>();
  __u16 phys_addr3 = info[3].As<SmallInt>();
  cec_msg_cdc_hec_request_deactivation(&msg, phys_addr1, phys_addr2,
                                       phys_addr3);
  return Msg::New(info.Env(), msg);
}

Napi::Value OpsCdcHecRequestDeactivation(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  __u16 phys_addr = 0;
  __u16 phys_addr1 = 0;
  __u16 phys_addr2 = 0;
  __u16 phys_addr3 = 0;
  cec_ops_cdc_hec_request_deactivation(&msg, &phys_addr, &phys_addr1,
                                       &phys_addr2, &phys_addr3);
  Napi::Object ret = Napi::Object::New(info.Env());
  ret["physAddr"] = SmallInt::New(info.Env(), phys_addr);
  ret["physAddr1"] = SmallInt::New(info.Env(), phys_addr1);
  ret["physAddr2"] = SmallInt::New(info.Env(), phys_addr2);
  ret["physAddr3"] = SmallInt::New(info.Env(), phys_addr3);
  return ret;
}

Napi::Value MsgCdcHecNotifyAlive(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  cec_msg_cdc_hec_notify_alive(&msg);
  return Msg::New(info.Env(), msg);
}

Napi::Value OpsCdcHecNotifyAlive(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  __u16 phys_addr = 0;
  cec_ops_cdc_hec_notify_alive(&msg, &phys_addr);
  Napi::Value ret = SmallInt::New(info.Env(), phys_addr);
  return ret;
}

Napi::Value MsgCdcHecDiscover(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  cec_msg_cdc_hec_discover(&msg);
  return Msg::New(info.Env(), msg);
}

Napi::Value OpsCdcHecDiscover(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  __u16 phys_addr = 0;
  cec_ops_cdc_hec_discover(&msg, &phys_addr);
  Napi::Value ret = SmallInt::New(info.Env(), phys_addr);
  return ret;
}

Napi::Value MsgCdcHpdSetState(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  __u8 input_port = info[1].As<SmallInt>();
  __u8 hpd_state = info[2].As<SmallInt>();
  cec_msg_cdc_hpd_set_state(&msg, input_port, hpd_state);
  return Msg::New(info.Env(), msg);
}

Napi::Value OpsCdcHpdSetState(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  __u16 phys_addr = 0;
  __u8 input_port = 0;
  __u8 hpd_state = 0;
  cec_ops_cdc_hpd_set_state(&msg, &phys_addr, &input_port, &hpd_state);
  Napi::Object ret = Napi::Object::New(info.Env());
  ret["physAddr"] = SmallInt::New(info.Env(), phys_addr);
  ret["inputPort"] = SmallInt::New(info.Env(), input_port);
  ret["hpdState"] = SmallInt::New(info.Env(), hpd_state);
  return ret;
}

Napi::Value MsgCdcHpdReportState(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  __u8 hpd_state = info[1].As<SmallInt>();
  __u8 hpd_error = info[2].As<SmallInt>();
  cec_msg_cdc_hpd_report_state(&msg, hpd_state, hpd_error);
  return Msg::New(info.Env(), msg);
}

Napi::Value OpsCdcHpdReportState(const Napi::CallbackInfo& info) {
  cec_msg msg = info[0].As<Msg>();
  __u16 phys_addr = 0;
  __u8 hpd_state = 0;
  __u8 hpd_error = 0;
  cec_ops_cdc_hpd_report_state(&msg, &phys_addr, &hpd_state, &hpd_error);
  Napi::Object ret = Napi::Object::New(info.Env());
  ret["physAddr"] = SmallInt::New(info.Env(), phys_addr);
  ret["hpdState"] = SmallInt::New(info.Env(), hpd_state);
  ret["hpdError"] = SmallInt::New(info.Env(), hpd_error);
  return ret;
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  Napi::Object cec = Napi::Object::New(env);

  cec.Set(Napi::String::New(env, "msgInitiator"),
          Napi::Function::New(env, MsgInitiator));
  cec.Set(Napi::String::New(env, "msgDestination"),
          Napi::Function::New(env, MsgDestination));
  cec.Set(Napi::String::New(env, "msgOpcode"),
          Napi::Function::New(env, MsgOpcode));
  cec.Set(Napi::String::New(env, "msgIsBroadcast"),
          Napi::Function::New(env, MsgIsBroadcast));
  cec.Set(Napi::String::New(env, "msgInit"), Napi::Function::New(env, MsgInit));
  cec.Set(Napi::String::New(env, "msgSetReplyTo"),
          Napi::Function::New(env, MsgSetReplyTo));
  cec.Set(Napi::String::New(env, "msgStatusIsOk"),
          Napi::Function::New(env, MsgStatusIsOk));
  cec.Set(Napi::String::New(env, "hasTv"), Napi::Function::New(env, HasTv));
  cec.Set(Napi::String::New(env, "hasRecord"),
          Napi::Function::New(env, HasRecord));
  cec.Set(Napi::String::New(env, "hasTuner"),
          Napi::Function::New(env, HasTuner));
  cec.Set(Napi::String::New(env, "hasPlayback"),
          Napi::Function::New(env, HasPlayback));
  cec.Set(Napi::String::New(env, "hasAudiosystem"),
          Napi::Function::New(env, HasAudiosystem));
  cec.Set(Napi::String::New(env, "hasBackup"),
          Napi::Function::New(env, HasBackup));
  cec.Set(Napi::String::New(env, "hasSpecific"),
          Napi::Function::New(env, HasSpecific));
  cec.Set(Napi::String::New(env, "isUnregistered"),
          Napi::Function::New(env, IsUnregistered));
  cec.Set(Napi::String::New(env, "isUnconfigured"),
          Napi::Function::New(env, IsUnconfigured));
  cec.Set(Napi::String::New(env, "is2ndTv"), Napi::Function::New(env, Is2ndTv));
  cec.Set(Napi::String::New(env, "isProcessor"),
          Napi::Function::New(env, IsProcessor));
  cec.Set(Napi::String::New(env, "isSwitch"),
          Napi::Function::New(env, IsSwitch));
  cec.Set(Napi::String::New(env, "isCdcOnly"),
          Napi::Function::New(env, IsCdcOnly));
  cec.Set(Napi::String::New(env, "msgActiveSource"),
          Napi::Function::New(env, MsgActiveSource));
  cec.Set(Napi::String::New(env, "opsActiveSource"),
          Napi::Function::New(env, OpsActiveSource));
  cec.Set(Napi::String::New(env, "msgImageViewOn"),
          Napi::Function::New(env, MsgImageViewOn));
  cec.Set(Napi::String::New(env, "msgTextViewOn"),
          Napi::Function::New(env, MsgTextViewOn));
  cec.Set(Napi::String::New(env, "msgInactiveSource"),
          Napi::Function::New(env, MsgInactiveSource));
  cec.Set(Napi::String::New(env, "opsInactiveSource"),
          Napi::Function::New(env, OpsInactiveSource));
  cec.Set(Napi::String::New(env, "msgRequestActiveSource"),
          Napi::Function::New(env, MsgRequestActiveSource));
  cec.Set(Napi::String::New(env, "msgRoutingInformation"),
          Napi::Function::New(env, MsgRoutingInformation));
  cec.Set(Napi::String::New(env, "opsRoutingInformation"),
          Napi::Function::New(env, OpsRoutingInformation));
  cec.Set(Napi::String::New(env, "msgRoutingChange"),
          Napi::Function::New(env, MsgRoutingChange));
  cec.Set(Napi::String::New(env, "opsRoutingChange"),
          Napi::Function::New(env, OpsRoutingChange));
  cec.Set(Napi::String::New(env, "msgSetStreamPath"),
          Napi::Function::New(env, MsgSetStreamPath));
  cec.Set(Napi::String::New(env, "opsSetStreamPath"),
          Napi::Function::New(env, OpsSetStreamPath));
  cec.Set(Napi::String::New(env, "msgStandby"),
          Napi::Function::New(env, MsgStandby));
  cec.Set(Napi::String::New(env, "msgRecordOff"),
          Napi::Function::New(env, MsgRecordOff));
  cec.Set(Napi::String::New(env, "setDigitalServiceId"),
          Napi::Function::New(env, SetDigitalServiceId));
  cec.Set(Napi::String::New(env, "getDigitalServiceId"),
          Napi::Function::New(env, GetDigitalServiceId));
  cec.Set(Napi::String::New(env, "msgRecordOnOwn"),
          Napi::Function::New(env, MsgRecordOnOwn));
  cec.Set(Napi::String::New(env, "msgRecordOnDigital"),
          Napi::Function::New(env, MsgRecordOnDigital));
  cec.Set(Napi::String::New(env, "msgRecordOnAnalog"),
          Napi::Function::New(env, MsgRecordOnAnalog));
  cec.Set(Napi::String::New(env, "msgRecordOnPlug"),
          Napi::Function::New(env, MsgRecordOnPlug));
  cec.Set(Napi::String::New(env, "msgRecordOnPhysAddr"),
          Napi::Function::New(env, MsgRecordOnPhysAddr));
  cec.Set(Napi::String::New(env, "msgRecordOn"),
          Napi::Function::New(env, MsgRecordOn));
  cec.Set(Napi::String::New(env, "opsRecordOn"),
          Napi::Function::New(env, OpsRecordOn));
  cec.Set(Napi::String::New(env, "msgRecordStatus"),
          Napi::Function::New(env, MsgRecordStatus));
  cec.Set(Napi::String::New(env, "opsRecordStatus"),
          Napi::Function::New(env, OpsRecordStatus));
  cec.Set(Napi::String::New(env, "msgRecordTvScreen"),
          Napi::Function::New(env, MsgRecordTvScreen));
  cec.Set(Napi::String::New(env, "msgTimerStatus"),
          Napi::Function::New(env, MsgTimerStatus));
  cec.Set(Napi::String::New(env, "opsTimerStatus"),
          Napi::Function::New(env, OpsTimerStatus));
  cec.Set(Napi::String::New(env, "msgTimerClearedStatus"),
          Napi::Function::New(env, MsgTimerClearedStatus));
  cec.Set(Napi::String::New(env, "opsTimerClearedStatus"),
          Napi::Function::New(env, OpsTimerClearedStatus));
  cec.Set(Napi::String::New(env, "msgClearAnalogueTimer"),
          Napi::Function::New(env, MsgClearAnalogueTimer));
  cec.Set(Napi::String::New(env, "opsClearAnalogueTimer"),
          Napi::Function::New(env, OpsClearAnalogueTimer));
  cec.Set(Napi::String::New(env, "msgClearDigitalTimer"),
          Napi::Function::New(env, MsgClearDigitalTimer));
  cec.Set(Napi::String::New(env, "opsClearDigitalTimer"),
          Napi::Function::New(env, OpsClearDigitalTimer));
  cec.Set(Napi::String::New(env, "msgClearExtTimer"),
          Napi::Function::New(env, MsgClearExtTimer));
  cec.Set(Napi::String::New(env, "opsClearExtTimer"),
          Napi::Function::New(env, OpsClearExtTimer));
  cec.Set(Napi::String::New(env, "msgSetAnalogueTimer"),
          Napi::Function::New(env, MsgSetAnalogueTimer));
  cec.Set(Napi::String::New(env, "opsSetAnalogueTimer"),
          Napi::Function::New(env, OpsSetAnalogueTimer));
  cec.Set(Napi::String::New(env, "msgSetDigitalTimer"),
          Napi::Function::New(env, MsgSetDigitalTimer));
  cec.Set(Napi::String::New(env, "opsSetDigitalTimer"),
          Napi::Function::New(env, OpsSetDigitalTimer));
  cec.Set(Napi::String::New(env, "msgSetExtTimer"),
          Napi::Function::New(env, MsgSetExtTimer));
  cec.Set(Napi::String::New(env, "opsSetExtTimer"),
          Napi::Function::New(env, OpsSetExtTimer));
  cec.Set(Napi::String::New(env, "msgSetTimerProgramTitle"),
          Napi::Function::New(env, MsgSetTimerProgramTitle));
  cec.Set(Napi::String::New(env, "opsSetTimerProgramTitle"),
          Napi::Function::New(env, OpsSetTimerProgramTitle));
  cec.Set(Napi::String::New(env, "msgCecVersion"),
          Napi::Function::New(env, MsgCecVersion));
  cec.Set(Napi::String::New(env, "opsCecVersion"),
          Napi::Function::New(env, OpsCecVersion));
  cec.Set(Napi::String::New(env, "msgGetCecVersion"),
          Napi::Function::New(env, MsgGetCecVersion));
  cec.Set(Napi::String::New(env, "msgReportPhysicalAddr"),
          Napi::Function::New(env, MsgReportPhysicalAddr));
  cec.Set(Napi::String::New(env, "opsReportPhysicalAddr"),
          Napi::Function::New(env, OpsReportPhysicalAddr));
  cec.Set(Napi::String::New(env, "msgGivePhysicalAddr"),
          Napi::Function::New(env, MsgGivePhysicalAddr));
  cec.Set(Napi::String::New(env, "msgSetMenuLanguage"),
          Napi::Function::New(env, MsgSetMenuLanguage));
  cec.Set(Napi::String::New(env, "opsSetMenuLanguage"),
          Napi::Function::New(env, OpsSetMenuLanguage));
  cec.Set(Napi::String::New(env, "msgGetMenuLanguage"),
          Napi::Function::New(env, MsgGetMenuLanguage));
  cec.Set(Napi::String::New(env, "msgReportFeatures"),
          Napi::Function::New(env, MsgReportFeatures));
  cec.Set(Napi::String::New(env, "opsReportFeatures"),
          Napi::Function::New(env, OpsReportFeatures));
  cec.Set(Napi::String::New(env, "msgGiveFeatures"),
          Napi::Function::New(env, MsgGiveFeatures));
  cec.Set(Napi::String::New(env, "msgDeckControl"),
          Napi::Function::New(env, MsgDeckControl));
  cec.Set(Napi::String::New(env, "opsDeckControl"),
          Napi::Function::New(env, OpsDeckControl));
  cec.Set(Napi::String::New(env, "msgDeckStatus"),
          Napi::Function::New(env, MsgDeckStatus));
  cec.Set(Napi::String::New(env, "opsDeckStatus"),
          Napi::Function::New(env, OpsDeckStatus));
  cec.Set(Napi::String::New(env, "msgGiveDeckStatus"),
          Napi::Function::New(env, MsgGiveDeckStatus));
  cec.Set(Napi::String::New(env, "opsGiveDeckStatus"),
          Napi::Function::New(env, OpsGiveDeckStatus));
  cec.Set(Napi::String::New(env, "msgPlay"), Napi::Function::New(env, MsgPlay));
  cec.Set(Napi::String::New(env, "opsPlay"), Napi::Function::New(env, OpsPlay));
  cec.Set(Napi::String::New(env, "msgTunerDeviceStatusAnalog"),
          Napi::Function::New(env, MsgTunerDeviceStatusAnalog));
  cec.Set(Napi::String::New(env, "msgTunerDeviceStatusDigital"),
          Napi::Function::New(env, MsgTunerDeviceStatusDigital));
  cec.Set(Napi::String::New(env, "msgTunerDeviceStatus"),
          Napi::Function::New(env, MsgTunerDeviceStatus));
  cec.Set(Napi::String::New(env, "opsTunerDeviceStatus"),
          Napi::Function::New(env, OpsTunerDeviceStatus));
  cec.Set(Napi::String::New(env, "msgGiveTunerDeviceStatus"),
          Napi::Function::New(env, MsgGiveTunerDeviceStatus));
  cec.Set(Napi::String::New(env, "opsGiveTunerDeviceStatus"),
          Napi::Function::New(env, OpsGiveTunerDeviceStatus));
  cec.Set(Napi::String::New(env, "msgSelectAnalogueService"),
          Napi::Function::New(env, MsgSelectAnalogueService));
  cec.Set(Napi::String::New(env, "opsSelectAnalogueService"),
          Napi::Function::New(env, OpsSelectAnalogueService));
  cec.Set(Napi::String::New(env, "msgSelectDigitalService"),
          Napi::Function::New(env, MsgSelectDigitalService));
  cec.Set(Napi::String::New(env, "opsSelectDigitalService"),
          Napi::Function::New(env, OpsSelectDigitalService));
  cec.Set(Napi::String::New(env, "msgTunerStepDecrement"),
          Napi::Function::New(env, MsgTunerStepDecrement));
  cec.Set(Napi::String::New(env, "msgTunerStepIncrement"),
          Napi::Function::New(env, MsgTunerStepIncrement));
  cec.Set(Napi::String::New(env, "msgDeviceVendorId"),
          Napi::Function::New(env, MsgDeviceVendorId));
  cec.Set(Napi::String::New(env, "opsDeviceVendorId"),
          Napi::Function::New(env, OpsDeviceVendorId));
  cec.Set(Napi::String::New(env, "msgGiveDeviceVendorId"),
          Napi::Function::New(env, MsgGiveDeviceVendorId));
  cec.Set(Napi::String::New(env, "msgVendorCommand"),
          Napi::Function::New(env, MsgVendorCommand));
  cec.Set(Napi::String::New(env, "opsVendorCommand"),
          Napi::Function::New(env, OpsVendorCommand));
  cec.Set(Napi::String::New(env, "msgVendorCommandWithId"),
          Napi::Function::New(env, MsgVendorCommandWithId));
  cec.Set(Napi::String::New(env, "opsVendorCommandWithId"),
          Napi::Function::New(env, OpsVendorCommandWithId));
  cec.Set(Napi::String::New(env, "msgVendorRemoteButtonDown"),
          Napi::Function::New(env, MsgVendorRemoteButtonDown));
  cec.Set(Napi::String::New(env, "opsVendorRemoteButtonDown"),
          Napi::Function::New(env, OpsVendorRemoteButtonDown));
  cec.Set(Napi::String::New(env, "msgVendorRemoteButtonUp"),
          Napi::Function::New(env, MsgVendorRemoteButtonUp));
  cec.Set(Napi::String::New(env, "msgSetOsdString"),
          Napi::Function::New(env, MsgSetOsdString));
  cec.Set(Napi::String::New(env, "opsSetOsdString"),
          Napi::Function::New(env, OpsSetOsdString));
  cec.Set(Napi::String::New(env, "msgSetOsdName"),
          Napi::Function::New(env, MsgSetOsdName));
  cec.Set(Napi::String::New(env, "opsSetOsdName"),
          Napi::Function::New(env, OpsSetOsdName));
  cec.Set(Napi::String::New(env, "msgGiveOsdName"),
          Napi::Function::New(env, MsgGiveOsdName));
  cec.Set(Napi::String::New(env, "msgMenuStatus"),
          Napi::Function::New(env, MsgMenuStatus));
  cec.Set(Napi::String::New(env, "opsMenuStatus"),
          Napi::Function::New(env, OpsMenuStatus));
  cec.Set(Napi::String::New(env, "msgMenuRequest"),
          Napi::Function::New(env, MsgMenuRequest));
  cec.Set(Napi::String::New(env, "opsMenuRequest"),
          Napi::Function::New(env, OpsMenuRequest));
  cec.Set(Napi::String::New(env, "msgUserControlPressed"),
          Napi::Function::New(env, MsgUserControlPressed));
  cec.Set(Napi::String::New(env, "opsUserControlPressed"),
          Napi::Function::New(env, OpsUserControlPressed));
  cec.Set(Napi::String::New(env, "msgUserControlReleased"),
          Napi::Function::New(env, MsgUserControlReleased));
  cec.Set(Napi::String::New(env, "msgReportPowerStatus"),
          Napi::Function::New(env, MsgReportPowerStatus));
  cec.Set(Napi::String::New(env, "opsReportPowerStatus"),
          Napi::Function::New(env, OpsReportPowerStatus));
  cec.Set(Napi::String::New(env, "msgGiveDevicePowerStatus"),
          Napi::Function::New(env, MsgGiveDevicePowerStatus));
  cec.Set(Napi::String::New(env, "msgFeatureAbort"),
          Napi::Function::New(env, MsgFeatureAbort));
  cec.Set(Napi::String::New(env, "opsFeatureAbort"),
          Napi::Function::New(env, OpsFeatureAbort));
  cec.Set(Napi::String::New(env, "msgReplyFeatureAbort"),
          Napi::Function::New(env, MsgReplyFeatureAbort));
  cec.Set(Napi::String::New(env, "msgAbort"),
          Napi::Function::New(env, MsgAbort));
  cec.Set(Napi::String::New(env, "msgReportAudioStatus"),
          Napi::Function::New(env, MsgReportAudioStatus));
  cec.Set(Napi::String::New(env, "opsReportAudioStatus"),
          Napi::Function::New(env, OpsReportAudioStatus));
  cec.Set(Napi::String::New(env, "msgGiveAudioStatus"),
          Napi::Function::New(env, MsgGiveAudioStatus));
  cec.Set(Napi::String::New(env, "msgSetSystemAudioMode"),
          Napi::Function::New(env, MsgSetSystemAudioMode));
  cec.Set(Napi::String::New(env, "opsSetSystemAudioMode"),
          Napi::Function::New(env, OpsSetSystemAudioMode));
  cec.Set(Napi::String::New(env, "msgSystemAudioModeRequest"),
          Napi::Function::New(env, MsgSystemAudioModeRequest));
  cec.Set(Napi::String::New(env, "opsSystemAudioModeRequest"),
          Napi::Function::New(env, OpsSystemAudioModeRequest));
  cec.Set(Napi::String::New(env, "msgSystemAudioModeStatus"),
          Napi::Function::New(env, MsgSystemAudioModeStatus));
  cec.Set(Napi::String::New(env, "opsSystemAudioModeStatus"),
          Napi::Function::New(env, OpsSystemAudioModeStatus));
  cec.Set(Napi::String::New(env, "msgGiveSystemAudioModeStatus"),
          Napi::Function::New(env, MsgGiveSystemAudioModeStatus));
  cec.Set(Napi::String::New(env, "msgReportShortAudioDescriptor"),
          Napi::Function::New(env, MsgReportShortAudioDescriptor));
  cec.Set(Napi::String::New(env, "opsReportShortAudioDescriptor"),
          Napi::Function::New(env, OpsReportShortAudioDescriptor));
  cec.Set(Napi::String::New(env, "msgRequestShortAudioDescriptor"),
          Napi::Function::New(env, MsgRequestShortAudioDescriptor));
  cec.Set(Napi::String::New(env, "opsRequestShortAudioDescriptor"),
          Napi::Function::New(env, OpsRequestShortAudioDescriptor));
  cec.Set(Napi::String::New(env, "msgSetAudioRate"),
          Napi::Function::New(env, MsgSetAudioRate));
  cec.Set(Napi::String::New(env, "opsSetAudioRate"),
          Napi::Function::New(env, OpsSetAudioRate));
  cec.Set(Napi::String::New(env, "msgReportArcInitiated"),
          Napi::Function::New(env, MsgReportArcInitiated));
  cec.Set(Napi::String::New(env, "msgInitiateArc"),
          Napi::Function::New(env, MsgInitiateArc));
  cec.Set(Napi::String::New(env, "msgRequestArcInitiation"),
          Napi::Function::New(env, MsgRequestArcInitiation));
  cec.Set(Napi::String::New(env, "msgReportArcTerminated"),
          Napi::Function::New(env, MsgReportArcTerminated));
  cec.Set(Napi::String::New(env, "msgTerminateArc"),
          Napi::Function::New(env, MsgTerminateArc));
  cec.Set(Napi::String::New(env, "msgRequestArcTermination"),
          Napi::Function::New(env, MsgRequestArcTermination));
  cec.Set(Napi::String::New(env, "msgReportCurrentLatency"),
          Napi::Function::New(env, MsgReportCurrentLatency));
  cec.Set(Napi::String::New(env, "opsReportCurrentLatency"),
          Napi::Function::New(env, OpsReportCurrentLatency));
  cec.Set(Napi::String::New(env, "msgRequestCurrentLatency"),
          Napi::Function::New(env, MsgRequestCurrentLatency));
  cec.Set(Napi::String::New(env, "opsRequestCurrentLatency"),
          Napi::Function::New(env, OpsRequestCurrentLatency));
  cec.Set(Napi::String::New(env, "msgCdcHecInquireState"),
          Napi::Function::New(env, MsgCdcHecInquireState));
  cec.Set(Napi::String::New(env, "opsCdcHecInquireState"),
          Napi::Function::New(env, OpsCdcHecInquireState));
  cec.Set(Napi::String::New(env, "msgCdcHecReportState"),
          Napi::Function::New(env, MsgCdcHecReportState));
  cec.Set(Napi::String::New(env, "opsCdcHecReportState"),
          Napi::Function::New(env, OpsCdcHecReportState));
  cec.Set(Napi::String::New(env, "msgCdcHecSetState"),
          Napi::Function::New(env, MsgCdcHecSetState));
  cec.Set(Napi::String::New(env, "opsCdcHecSetState"),
          Napi::Function::New(env, OpsCdcHecSetState));
  cec.Set(Napi::String::New(env, "msgCdcHecSetStateAdjacent"),
          Napi::Function::New(env, MsgCdcHecSetStateAdjacent));
  cec.Set(Napi::String::New(env, "opsCdcHecSetStateAdjacent"),
          Napi::Function::New(env, OpsCdcHecSetStateAdjacent));
  cec.Set(Napi::String::New(env, "msgCdcHecRequestDeactivation"),
          Napi::Function::New(env, MsgCdcHecRequestDeactivation));
  cec.Set(Napi::String::New(env, "opsCdcHecRequestDeactivation"),
          Napi::Function::New(env, OpsCdcHecRequestDeactivation));
  cec.Set(Napi::String::New(env, "msgCdcHecNotifyAlive"),
          Napi::Function::New(env, MsgCdcHecNotifyAlive));
  cec.Set(Napi::String::New(env, "opsCdcHecNotifyAlive"),
          Napi::Function::New(env, OpsCdcHecNotifyAlive));
  cec.Set(Napi::String::New(env, "msgCdcHecDiscover"),
          Napi::Function::New(env, MsgCdcHecDiscover));
  cec.Set(Napi::String::New(env, "opsCdcHecDiscover"),
          Napi::Function::New(env, OpsCdcHecDiscover));
  cec.Set(Napi::String::New(env, "msgCdcHpdSetState"),
          Napi::Function::New(env, MsgCdcHpdSetState));
  cec.Set(Napi::String::New(env, "opsCdcHpdSetState"),
          Napi::Function::New(env, OpsCdcHpdSetState));
  cec.Set(Napi::String::New(env, "msgCdcHpdReportState"),
          Napi::Function::New(env, MsgCdcHpdReportState));
  cec.Set(Napi::String::New(env, "opsCdcHpdReportState"),
          Napi::Function::New(env, OpsCdcHpdReportState));
  cec.DefineProperties({
      Napi::PropertyDescriptor::Value("MAX_MSG_SIZE",
                                      Napi::Number::New(env, CEC_MAX_MSG_SIZE),
                                      napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "MSG_FL_REPLY_TO_FOLLOWERS",
          Napi::Number::New(env, CEC_MSG_FL_REPLY_TO_FOLLOWERS),
          napi_enumerable),
      Napi::PropertyDescriptor::Value("TX_STATUS_OK",
                                      Napi::Number::New(env, CEC_TX_STATUS_OK),
                                      napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "TX_STATUS_ARB_LOST", Napi::Number::New(env, CEC_TX_STATUS_ARB_LOST),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "TX_STATUS_NACK", Napi::Number::New(env, CEC_TX_STATUS_NACK),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "TX_STATUS_LOW_DRIVE",
          Napi::Number::New(env, CEC_TX_STATUS_LOW_DRIVE), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "TX_STATUS_ERROR", Napi::Number::New(env, CEC_TX_STATUS_ERROR),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "TX_STATUS_MAX_RETRIES",
          Napi::Number::New(env, CEC_TX_STATUS_MAX_RETRIES), napi_enumerable),
      Napi::PropertyDescriptor::Value("RX_STATUS_OK",
                                      Napi::Number::New(env, CEC_RX_STATUS_OK),
                                      napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "RX_STATUS_TIMEOUT", Napi::Number::New(env, CEC_RX_STATUS_TIMEOUT),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "RX_STATUS_FEATURE_ABORT",
          Napi::Number::New(env, CEC_RX_STATUS_FEATURE_ABORT), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "LOG_ADDR_INVALID", Napi::Number::New(env, CEC_LOG_ADDR_INVALID),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "PHYS_ADDR_INVALID", Napi::Number::New(env, CEC_PHYS_ADDR_INVALID),
          napi_enumerable),
      Napi::PropertyDescriptor::Value("MAX_LOG_ADDRS",
                                      Napi::Number::New(env, CEC_MAX_LOG_ADDRS),
                                      napi_enumerable),
      Napi::PropertyDescriptor::Value("LOG_ADDR_TV",
                                      Napi::Number::New(env, CEC_LOG_ADDR_TV),
                                      napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "LOG_ADDR_RECORD_1", Napi::Number::New(env, CEC_LOG_ADDR_RECORD_1),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "LOG_ADDR_RECORD_2", Napi::Number::New(env, CEC_LOG_ADDR_RECORD_2),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "LOG_ADDR_TUNER_1", Napi::Number::New(env, CEC_LOG_ADDR_TUNER_1),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "LOG_ADDR_PLAYBACK_1",
          Napi::Number::New(env, CEC_LOG_ADDR_PLAYBACK_1), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "LOG_ADDR_AUDIOSYSTEM",
          Napi::Number::New(env, CEC_LOG_ADDR_AUDIOSYSTEM), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "LOG_ADDR_TUNER_2", Napi::Number::New(env, CEC_LOG_ADDR_TUNER_2),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "LOG_ADDR_TUNER_3", Napi::Number::New(env, CEC_LOG_ADDR_TUNER_3),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "LOG_ADDR_PLAYBACK_2",
          Napi::Number::New(env, CEC_LOG_ADDR_PLAYBACK_2), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "LOG_ADDR_RECORD_3", Napi::Number::New(env, CEC_LOG_ADDR_RECORD_3),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "LOG_ADDR_TUNER_4", Napi::Number::New(env, CEC_LOG_ADDR_TUNER_4),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "LOG_ADDR_PLAYBACK_3",
          Napi::Number::New(env, CEC_LOG_ADDR_PLAYBACK_3), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "LOG_ADDR_BACKUP_1", Napi::Number::New(env, CEC_LOG_ADDR_BACKUP_1),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "LOG_ADDR_BACKUP_2", Napi::Number::New(env, CEC_LOG_ADDR_BACKUP_2),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "LOG_ADDR_SPECIFIC", Napi::Number::New(env, CEC_LOG_ADDR_SPECIFIC),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "LOG_ADDR_UNREGISTERED",
          Napi::Number::New(env, CEC_LOG_ADDR_UNREGISTERED), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "LOG_ADDR_BROADCAST", Napi::Number::New(env, CEC_LOG_ADDR_BROADCAST),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "LOG_ADDR_TYPE_TV", Napi::Number::New(env, CEC_LOG_ADDR_TYPE_TV),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "LOG_ADDR_TYPE_RECORD",
          Napi::Number::New(env, CEC_LOG_ADDR_TYPE_RECORD), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "LOG_ADDR_TYPE_TUNER",
          Napi::Number::New(env, CEC_LOG_ADDR_TYPE_TUNER), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "LOG_ADDR_TYPE_PLAYBACK",
          Napi::Number::New(env, CEC_LOG_ADDR_TYPE_PLAYBACK), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "LOG_ADDR_TYPE_AUDIOSYSTEM",
          Napi::Number::New(env, CEC_LOG_ADDR_TYPE_AUDIOSYSTEM),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "LOG_ADDR_TYPE_SPECIFIC",
          Napi::Number::New(env, CEC_LOG_ADDR_TYPE_SPECIFIC), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "LOG_ADDR_TYPE_UNREGISTERED",
          Napi::Number::New(env, CEC_LOG_ADDR_TYPE_UNREGISTERED),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "LOG_ADDR_MASK_TV", Napi::Number::New(env, CEC_LOG_ADDR_MASK_TV),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "LOG_ADDR_MASK_RECORD",
          Napi::Number::New(env, CEC_LOG_ADDR_MASK_RECORD), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "LOG_ADDR_MASK_TUNER",
          Napi::Number::New(env, CEC_LOG_ADDR_MASK_TUNER), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "LOG_ADDR_MASK_PLAYBACK",
          Napi::Number::New(env, CEC_LOG_ADDR_MASK_PLAYBACK), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "LOG_ADDR_MASK_AUDIOSYSTEM",
          Napi::Number::New(env, CEC_LOG_ADDR_MASK_AUDIOSYSTEM),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "LOG_ADDR_MASK_BACKUP",
          Napi::Number::New(env, CEC_LOG_ADDR_MASK_BACKUP), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "LOG_ADDR_MASK_SPECIFIC",
          Napi::Number::New(env, CEC_LOG_ADDR_MASK_SPECIFIC), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "LOG_ADDR_MASK_UNREGISTERED",
          Napi::Number::New(env, CEC_LOG_ADDR_MASK_UNREGISTERED),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "VENDOR_ID_NONE", Napi::Number::New(env, CEC_VENDOR_ID_NONE),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "MODE_NO_INITIATOR", Napi::Number::New(env, CEC_MODE_NO_INITIATOR),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "MODE_INITIATOR", Napi::Number::New(env, CEC_MODE_INITIATOR),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "MODE_EXCL_INITIATOR",
          Napi::Number::New(env, CEC_MODE_EXCL_INITIATOR), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "MODE_INITIATOR_MSK", Napi::Number::New(env, CEC_MODE_INITIATOR_MSK),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "MODE_NO_FOLLOWER", Napi::Number::New(env, CEC_MODE_NO_FOLLOWER),
          napi_enumerable),
      Napi::PropertyDescriptor::Value("MODE_FOLLOWER",
                                      Napi::Number::New(env, CEC_MODE_FOLLOWER),
                                      napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "MODE_EXCL_FOLLOWER", Napi::Number::New(env, CEC_MODE_EXCL_FOLLOWER),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "MODE_EXCL_FOLLOWER_PASSTHRU",
          Napi::Number::New(env, CEC_MODE_EXCL_FOLLOWER_PASSTHRU),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "MODE_MONITOR_PIN", Napi::Number::New(env, CEC_MODE_MONITOR_PIN),
          napi_enumerable),
      Napi::PropertyDescriptor::Value("MODE_MONITOR",
                                      Napi::Number::New(env, CEC_MODE_MONITOR),
                                      napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "MODE_MONITOR_ALL", Napi::Number::New(env, CEC_MODE_MONITOR_ALL),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "MODE_FOLLOWER_MSK", Napi::Number::New(env, CEC_MODE_FOLLOWER_MSK),
          napi_enumerable),
      Napi::PropertyDescriptor::Value("CAP_PHYS_ADDR",
                                      Napi::Number::New(env, CEC_CAP_PHYS_ADDR),
                                      napi_enumerable),
      Napi::PropertyDescriptor::Value("CAP_LOG_ADDRS",
                                      Napi::Number::New(env, CEC_CAP_LOG_ADDRS),
                                      napi_enumerable),
      Napi::PropertyDescriptor::Value("CAP_TRANSMIT",
                                      Napi::Number::New(env, CEC_CAP_TRANSMIT),
                                      napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "CAP_PASSTHROUGH", Napi::Number::New(env, CEC_CAP_PASSTHROUGH),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "CAP_RC", Napi::Number::New(env, CEC_CAP_RC), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "CAP_MONITOR_ALL", Napi::Number::New(env, CEC_CAP_MONITOR_ALL),
          napi_enumerable),
      Napi::PropertyDescriptor::Value("CAP_NEEDS_HPD",
                                      Napi::Number::New(env, CEC_CAP_NEEDS_HPD),
                                      napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "CAP_MONITOR_PIN", Napi::Number::New(env, CEC_CAP_MONITOR_PIN),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "LOG_ADDRS_FL_ALLOW_UNREG_FALLBACK",
          Napi::Number::New(env, CEC_LOG_ADDRS_FL_ALLOW_UNREG_FALLBACK),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "LOG_ADDRS_FL_ALLOW_RC_PASSTHRU",
          Napi::Number::New(env, CEC_LOG_ADDRS_FL_ALLOW_RC_PASSTHRU),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "LOG_ADDRS_FL_CDC_ONLY",
          Napi::Number::New(env, CEC_LOG_ADDRS_FL_CDC_ONLY), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "EVENT_STATE_CHANGE", Napi::Number::New(env, CEC_EVENT_STATE_CHANGE),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "EVENT_LOST_MSGS", Napi::Number::New(env, CEC_EVENT_LOST_MSGS),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "EVENT_PIN_CEC_LOW", Napi::Number::New(env, CEC_EVENT_PIN_CEC_LOW),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "EVENT_PIN_CEC_HIGH", Napi::Number::New(env, CEC_EVENT_PIN_CEC_HIGH),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "EVENT_PIN_HPD_LOW", Napi::Number::New(env, CEC_EVENT_PIN_HPD_LOW),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "EVENT_PIN_HPD_HIGH", Napi::Number::New(env, CEC_EVENT_PIN_HPD_HIGH),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "EVENT_PIN_5V_LOW", Napi::Number::New(env, CEC_EVENT_PIN_5V_LOW),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "EVENT_PIN_5V_HIGH", Napi::Number::New(env, CEC_EVENT_PIN_5V_HIGH),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "EVENT_FL_INITIAL_STATE",
          Napi::Number::New(env, CEC_EVENT_FL_INITIAL_STATE), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "EVENT_FL_DROPPED_EVENTS",
          Napi::Number::New(env, CEC_EVENT_FL_DROPPED_EVENTS), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "MSG_ACTIVE_SOURCE", Napi::Number::New(env, CEC_MSG_ACTIVE_SOURCE),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "MSG_IMAGE_VIEW_ON", Napi::Number::New(env, CEC_MSG_IMAGE_VIEW_ON),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "MSG_TEXT_VIEW_ON", Napi::Number::New(env, CEC_MSG_TEXT_VIEW_ON),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "MSG_INACTIVE_SOURCE",
          Napi::Number::New(env, CEC_MSG_INACTIVE_SOURCE), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "MSG_REQUEST_ACTIVE_SOURCE",
          Napi::Number::New(env, CEC_MSG_REQUEST_ACTIVE_SOURCE),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "MSG_ROUTING_CHANGE", Napi::Number::New(env, CEC_MSG_ROUTING_CHANGE),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "MSG_ROUTING_INFORMATION",
          Napi::Number::New(env, CEC_MSG_ROUTING_INFORMATION), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "MSG_SET_STREAM_PATH",
          Napi::Number::New(env, CEC_MSG_SET_STREAM_PATH), napi_enumerable),
      Napi::PropertyDescriptor::Value("MSG_STANDBY",
                                      Napi::Number::New(env, CEC_MSG_STANDBY),
                                      napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "MSG_RECORD_OFF", Napi::Number::New(env, CEC_MSG_RECORD_OFF),
          napi_enumerable),
      Napi::PropertyDescriptor::Value("MSG_RECORD_ON",
                                      Napi::Number::New(env, CEC_MSG_RECORD_ON),
                                      napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_RECORD_SRC_OWN", Napi::Number::New(env, CEC_OP_RECORD_SRC_OWN),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_RECORD_SRC_DIGITAL",
          Napi::Number::New(env, CEC_OP_RECORD_SRC_DIGITAL), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_RECORD_SRC_ANALOG",
          Napi::Number::New(env, CEC_OP_RECORD_SRC_ANALOG), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_RECORD_SRC_EXT_PLUG",
          Napi::Number::New(env, CEC_OP_RECORD_SRC_EXT_PLUG), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_RECORD_SRC_EXT_PHYS_ADDR",
          Napi::Number::New(env, CEC_OP_RECORD_SRC_EXT_PHYS_ADDR),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_SERVICE_ID_METHOD_BY_DIG_ID",
          Napi::Number::New(env, CEC_OP_SERVICE_ID_METHOD_BY_DIG_ID),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_SERVICE_ID_METHOD_BY_CHANNEL",
          Napi::Number::New(env, CEC_OP_SERVICE_ID_METHOD_BY_CHANNEL),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_DIG_SERVICE_BCAST_SYSTEM_ARIB_GEN",
          Napi::Number::New(env, CEC_OP_DIG_SERVICE_BCAST_SYSTEM_ARIB_GEN),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_DIG_SERVICE_BCAST_SYSTEM_ATSC_GEN",
          Napi::Number::New(env, CEC_OP_DIG_SERVICE_BCAST_SYSTEM_ATSC_GEN),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_DIG_SERVICE_BCAST_SYSTEM_DVB_GEN",
          Napi::Number::New(env, CEC_OP_DIG_SERVICE_BCAST_SYSTEM_DVB_GEN),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_DIG_SERVICE_BCAST_SYSTEM_ARIB_BS",
          Napi::Number::New(env, CEC_OP_DIG_SERVICE_BCAST_SYSTEM_ARIB_BS),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_DIG_SERVICE_BCAST_SYSTEM_ARIB_CS",
          Napi::Number::New(env, CEC_OP_DIG_SERVICE_BCAST_SYSTEM_ARIB_CS),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_DIG_SERVICE_BCAST_SYSTEM_ARIB_T",
          Napi::Number::New(env, CEC_OP_DIG_SERVICE_BCAST_SYSTEM_ARIB_T),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_DIG_SERVICE_BCAST_SYSTEM_ATSC_CABLE",
          Napi::Number::New(env, CEC_OP_DIG_SERVICE_BCAST_SYSTEM_ATSC_CABLE),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_DIG_SERVICE_BCAST_SYSTEM_ATSC_SAT",
          Napi::Number::New(env, CEC_OP_DIG_SERVICE_BCAST_SYSTEM_ATSC_SAT),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_DIG_SERVICE_BCAST_SYSTEM_ATSC_T",
          Napi::Number::New(env, CEC_OP_DIG_SERVICE_BCAST_SYSTEM_ATSC_T),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_DIG_SERVICE_BCAST_SYSTEM_DVB_C",
          Napi::Number::New(env, CEC_OP_DIG_SERVICE_BCAST_SYSTEM_DVB_C),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_DIG_SERVICE_BCAST_SYSTEM_DVB_S",
          Napi::Number::New(env, CEC_OP_DIG_SERVICE_BCAST_SYSTEM_DVB_S),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_DIG_SERVICE_BCAST_SYSTEM_DVB_S2",
          Napi::Number::New(env, CEC_OP_DIG_SERVICE_BCAST_SYSTEM_DVB_S2),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_DIG_SERVICE_BCAST_SYSTEM_DVB_T",
          Napi::Number::New(env, CEC_OP_DIG_SERVICE_BCAST_SYSTEM_DVB_T),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_ANA_BCAST_TYPE_CABLE",
          Napi::Number::New(env, CEC_OP_ANA_BCAST_TYPE_CABLE), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_ANA_BCAST_TYPE_SATELLITE",
          Napi::Number::New(env, CEC_OP_ANA_BCAST_TYPE_SATELLITE),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_ANA_BCAST_TYPE_TERRESTRIAL",
          Napi::Number::New(env, CEC_OP_ANA_BCAST_TYPE_TERRESTRIAL),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_BCAST_SYSTEM_PAL_BG",
          Napi::Number::New(env, CEC_OP_BCAST_SYSTEM_PAL_BG), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_BCAST_SYSTEM_SECAM_LQ",
          Napi::Number::New(env, CEC_OP_BCAST_SYSTEM_SECAM_LQ),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_BCAST_SYSTEM_PAL_M",
          Napi::Number::New(env, CEC_OP_BCAST_SYSTEM_PAL_M), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_BCAST_SYSTEM_NTSC_M",
          Napi::Number::New(env, CEC_OP_BCAST_SYSTEM_NTSC_M), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_BCAST_SYSTEM_PAL_I",
          Napi::Number::New(env, CEC_OP_BCAST_SYSTEM_PAL_I), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_BCAST_SYSTEM_SECAM_DK",
          Napi::Number::New(env, CEC_OP_BCAST_SYSTEM_SECAM_DK),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_BCAST_SYSTEM_SECAM_BG",
          Napi::Number::New(env, CEC_OP_BCAST_SYSTEM_SECAM_BG),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_BCAST_SYSTEM_SECAM_L",
          Napi::Number::New(env, CEC_OP_BCAST_SYSTEM_SECAM_L), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_BCAST_SYSTEM_PAL_DK",
          Napi::Number::New(env, CEC_OP_BCAST_SYSTEM_PAL_DK), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_BCAST_SYSTEM_OTHER",
          Napi::Number::New(env, CEC_OP_BCAST_SYSTEM_OTHER), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_CHANNEL_NUMBER_FMT_1_PART",
          Napi::Number::New(env, CEC_OP_CHANNEL_NUMBER_FMT_1_PART),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_CHANNEL_NUMBER_FMT_2_PART",
          Napi::Number::New(env, CEC_OP_CHANNEL_NUMBER_FMT_2_PART),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "MSG_RECORD_STATUS", Napi::Number::New(env, CEC_MSG_RECORD_STATUS),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_RECORD_STATUS_CUR_SRC",
          Napi::Number::New(env, CEC_OP_RECORD_STATUS_CUR_SRC),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_RECORD_STATUS_DIG_SERVICE",
          Napi::Number::New(env, CEC_OP_RECORD_STATUS_DIG_SERVICE),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_RECORD_STATUS_ANA_SERVICE",
          Napi::Number::New(env, CEC_OP_RECORD_STATUS_ANA_SERVICE),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_RECORD_STATUS_EXT_INPUT",
          Napi::Number::New(env, CEC_OP_RECORD_STATUS_EXT_INPUT),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_RECORD_STATUS_NO_DIG_SERVICE",
          Napi::Number::New(env, CEC_OP_RECORD_STATUS_NO_DIG_SERVICE),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_RECORD_STATUS_NO_ANA_SERVICE",
          Napi::Number::New(env, CEC_OP_RECORD_STATUS_NO_ANA_SERVICE),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_RECORD_STATUS_NO_SERVICE",
          Napi::Number::New(env, CEC_OP_RECORD_STATUS_NO_SERVICE),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_RECORD_STATUS_INVALID_EXT_PLUG",
          Napi::Number::New(env, CEC_OP_RECORD_STATUS_INVALID_EXT_PLUG),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_RECORD_STATUS_INVALID_EXT_PHYS_ADDR",
          Napi::Number::New(env, CEC_OP_RECORD_STATUS_INVALID_EXT_PHYS_ADDR),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_RECORD_STATUS_UNSUP_CA",
          Napi::Number::New(env, CEC_OP_RECORD_STATUS_UNSUP_CA),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_RECORD_STATUS_NO_CA_ENTITLEMENTS",
          Napi::Number::New(env, CEC_OP_RECORD_STATUS_NO_CA_ENTITLEMENTS),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_RECORD_STATUS_CANT_COPY_SRC",
          Napi::Number::New(env, CEC_OP_RECORD_STATUS_CANT_COPY_SRC),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_RECORD_STATUS_NO_MORE_COPIES",
          Napi::Number::New(env, CEC_OP_RECORD_STATUS_NO_MORE_COPIES),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_RECORD_STATUS_NO_MEDIA",
          Napi::Number::New(env, CEC_OP_RECORD_STATUS_NO_MEDIA),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_RECORD_STATUS_PLAYING",
          Napi::Number::New(env, CEC_OP_RECORD_STATUS_PLAYING),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_RECORD_STATUS_ALREADY_RECORDING",
          Napi::Number::New(env, CEC_OP_RECORD_STATUS_ALREADY_RECORDING),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_RECORD_STATUS_MEDIA_PROT",
          Napi::Number::New(env, CEC_OP_RECORD_STATUS_MEDIA_PROT),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_RECORD_STATUS_NO_SIGNAL",
          Napi::Number::New(env, CEC_OP_RECORD_STATUS_NO_SIGNAL),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_RECORD_STATUS_MEDIA_PROBLEM",
          Napi::Number::New(env, CEC_OP_RECORD_STATUS_MEDIA_PROBLEM),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_RECORD_STATUS_NO_SPACE",
          Napi::Number::New(env, CEC_OP_RECORD_STATUS_NO_SPACE),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_RECORD_STATUS_PARENTAL_LOCK",
          Napi::Number::New(env, CEC_OP_RECORD_STATUS_PARENTAL_LOCK),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_RECORD_STATUS_TERMINATED_OK",
          Napi::Number::New(env, CEC_OP_RECORD_STATUS_TERMINATED_OK),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_RECORD_STATUS_ALREADY_TERM",
          Napi::Number::New(env, CEC_OP_RECORD_STATUS_ALREADY_TERM),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_RECORD_STATUS_OTHER",
          Napi::Number::New(env, CEC_OP_RECORD_STATUS_OTHER), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "MSG_RECORD_TV_SCREEN",
          Napi::Number::New(env, CEC_MSG_RECORD_TV_SCREEN), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "MSG_CLEAR_ANALOGUE_TIMER",
          Napi::Number::New(env, CEC_MSG_CLEAR_ANALOGUE_TIMER),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_REC_SEQ_SUNDAY", Napi::Number::New(env, CEC_OP_REC_SEQ_SUNDAY),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_REC_SEQ_MONDAY", Napi::Number::New(env, CEC_OP_REC_SEQ_MONDAY),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_REC_SEQ_TUESDAY", Napi::Number::New(env, CEC_OP_REC_SEQ_TUESDAY),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_REC_SEQ_WEDNESDAY",
          Napi::Number::New(env, CEC_OP_REC_SEQ_WEDNESDAY), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_REC_SEQ_THURSDAY",
          Napi::Number::New(env, CEC_OP_REC_SEQ_THURSDAY), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_REC_SEQ_FRIDAY", Napi::Number::New(env, CEC_OP_REC_SEQ_FRIDAY),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_REC_SEQ_SATERDAY",
          Napi::Number::New(env, CEC_OP_REC_SEQ_SATERDAY), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_REC_SEQ_ONCE_ONLY",
          Napi::Number::New(env, CEC_OP_REC_SEQ_ONCE_ONLY), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "MSG_CLEAR_DIGITAL_TIMER",
          Napi::Number::New(env, CEC_MSG_CLEAR_DIGITAL_TIMER), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "MSG_CLEAR_EXT_TIMER",
          Napi::Number::New(env, CEC_MSG_CLEAR_EXT_TIMER), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_EXT_SRC_PLUG", Napi::Number::New(env, CEC_OP_EXT_SRC_PLUG),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_EXT_SRC_PHYS_ADDR",
          Napi::Number::New(env, CEC_OP_EXT_SRC_PHYS_ADDR), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "MSG_SET_ANALOGUE_TIMER",
          Napi::Number::New(env, CEC_MSG_SET_ANALOGUE_TIMER), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "MSG_SET_DIGITAL_TIMER",
          Napi::Number::New(env, CEC_MSG_SET_DIGITAL_TIMER), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "MSG_SET_EXT_TIMER", Napi::Number::New(env, CEC_MSG_SET_EXT_TIMER),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "MSG_SET_TIMER_PROGRAM_TITLE",
          Napi::Number::New(env, CEC_MSG_SET_TIMER_PROGRAM_TITLE),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "MSG_TIMER_CLEARED_STATUS",
          Napi::Number::New(env, CEC_MSG_TIMER_CLEARED_STATUS),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_TIMER_CLR_STAT_RECORDING",
          Napi::Number::New(env, CEC_OP_TIMER_CLR_STAT_RECORDING),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_TIMER_CLR_STAT_NO_MATCHING",
          Napi::Number::New(env, CEC_OP_TIMER_CLR_STAT_NO_MATCHING),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_TIMER_CLR_STAT_NO_INFO",
          Napi::Number::New(env, CEC_OP_TIMER_CLR_STAT_NO_INFO),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_TIMER_CLR_STAT_CLEARED",
          Napi::Number::New(env, CEC_OP_TIMER_CLR_STAT_CLEARED),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "MSG_TIMER_STATUS", Napi::Number::New(env, CEC_MSG_TIMER_STATUS),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_TIMER_OVERLAP_WARNING_NO_OVERLAP",
          Napi::Number::New(env, CEC_OP_TIMER_OVERLAP_WARNING_NO_OVERLAP),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_TIMER_OVERLAP_WARNING_OVERLAP",
          Napi::Number::New(env, CEC_OP_TIMER_OVERLAP_WARNING_OVERLAP),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_MEDIA_INFO_UNPROT_MEDIA",
          Napi::Number::New(env, CEC_OP_MEDIA_INFO_UNPROT_MEDIA),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_MEDIA_INFO_PROT_MEDIA",
          Napi::Number::New(env, CEC_OP_MEDIA_INFO_PROT_MEDIA),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_MEDIA_INFO_NO_MEDIA",
          Napi::Number::New(env, CEC_OP_MEDIA_INFO_NO_MEDIA), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_PROG_IND_NOT_PROGRAMMED",
          Napi::Number::New(env, CEC_OP_PROG_IND_NOT_PROGRAMMED),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_PROG_IND_PROGRAMMED",
          Napi::Number::New(env, CEC_OP_PROG_IND_PROGRAMMED), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_PROG_INFO_ENOUGH_SPACE",
          Napi::Number::New(env, CEC_OP_PROG_INFO_ENOUGH_SPACE),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_PROG_INFO_NOT_ENOUGH_SPACE",
          Napi::Number::New(env, CEC_OP_PROG_INFO_NOT_ENOUGH_SPACE),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_PROG_INFO_MIGHT_NOT_BE_ENOUGH_SPACE",
          Napi::Number::New(env, CEC_OP_PROG_INFO_MIGHT_NOT_BE_ENOUGH_SPACE),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_PROG_INFO_NONE_AVAILABLE",
          Napi::Number::New(env, CEC_OP_PROG_INFO_NONE_AVAILABLE),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_PROG_ERROR_NO_FREE_TIMER",
          Napi::Number::New(env, CEC_OP_PROG_ERROR_NO_FREE_TIMER),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_PROG_ERROR_DATE_OUT_OF_RANGE",
          Napi::Number::New(env, CEC_OP_PROG_ERROR_DATE_OUT_OF_RANGE),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_PROG_ERROR_REC_SEQ_ERROR",
          Napi::Number::New(env, CEC_OP_PROG_ERROR_REC_SEQ_ERROR),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_PROG_ERROR_INV_EXT_PLUG",
          Napi::Number::New(env, CEC_OP_PROG_ERROR_INV_EXT_PLUG),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_PROG_ERROR_INV_EXT_PHYS_ADDR",
          Napi::Number::New(env, CEC_OP_PROG_ERROR_INV_EXT_PHYS_ADDR),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_PROG_ERROR_CA_UNSUPP",
          Napi::Number::New(env, CEC_OP_PROG_ERROR_CA_UNSUPP), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_PROG_ERROR_INSUF_CA_ENTITLEMENTS",
          Napi::Number::New(env, CEC_OP_PROG_ERROR_INSUF_CA_ENTITLEMENTS),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_PROG_ERROR_RESOLUTION_UNSUPP",
          Napi::Number::New(env, CEC_OP_PROG_ERROR_RESOLUTION_UNSUPP),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_PROG_ERROR_PARENTAL_LOCK",
          Napi::Number::New(env, CEC_OP_PROG_ERROR_PARENTAL_LOCK),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_PROG_ERROR_CLOCK_FAILURE",
          Napi::Number::New(env, CEC_OP_PROG_ERROR_CLOCK_FAILURE),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_PROG_ERROR_DUPLICATE",
          Napi::Number::New(env, CEC_OP_PROG_ERROR_DUPLICATE), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "MSG_CEC_VERSION", Napi::Number::New(env, CEC_MSG_CEC_VERSION),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_CEC_VERSION_1_3A",
          Napi::Number::New(env, CEC_OP_CEC_VERSION_1_3A), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_CEC_VERSION_1_4", Napi::Number::New(env, CEC_OP_CEC_VERSION_1_4),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_CEC_VERSION_2_0", Napi::Number::New(env, CEC_OP_CEC_VERSION_2_0),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "MSG_GET_CEC_VERSION",
          Napi::Number::New(env, CEC_MSG_GET_CEC_VERSION), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "MSG_GIVE_PHYSICAL_ADDR",
          Napi::Number::New(env, CEC_MSG_GIVE_PHYSICAL_ADDR), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "MSG_GET_MENU_LANGUAGE",
          Napi::Number::New(env, CEC_MSG_GET_MENU_LANGUAGE), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "MSG_REPORT_PHYSICAL_ADDR",
          Napi::Number::New(env, CEC_MSG_REPORT_PHYSICAL_ADDR),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_PRIM_DEVTYPE_TV", Napi::Number::New(env, CEC_OP_PRIM_DEVTYPE_TV),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_PRIM_DEVTYPE_RECORD",
          Napi::Number::New(env, CEC_OP_PRIM_DEVTYPE_RECORD), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_PRIM_DEVTYPE_TUNER",
          Napi::Number::New(env, CEC_OP_PRIM_DEVTYPE_TUNER), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_PRIM_DEVTYPE_PLAYBACK",
          Napi::Number::New(env, CEC_OP_PRIM_DEVTYPE_PLAYBACK),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_PRIM_DEVTYPE_AUDIOSYSTEM",
          Napi::Number::New(env, CEC_OP_PRIM_DEVTYPE_AUDIOSYSTEM),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_PRIM_DEVTYPE_SWITCH",
          Napi::Number::New(env, CEC_OP_PRIM_DEVTYPE_SWITCH), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_PRIM_DEVTYPE_PROCESSOR",
          Napi::Number::New(env, CEC_OP_PRIM_DEVTYPE_PROCESSOR),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "MSG_SET_MENU_LANGUAGE",
          Napi::Number::New(env, CEC_MSG_SET_MENU_LANGUAGE), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "MSG_REPORT_FEATURES",
          Napi::Number::New(env, CEC_MSG_REPORT_FEATURES), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_ALL_DEVTYPE_TV", Napi::Number::New(env, CEC_OP_ALL_DEVTYPE_TV),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_ALL_DEVTYPE_RECORD",
          Napi::Number::New(env, CEC_OP_ALL_DEVTYPE_RECORD), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_ALL_DEVTYPE_TUNER",
          Napi::Number::New(env, CEC_OP_ALL_DEVTYPE_TUNER), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_ALL_DEVTYPE_PLAYBACK",
          Napi::Number::New(env, CEC_OP_ALL_DEVTYPE_PLAYBACK), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_ALL_DEVTYPE_AUDIOSYSTEM",
          Napi::Number::New(env, CEC_OP_ALL_DEVTYPE_AUDIOSYSTEM),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_ALL_DEVTYPE_SWITCH",
          Napi::Number::New(env, CEC_OP_ALL_DEVTYPE_SWITCH), napi_enumerable),
      Napi::PropertyDescriptor::Value("OP_FEAT_EXT",
                                      Napi::Number::New(env, CEC_OP_FEAT_EXT),
                                      napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_FEAT_RC_TV_PROFILE_NONE",
          Napi::Number::New(env, CEC_OP_FEAT_RC_TV_PROFILE_NONE),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_FEAT_RC_TV_PROFILE_1",
          Napi::Number::New(env, CEC_OP_FEAT_RC_TV_PROFILE_1), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_FEAT_RC_TV_PROFILE_2",
          Napi::Number::New(env, CEC_OP_FEAT_RC_TV_PROFILE_2), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_FEAT_RC_TV_PROFILE_3",
          Napi::Number::New(env, CEC_OP_FEAT_RC_TV_PROFILE_3), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_FEAT_RC_TV_PROFILE_4",
          Napi::Number::New(env, CEC_OP_FEAT_RC_TV_PROFILE_4), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_FEAT_RC_SRC_HAS_DEV_ROOT_MENU",
          Napi::Number::New(env, CEC_OP_FEAT_RC_SRC_HAS_DEV_ROOT_MENU),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_FEAT_RC_SRC_HAS_DEV_SETUP_MENU",
          Napi::Number::New(env, CEC_OP_FEAT_RC_SRC_HAS_DEV_SETUP_MENU),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_FEAT_RC_SRC_HAS_CONTENTS_MENU",
          Napi::Number::New(env, CEC_OP_FEAT_RC_SRC_HAS_CONTENTS_MENU),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_FEAT_RC_SRC_HAS_MEDIA_TOP_MENU",
          Napi::Number::New(env, CEC_OP_FEAT_RC_SRC_HAS_MEDIA_TOP_MENU),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_FEAT_RC_SRC_HAS_MEDIA_CONTEXT_MENU",
          Napi::Number::New(env, CEC_OP_FEAT_RC_SRC_HAS_MEDIA_CONTEXT_MENU),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_FEAT_DEV_HAS_RECORD_TV_SCREEN",
          Napi::Number::New(env, CEC_OP_FEAT_DEV_HAS_RECORD_TV_SCREEN),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_FEAT_DEV_HAS_SET_OSD_STRING",
          Napi::Number::New(env, CEC_OP_FEAT_DEV_HAS_SET_OSD_STRING),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_FEAT_DEV_HAS_DECK_CONTROL",
          Napi::Number::New(env, CEC_OP_FEAT_DEV_HAS_DECK_CONTROL),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_FEAT_DEV_HAS_SET_AUDIO_RATE",
          Napi::Number::New(env, CEC_OP_FEAT_DEV_HAS_SET_AUDIO_RATE),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_FEAT_DEV_SINK_HAS_ARC_TX",
          Napi::Number::New(env, CEC_OP_FEAT_DEV_SINK_HAS_ARC_TX),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_FEAT_DEV_SOURCE_HAS_ARC_RX",
          Napi::Number::New(env, CEC_OP_FEAT_DEV_SOURCE_HAS_ARC_RX),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "MSG_GIVE_FEATURES", Napi::Number::New(env, CEC_MSG_GIVE_FEATURES),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "MSG_DECK_CONTROL", Napi::Number::New(env, CEC_MSG_DECK_CONTROL),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_DECK_CTL_MODE_SKIP_FWD",
          Napi::Number::New(env, CEC_OP_DECK_CTL_MODE_SKIP_FWD),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_DECK_CTL_MODE_SKIP_REV",
          Napi::Number::New(env, CEC_OP_DECK_CTL_MODE_SKIP_REV),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_DECK_CTL_MODE_STOP",
          Napi::Number::New(env, CEC_OP_DECK_CTL_MODE_STOP), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_DECK_CTL_MODE_EJECT",
          Napi::Number::New(env, CEC_OP_DECK_CTL_MODE_EJECT), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "MSG_DECK_STATUS", Napi::Number::New(env, CEC_MSG_DECK_STATUS),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_DECK_INFO_PLAY", Napi::Number::New(env, CEC_OP_DECK_INFO_PLAY),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_DECK_INFO_RECORD",
          Napi::Number::New(env, CEC_OP_DECK_INFO_RECORD), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_DECK_INFO_PLAY_REV",
          Napi::Number::New(env, CEC_OP_DECK_INFO_PLAY_REV), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_DECK_INFO_STILL", Napi::Number::New(env, CEC_OP_DECK_INFO_STILL),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_DECK_INFO_SLOW", Napi::Number::New(env, CEC_OP_DECK_INFO_SLOW),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_DECK_INFO_SLOW_REV",
          Napi::Number::New(env, CEC_OP_DECK_INFO_SLOW_REV), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_DECK_INFO_FAST_FWD",
          Napi::Number::New(env, CEC_OP_DECK_INFO_FAST_FWD), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_DECK_INFO_FAST_REV",
          Napi::Number::New(env, CEC_OP_DECK_INFO_FAST_REV), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_DECK_INFO_NO_MEDIA",
          Napi::Number::New(env, CEC_OP_DECK_INFO_NO_MEDIA), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_DECK_INFO_STOP", Napi::Number::New(env, CEC_OP_DECK_INFO_STOP),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_DECK_INFO_SKIP_FWD",
          Napi::Number::New(env, CEC_OP_DECK_INFO_SKIP_FWD), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_DECK_INFO_SKIP_REV",
          Napi::Number::New(env, CEC_OP_DECK_INFO_SKIP_REV), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_DECK_INFO_INDEX_SEARCH_FWD",
          Napi::Number::New(env, CEC_OP_DECK_INFO_INDEX_SEARCH_FWD),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_DECK_INFO_INDEX_SEARCH_REV",
          Napi::Number::New(env, CEC_OP_DECK_INFO_INDEX_SEARCH_REV),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_DECK_INFO_OTHER", Napi::Number::New(env, CEC_OP_DECK_INFO_OTHER),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "MSG_GIVE_DECK_STATUS",
          Napi::Number::New(env, CEC_MSG_GIVE_DECK_STATUS), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_STATUS_REQ_ON", Napi::Number::New(env, CEC_OP_STATUS_REQ_ON),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_STATUS_REQ_OFF", Napi::Number::New(env, CEC_OP_STATUS_REQ_OFF),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_STATUS_REQ_ONCE", Napi::Number::New(env, CEC_OP_STATUS_REQ_ONCE),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "MSG_PLAY", Napi::Number::New(env, CEC_MSG_PLAY), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_PLAY_MODE_PLAY_FWD",
          Napi::Number::New(env, CEC_OP_PLAY_MODE_PLAY_FWD), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_PLAY_MODE_PLAY_REV",
          Napi::Number::New(env, CEC_OP_PLAY_MODE_PLAY_REV), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_PLAY_MODE_PLAY_STILL",
          Napi::Number::New(env, CEC_OP_PLAY_MODE_PLAY_STILL), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_PLAY_MODE_PLAY_FAST_FWD_MIN",
          Napi::Number::New(env, CEC_OP_PLAY_MODE_PLAY_FAST_FWD_MIN),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_PLAY_MODE_PLAY_FAST_FWD_MED",
          Napi::Number::New(env, CEC_OP_PLAY_MODE_PLAY_FAST_FWD_MED),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_PLAY_MODE_PLAY_FAST_FWD_MAX",
          Napi::Number::New(env, CEC_OP_PLAY_MODE_PLAY_FAST_FWD_MAX),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_PLAY_MODE_PLAY_FAST_REV_MIN",
          Napi::Number::New(env, CEC_OP_PLAY_MODE_PLAY_FAST_REV_MIN),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_PLAY_MODE_PLAY_FAST_REV_MED",
          Napi::Number::New(env, CEC_OP_PLAY_MODE_PLAY_FAST_REV_MED),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_PLAY_MODE_PLAY_FAST_REV_MAX",
          Napi::Number::New(env, CEC_OP_PLAY_MODE_PLAY_FAST_REV_MAX),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_PLAY_MODE_PLAY_SLOW_FWD_MIN",
          Napi::Number::New(env, CEC_OP_PLAY_MODE_PLAY_SLOW_FWD_MIN),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_PLAY_MODE_PLAY_SLOW_FWD_MED",
          Napi::Number::New(env, CEC_OP_PLAY_MODE_PLAY_SLOW_FWD_MED),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_PLAY_MODE_PLAY_SLOW_FWD_MAX",
          Napi::Number::New(env, CEC_OP_PLAY_MODE_PLAY_SLOW_FWD_MAX),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_PLAY_MODE_PLAY_SLOW_REV_MIN",
          Napi::Number::New(env, CEC_OP_PLAY_MODE_PLAY_SLOW_REV_MIN),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_PLAY_MODE_PLAY_SLOW_REV_MED",
          Napi::Number::New(env, CEC_OP_PLAY_MODE_PLAY_SLOW_REV_MED),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_PLAY_MODE_PLAY_SLOW_REV_MAX",
          Napi::Number::New(env, CEC_OP_PLAY_MODE_PLAY_SLOW_REV_MAX),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "MSG_GIVE_TUNER_DEVICE_STATUS",
          Napi::Number::New(env, CEC_MSG_GIVE_TUNER_DEVICE_STATUS),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "MSG_SELECT_ANALOGUE_SERVICE",
          Napi::Number::New(env, CEC_MSG_SELECT_ANALOGUE_SERVICE),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "MSG_SELECT_DIGITAL_SERVICE",
          Napi::Number::New(env, CEC_MSG_SELECT_DIGITAL_SERVICE),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "MSG_TUNER_DEVICE_STATUS",
          Napi::Number::New(env, CEC_MSG_TUNER_DEVICE_STATUS), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_REC_FLAG_USED", Napi::Number::New(env, CEC_OP_REC_FLAG_USED),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_REC_FLAG_NOT_USED",
          Napi::Number::New(env, CEC_OP_REC_FLAG_NOT_USED), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_TUNER_DISPLAY_INFO_DIGITAL",
          Napi::Number::New(env, CEC_OP_TUNER_DISPLAY_INFO_DIGITAL),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_TUNER_DISPLAY_INFO_NONE",
          Napi::Number::New(env, CEC_OP_TUNER_DISPLAY_INFO_NONE),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_TUNER_DISPLAY_INFO_ANALOGUE",
          Napi::Number::New(env, CEC_OP_TUNER_DISPLAY_INFO_ANALOGUE),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "MSG_TUNER_STEP_DECREMENT",
          Napi::Number::New(env, CEC_MSG_TUNER_STEP_DECREMENT),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "MSG_TUNER_STEP_INCREMENT",
          Napi::Number::New(env, CEC_MSG_TUNER_STEP_INCREMENT),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "MSG_DEVICE_VENDOR_ID",
          Napi::Number::New(env, CEC_MSG_DEVICE_VENDOR_ID), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "MSG_GIVE_DEVICE_VENDOR_ID",
          Napi::Number::New(env, CEC_MSG_GIVE_DEVICE_VENDOR_ID),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "MSG_VENDOR_COMMAND", Napi::Number::New(env, CEC_MSG_VENDOR_COMMAND),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "MSG_VENDOR_COMMAND_WITH_ID",
          Napi::Number::New(env, CEC_MSG_VENDOR_COMMAND_WITH_ID),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "MSG_VENDOR_REMOTE_BUTTON_DOWN",
          Napi::Number::New(env, CEC_MSG_VENDOR_REMOTE_BUTTON_DOWN),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "MSG_VENDOR_REMOTE_BUTTON_UP",
          Napi::Number::New(env, CEC_MSG_VENDOR_REMOTE_BUTTON_UP),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "MSG_SET_OSD_STRING", Napi::Number::New(env, CEC_MSG_SET_OSD_STRING),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_DISP_CTL_DEFAULT",
          Napi::Number::New(env, CEC_OP_DISP_CTL_DEFAULT), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_DISP_CTL_UNTIL_CLEARED",
          Napi::Number::New(env, CEC_OP_DISP_CTL_UNTIL_CLEARED),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_DISP_CTL_CLEAR", Napi::Number::New(env, CEC_OP_DISP_CTL_CLEAR),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "MSG_GIVE_OSD_NAME", Napi::Number::New(env, CEC_MSG_GIVE_OSD_NAME),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "MSG_SET_OSD_NAME", Napi::Number::New(env, CEC_MSG_SET_OSD_NAME),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "MSG_MENU_REQUEST", Napi::Number::New(env, CEC_MSG_MENU_REQUEST),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_MENU_REQUEST_ACTIVATE",
          Napi::Number::New(env, CEC_OP_MENU_REQUEST_ACTIVATE),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_MENU_REQUEST_DEACTIVATE",
          Napi::Number::New(env, CEC_OP_MENU_REQUEST_DEACTIVATE),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_MENU_REQUEST_QUERY",
          Napi::Number::New(env, CEC_OP_MENU_REQUEST_QUERY), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "MSG_MENU_STATUS", Napi::Number::New(env, CEC_MSG_MENU_STATUS),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_MENU_STATE_ACTIVATED",
          Napi::Number::New(env, CEC_OP_MENU_STATE_ACTIVATED), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_MENU_STATE_DEACTIVATED",
          Napi::Number::New(env, CEC_OP_MENU_STATE_DEACTIVATED),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "MSG_USER_CONTROL_PRESSED",
          Napi::Number::New(env, CEC_MSG_USER_CONTROL_PRESSED),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_UI_BCAST_TYPE_TOGGLE_ALL",
          Napi::Number::New(env, CEC_OP_UI_BCAST_TYPE_TOGGLE_ALL),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_UI_BCAST_TYPE_TOGGLE_DIG_ANA",
          Napi::Number::New(env, CEC_OP_UI_BCAST_TYPE_TOGGLE_DIG_ANA),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_UI_BCAST_TYPE_ANALOGUE",
          Napi::Number::New(env, CEC_OP_UI_BCAST_TYPE_ANALOGUE),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_UI_BCAST_TYPE_ANALOGUE_T",
          Napi::Number::New(env, CEC_OP_UI_BCAST_TYPE_ANALOGUE_T),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_UI_BCAST_TYPE_ANALOGUE_CABLE",
          Napi::Number::New(env, CEC_OP_UI_BCAST_TYPE_ANALOGUE_CABLE),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_UI_BCAST_TYPE_ANALOGUE_SAT",
          Napi::Number::New(env, CEC_OP_UI_BCAST_TYPE_ANALOGUE_SAT),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_UI_BCAST_TYPE_DIGITAL",
          Napi::Number::New(env, CEC_OP_UI_BCAST_TYPE_DIGITAL),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_UI_BCAST_TYPE_DIGITAL_T",
          Napi::Number::New(env, CEC_OP_UI_BCAST_TYPE_DIGITAL_T),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_UI_BCAST_TYPE_DIGITAL_CABLE",
          Napi::Number::New(env, CEC_OP_UI_BCAST_TYPE_DIGITAL_CABLE),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_UI_BCAST_TYPE_DIGITAL_SAT",
          Napi::Number::New(env, CEC_OP_UI_BCAST_TYPE_DIGITAL_SAT),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_UI_BCAST_TYPE_DIGITAL_COM_SAT",
          Napi::Number::New(env, CEC_OP_UI_BCAST_TYPE_DIGITAL_COM_SAT),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_UI_BCAST_TYPE_DIGITAL_COM_SAT2",
          Napi::Number::New(env, CEC_OP_UI_BCAST_TYPE_DIGITAL_COM_SAT2),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_UI_BCAST_TYPE_IP",
          Napi::Number::New(env, CEC_OP_UI_BCAST_TYPE_IP), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_UI_SND_PRES_CTL_DUAL_MONO",
          Napi::Number::New(env, CEC_OP_UI_SND_PRES_CTL_DUAL_MONO),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_UI_SND_PRES_CTL_KARAOKE",
          Napi::Number::New(env, CEC_OP_UI_SND_PRES_CTL_KARAOKE),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_UI_SND_PRES_CTL_DOWNMIX",
          Napi::Number::New(env, CEC_OP_UI_SND_PRES_CTL_DOWNMIX),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_UI_SND_PRES_CTL_REVERB",
          Napi::Number::New(env, CEC_OP_UI_SND_PRES_CTL_REVERB),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_UI_SND_PRES_CTL_EQUALIZER",
          Napi::Number::New(env, CEC_OP_UI_SND_PRES_CTL_EQUALIZER),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_UI_SND_PRES_CTL_BASS_UP",
          Napi::Number::New(env, CEC_OP_UI_SND_PRES_CTL_BASS_UP),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_UI_SND_PRES_CTL_BASS_NEUTRAL",
          Napi::Number::New(env, CEC_OP_UI_SND_PRES_CTL_BASS_NEUTRAL),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_UI_SND_PRES_CTL_BASS_DOWN",
          Napi::Number::New(env, CEC_OP_UI_SND_PRES_CTL_BASS_DOWN),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_UI_SND_PRES_CTL_TREBLE_UP",
          Napi::Number::New(env, CEC_OP_UI_SND_PRES_CTL_TREBLE_UP),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_UI_SND_PRES_CTL_TREBLE_NEUTRAL",
          Napi::Number::New(env, CEC_OP_UI_SND_PRES_CTL_TREBLE_NEUTRAL),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_UI_SND_PRES_CTL_TREBLE_DOWN",
          Napi::Number::New(env, CEC_OP_UI_SND_PRES_CTL_TREBLE_DOWN),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "MSG_USER_CONTROL_RELEASED",
          Napi::Number::New(env, CEC_MSG_USER_CONTROL_RELEASED),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "MSG_GIVE_DEVICE_POWER_STATUS",
          Napi::Number::New(env, CEC_MSG_GIVE_DEVICE_POWER_STATUS),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "MSG_REPORT_POWER_STATUS",
          Napi::Number::New(env, CEC_MSG_REPORT_POWER_STATUS), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_POWER_STATUS_ON", Napi::Number::New(env, CEC_OP_POWER_STATUS_ON),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_POWER_STATUS_STANDBY",
          Napi::Number::New(env, CEC_OP_POWER_STATUS_STANDBY), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_POWER_STATUS_TO_ON",
          Napi::Number::New(env, CEC_OP_POWER_STATUS_TO_ON), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_POWER_STATUS_TO_STANDBY",
          Napi::Number::New(env, CEC_OP_POWER_STATUS_TO_STANDBY),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "MSG_FEATURE_ABORT", Napi::Number::New(env, CEC_MSG_FEATURE_ABORT),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_ABORT_UNRECOGNIZED_OP",
          Napi::Number::New(env, CEC_OP_ABORT_UNRECOGNIZED_OP),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_ABORT_INCORRECT_MODE",
          Napi::Number::New(env, CEC_OP_ABORT_INCORRECT_MODE), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_ABORT_NO_SOURCE", Napi::Number::New(env, CEC_OP_ABORT_NO_SOURCE),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_ABORT_INVALID_OP",
          Napi::Number::New(env, CEC_OP_ABORT_INVALID_OP), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_ABORT_REFUSED", Napi::Number::New(env, CEC_OP_ABORT_REFUSED),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_ABORT_UNDETERMINED",
          Napi::Number::New(env, CEC_OP_ABORT_UNDETERMINED), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "MSG_ABORT", Napi::Number::New(env, CEC_MSG_ABORT), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "MSG_GIVE_AUDIO_STATUS",
          Napi::Number::New(env, CEC_MSG_GIVE_AUDIO_STATUS), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "MSG_GIVE_SYSTEM_AUDIO_MODE_STATUS",
          Napi::Number::New(env, CEC_MSG_GIVE_SYSTEM_AUDIO_MODE_STATUS),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "MSG_REPORT_AUDIO_STATUS",
          Napi::Number::New(env, CEC_MSG_REPORT_AUDIO_STATUS), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_AUD_MUTE_STATUS_OFF",
          Napi::Number::New(env, CEC_OP_AUD_MUTE_STATUS_OFF), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_AUD_MUTE_STATUS_ON",
          Napi::Number::New(env, CEC_OP_AUD_MUTE_STATUS_ON), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "MSG_REPORT_SHORT_AUDIO_DESCRIPTOR",
          Napi::Number::New(env, CEC_MSG_REPORT_SHORT_AUDIO_DESCRIPTOR),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "MSG_REQUEST_SHORT_AUDIO_DESCRIPTOR",
          Napi::Number::New(env, CEC_MSG_REQUEST_SHORT_AUDIO_DESCRIPTOR),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "MSG_SET_SYSTEM_AUDIO_MODE",
          Napi::Number::New(env, CEC_MSG_SET_SYSTEM_AUDIO_MODE),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_SYS_AUD_STATUS_OFF",
          Napi::Number::New(env, CEC_OP_SYS_AUD_STATUS_OFF), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_SYS_AUD_STATUS_ON",
          Napi::Number::New(env, CEC_OP_SYS_AUD_STATUS_ON), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "MSG_SYSTEM_AUDIO_MODE_REQUEST",
          Napi::Number::New(env, CEC_MSG_SYSTEM_AUDIO_MODE_REQUEST),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "MSG_SYSTEM_AUDIO_MODE_STATUS",
          Napi::Number::New(env, CEC_MSG_SYSTEM_AUDIO_MODE_STATUS),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_AUD_FMT_ID_CEA861",
          Napi::Number::New(env, CEC_OP_AUD_FMT_ID_CEA861), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_AUD_FMT_ID_CEA861_CXT",
          Napi::Number::New(env, CEC_OP_AUD_FMT_ID_CEA861_CXT),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "MSG_SET_AUDIO_RATE", Napi::Number::New(env, CEC_MSG_SET_AUDIO_RATE),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_AUD_RATE_OFF", Napi::Number::New(env, CEC_OP_AUD_RATE_OFF),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_AUD_RATE_WIDE_STD",
          Napi::Number::New(env, CEC_OP_AUD_RATE_WIDE_STD), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_AUD_RATE_WIDE_FAST",
          Napi::Number::New(env, CEC_OP_AUD_RATE_WIDE_FAST), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_AUD_RATE_WIDE_SLOW",
          Napi::Number::New(env, CEC_OP_AUD_RATE_WIDE_SLOW), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_AUD_RATE_NARROW_STD",
          Napi::Number::New(env, CEC_OP_AUD_RATE_NARROW_STD), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_AUD_RATE_NARROW_FAST",
          Napi::Number::New(env, CEC_OP_AUD_RATE_NARROW_FAST), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_AUD_RATE_NARROW_SLOW",
          Napi::Number::New(env, CEC_OP_AUD_RATE_NARROW_SLOW), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "MSG_INITIATE_ARC", Napi::Number::New(env, CEC_MSG_INITIATE_ARC),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "MSG_REPORT_ARC_INITIATED",
          Napi::Number::New(env, CEC_MSG_REPORT_ARC_INITIATED),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "MSG_REPORT_ARC_TERMINATED",
          Napi::Number::New(env, CEC_MSG_REPORT_ARC_TERMINATED),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "MSG_REQUEST_ARC_INITIATION",
          Napi::Number::New(env, CEC_MSG_REQUEST_ARC_INITIATION),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "MSG_REQUEST_ARC_TERMINATION",
          Napi::Number::New(env, CEC_MSG_REQUEST_ARC_TERMINATION),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "MSG_TERMINATE_ARC", Napi::Number::New(env, CEC_MSG_TERMINATE_ARC),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "MSG_REQUEST_CURRENT_LATENCY",
          Napi::Number::New(env, CEC_MSG_REQUEST_CURRENT_LATENCY),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "MSG_REPORT_CURRENT_LATENCY",
          Napi::Number::New(env, CEC_MSG_REPORT_CURRENT_LATENCY),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_LOW_LATENCY_MODE_OFF",
          Napi::Number::New(env, CEC_OP_LOW_LATENCY_MODE_OFF), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_LOW_LATENCY_MODE_ON",
          Napi::Number::New(env, CEC_OP_LOW_LATENCY_MODE_ON), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_AUD_OUT_COMPENSATED_NA",
          Napi::Number::New(env, CEC_OP_AUD_OUT_COMPENSATED_NA),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_AUD_OUT_COMPENSATED_DELAY",
          Napi::Number::New(env, CEC_OP_AUD_OUT_COMPENSATED_DELAY),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_AUD_OUT_COMPENSATED_NO_DELAY",
          Napi::Number::New(env, CEC_OP_AUD_OUT_COMPENSATED_NO_DELAY),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_AUD_OUT_COMPENSATED_PARTIAL_DELAY",
          Napi::Number::New(env, CEC_OP_AUD_OUT_COMPENSATED_PARTIAL_DELAY),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "MSG_CDC_MESSAGE", Napi::Number::New(env, CEC_MSG_CDC_MESSAGE),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "MSG_CDC_HEC_INQUIRE_STATE",
          Napi::Number::New(env, CEC_MSG_CDC_HEC_INQUIRE_STATE),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "MSG_CDC_HEC_REPORT_STATE",
          Napi::Number::New(env, CEC_MSG_CDC_HEC_REPORT_STATE),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_HEC_FUNC_STATE_NOT_SUPPORTED",
          Napi::Number::New(env, CEC_OP_HEC_FUNC_STATE_NOT_SUPPORTED),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_HEC_FUNC_STATE_INACTIVE",
          Napi::Number::New(env, CEC_OP_HEC_FUNC_STATE_INACTIVE),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_HEC_FUNC_STATE_ACTIVE",
          Napi::Number::New(env, CEC_OP_HEC_FUNC_STATE_ACTIVE),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_HEC_FUNC_STATE_ACTIVATION_FIELD",
          Napi::Number::New(env, CEC_OP_HEC_FUNC_STATE_ACTIVATION_FIELD),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_HOST_FUNC_STATE_NOT_SUPPORTED",
          Napi::Number::New(env, CEC_OP_HOST_FUNC_STATE_NOT_SUPPORTED),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_HOST_FUNC_STATE_INACTIVE",
          Napi::Number::New(env, CEC_OP_HOST_FUNC_STATE_INACTIVE),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_HOST_FUNC_STATE_ACTIVE",
          Napi::Number::New(env, CEC_OP_HOST_FUNC_STATE_ACTIVE),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_ENC_FUNC_STATE_EXT_CON_NOT_SUPPORTED",
          Napi::Number::New(env, CEC_OP_ENC_FUNC_STATE_EXT_CON_NOT_SUPPORTED),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_ENC_FUNC_STATE_EXT_CON_INACTIVE",
          Napi::Number::New(env, CEC_OP_ENC_FUNC_STATE_EXT_CON_INACTIVE),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_ENC_FUNC_STATE_EXT_CON_ACTIVE",
          Napi::Number::New(env, CEC_OP_ENC_FUNC_STATE_EXT_CON_ACTIVE),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_CDC_ERROR_CODE_NONE",
          Napi::Number::New(env, CEC_OP_CDC_ERROR_CODE_NONE), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_CDC_ERROR_CODE_CAP_UNSUPPORTED",
          Napi::Number::New(env, CEC_OP_CDC_ERROR_CODE_CAP_UNSUPPORTED),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_CDC_ERROR_CODE_WRONG_STATE",
          Napi::Number::New(env, CEC_OP_CDC_ERROR_CODE_WRONG_STATE),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_CDC_ERROR_CODE_OTHER",
          Napi::Number::New(env, CEC_OP_CDC_ERROR_CODE_OTHER), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_HEC_SUPPORT_NO", Napi::Number::New(env, CEC_OP_HEC_SUPPORT_NO),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_HEC_SUPPORT_YES", Napi::Number::New(env, CEC_OP_HEC_SUPPORT_YES),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_HEC_ACTIVATION_ON",
          Napi::Number::New(env, CEC_OP_HEC_ACTIVATION_ON), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_HEC_ACTIVATION_OFF",
          Napi::Number::New(env, CEC_OP_HEC_ACTIVATION_OFF), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "MSG_CDC_HEC_SET_STATE_ADJACENT",
          Napi::Number::New(env, CEC_MSG_CDC_HEC_SET_STATE_ADJACENT),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "MSG_CDC_HEC_SET_STATE",
          Napi::Number::New(env, CEC_MSG_CDC_HEC_SET_STATE), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_HEC_SET_STATE_DEACTIVATE",
          Napi::Number::New(env, CEC_OP_HEC_SET_STATE_DEACTIVATE),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_HEC_SET_STATE_ACTIVATE",
          Napi::Number::New(env, CEC_OP_HEC_SET_STATE_ACTIVATE),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "MSG_CDC_HEC_REQUEST_DEACTIVATION",
          Napi::Number::New(env, CEC_MSG_CDC_HEC_REQUEST_DEACTIVATION),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "MSG_CDC_HEC_NOTIFY_ALIVE",
          Napi::Number::New(env, CEC_MSG_CDC_HEC_NOTIFY_ALIVE),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "MSG_CDC_HEC_DISCOVER",
          Napi::Number::New(env, CEC_MSG_CDC_HEC_DISCOVER), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "MSG_CDC_HPD_SET_STATE",
          Napi::Number::New(env, CEC_MSG_CDC_HPD_SET_STATE), napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_HPD_STATE_CP_EDID_DISABLE",
          Napi::Number::New(env, CEC_OP_HPD_STATE_CP_EDID_DISABLE),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_HPD_STATE_CP_EDID_ENABLE",
          Napi::Number::New(env, CEC_OP_HPD_STATE_CP_EDID_ENABLE),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_HPD_STATE_CP_EDID_DISABLE_ENABLE",
          Napi::Number::New(env, CEC_OP_HPD_STATE_CP_EDID_DISABLE_ENABLE),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_HPD_STATE_EDID_DISABLE",
          Napi::Number::New(env, CEC_OP_HPD_STATE_EDID_DISABLE),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_HPD_STATE_EDID_ENABLE",
          Napi::Number::New(env, CEC_OP_HPD_STATE_EDID_ENABLE),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_HPD_STATE_EDID_DISABLE_ENABLE",
          Napi::Number::New(env, CEC_OP_HPD_STATE_EDID_DISABLE_ENABLE),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "MSG_CDC_HPD_REPORT_STATE",
          Napi::Number::New(env, CEC_MSG_CDC_HPD_REPORT_STATE),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_HPD_ERROR_NONE", Napi::Number::New(env, CEC_OP_HPD_ERROR_NONE),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_HPD_ERROR_INITIATOR_NOT_CAPABLE",
          Napi::Number::New(env, CEC_OP_HPD_ERROR_INITIATOR_NOT_CAPABLE),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_HPD_ERROR_INITIATOR_WRONG_STATE",
          Napi::Number::New(env, CEC_OP_HPD_ERROR_INITIATOR_WRONG_STATE),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_HPD_ERROR_OTHER", Napi::Number::New(env, CEC_OP_HPD_ERROR_OTHER),
          napi_enumerable),
      Napi::PropertyDescriptor::Value(
          "OP_HPD_ERROR_NONE_NO_VIDEO",
          Napi::Number::New(env, CEC_OP_HPD_ERROR_NONE_NO_VIDEO),
          napi_enumerable),
  });

  exports.Set(Napi::String::New(env, "cec"), cec);
  return exports;
}

}  // namespace Cec
}  // namespace nodelinuxcec
