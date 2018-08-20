
#ifndef NODE_LINUX_CEC_CEC_H_
#define NODE_LINUX_CEC_CEC_H_

#include <sys/ioctl.h>  // Must load before linux/cec

#include <linux/cec-funcs.h>
#include <linux/cec.h>
#include <napi.h>
#include "small-int.h"
#include "types.h"

#ifndef CEC_EVENT_PIN_5V_LOW
#define CEC_EVENT_PIN_5V_LOW 7
#endif

#ifndef CEC_EVENT_PIN_5V_HIGH
#define CEC_EVENT_PIN_5V_HIGH 8
#endif

namespace nodelinuxcec {
namespace Cec {

Napi::Object Init(Napi::Env env, Napi::Object exports);

Napi::Value MsgInitiator(const Napi::CallbackInfo& info);
Napi::Value MsgDestination(const Napi::CallbackInfo& info);
Napi::Value MsgOpcode(const Napi::CallbackInfo& info);
Napi::Value MsgIsBroadcast(const Napi::CallbackInfo& info);
Napi::Value MsgInit(const Napi::CallbackInfo& info);
Napi::Value MsgSetReplyTo(const Napi::CallbackInfo& info);
Napi::Value MsgStatusIsOk(const Napi::CallbackInfo& info);
Napi::Value HasTv(const Napi::CallbackInfo& info);
Napi::Value HasRecord(const Napi::CallbackInfo& info);
Napi::Value HasTuner(const Napi::CallbackInfo& info);
Napi::Value HasPlayback(const Napi::CallbackInfo& info);
Napi::Value HasAudiosystem(const Napi::CallbackInfo& info);
Napi::Value HasBackup(const Napi::CallbackInfo& info);
Napi::Value HasSpecific(const Napi::CallbackInfo& info);
Napi::Value IsUnregistered(const Napi::CallbackInfo& info);
Napi::Value IsUnconfigured(const Napi::CallbackInfo& info);
Napi::Value Is2ndTv(const Napi::CallbackInfo& info);
Napi::Value IsProcessor(const Napi::CallbackInfo& info);
Napi::Value IsSwitch(const Napi::CallbackInfo& info);
Napi::Value IsCdcOnly(const Napi::CallbackInfo& info);
Napi::Value MsgActiveSource(const Napi::CallbackInfo& info);
Napi::Value OpsActiveSource(const Napi::CallbackInfo& info);
Napi::Value MsgImageViewOn(const Napi::CallbackInfo& info);
Napi::Value MsgTextViewOn(const Napi::CallbackInfo& info);
Napi::Value MsgInactiveSource(const Napi::CallbackInfo& info);
Napi::Value OpsInactiveSource(const Napi::CallbackInfo& info);
Napi::Value MsgRequestActiveSource(const Napi::CallbackInfo& info);
Napi::Value MsgRoutingInformation(const Napi::CallbackInfo& info);
Napi::Value OpsRoutingInformation(const Napi::CallbackInfo& info);
Napi::Value MsgRoutingChange(const Napi::CallbackInfo& info);
Napi::Value OpsRoutingChange(const Napi::CallbackInfo& info);
Napi::Value MsgSetStreamPath(const Napi::CallbackInfo& info);
Napi::Value OpsSetStreamPath(const Napi::CallbackInfo& info);
Napi::Value MsgStandby(const Napi::CallbackInfo& info);
Napi::Value MsgRecordOff(const Napi::CallbackInfo& info);
Napi::Value SetDigitalServiceId(const Napi::CallbackInfo& info);
Napi::Value GetDigitalServiceId(const Napi::CallbackInfo& info);
Napi::Value MsgRecordOnOwn(const Napi::CallbackInfo& info);
Napi::Value MsgRecordOnDigital(const Napi::CallbackInfo& info);
Napi::Value MsgRecordOnAnalog(const Napi::CallbackInfo& info);
Napi::Value MsgRecordOnPlug(const Napi::CallbackInfo& info);
Napi::Value MsgRecordOnPhysAddr(const Napi::CallbackInfo& info);
Napi::Value MsgRecordOn(const Napi::CallbackInfo& info);
Napi::Value OpsRecordOn(const Napi::CallbackInfo& info);
Napi::Value MsgRecordStatus(const Napi::CallbackInfo& info);
Napi::Value OpsRecordStatus(const Napi::CallbackInfo& info);
Napi::Value MsgRecordTvScreen(const Napi::CallbackInfo& info);
Napi::Value MsgTimerStatus(const Napi::CallbackInfo& info);
Napi::Value OpsTimerStatus(const Napi::CallbackInfo& info);
Napi::Value MsgTimerClearedStatus(const Napi::CallbackInfo& info);
Napi::Value OpsTimerClearedStatus(const Napi::CallbackInfo& info);
Napi::Value MsgClearAnalogueTimer(const Napi::CallbackInfo& info);
Napi::Value OpsClearAnalogueTimer(const Napi::CallbackInfo& info);
Napi::Value MsgClearDigitalTimer(const Napi::CallbackInfo& info);
Napi::Value OpsClearDigitalTimer(const Napi::CallbackInfo& info);
Napi::Value MsgClearExtTimer(const Napi::CallbackInfo& info);
Napi::Value OpsClearExtTimer(const Napi::CallbackInfo& info);
Napi::Value MsgSetAnalogueTimer(const Napi::CallbackInfo& info);
Napi::Value OpsSetAnalogueTimer(const Napi::CallbackInfo& info);
Napi::Value MsgSetDigitalTimer(const Napi::CallbackInfo& info);
Napi::Value OpsSetDigitalTimer(const Napi::CallbackInfo& info);
Napi::Value MsgSetExtTimer(const Napi::CallbackInfo& info);
Napi::Value OpsSetExtTimer(const Napi::CallbackInfo& info);
Napi::Value MsgSetTimerProgramTitle(const Napi::CallbackInfo& info);
Napi::Value OpsSetTimerProgramTitle(const Napi::CallbackInfo& info);
Napi::Value MsgCecVersion(const Napi::CallbackInfo& info);
Napi::Value OpsCecVersion(const Napi::CallbackInfo& info);
Napi::Value MsgGetCecVersion(const Napi::CallbackInfo& info);
Napi::Value MsgReportPhysicalAddr(const Napi::CallbackInfo& info);
Napi::Value OpsReportPhysicalAddr(const Napi::CallbackInfo& info);
Napi::Value MsgGivePhysicalAddr(const Napi::CallbackInfo& info);
Napi::Value MsgSetMenuLanguage(const Napi::CallbackInfo& info);
Napi::Value OpsSetMenuLanguage(const Napi::CallbackInfo& info);
Napi::Value MsgGetMenuLanguage(const Napi::CallbackInfo& info);
Napi::Value MsgReportFeatures(const Napi::CallbackInfo& info);
Napi::Value OpsReportFeatures(const Napi::CallbackInfo& info);
Napi::Value MsgGiveFeatures(const Napi::CallbackInfo& info);
Napi::Value MsgDeckControl(const Napi::CallbackInfo& info);
Napi::Value OpsDeckControl(const Napi::CallbackInfo& info);
Napi::Value MsgDeckStatus(const Napi::CallbackInfo& info);
Napi::Value OpsDeckStatus(const Napi::CallbackInfo& info);
Napi::Value MsgGiveDeckStatus(const Napi::CallbackInfo& info);
Napi::Value OpsGiveDeckStatus(const Napi::CallbackInfo& info);
Napi::Value MsgPlay(const Napi::CallbackInfo& info);
Napi::Value OpsPlay(const Napi::CallbackInfo& info);
Napi::Value MsgTunerDeviceStatusAnalog(const Napi::CallbackInfo& info);
Napi::Value MsgTunerDeviceStatusDigital(const Napi::CallbackInfo& info);
Napi::Value MsgTunerDeviceStatus(const Napi::CallbackInfo& info);
Napi::Value OpsTunerDeviceStatus(const Napi::CallbackInfo& info);
Napi::Value MsgGiveTunerDeviceStatus(const Napi::CallbackInfo& info);
Napi::Value OpsGiveTunerDeviceStatus(const Napi::CallbackInfo& info);
Napi::Value MsgSelectAnalogueService(const Napi::CallbackInfo& info);
Napi::Value OpsSelectAnalogueService(const Napi::CallbackInfo& info);
Napi::Value MsgSelectDigitalService(const Napi::CallbackInfo& info);
Napi::Value OpsSelectDigitalService(const Napi::CallbackInfo& info);
Napi::Value MsgTunerStepDecrement(const Napi::CallbackInfo& info);
Napi::Value MsgTunerStepIncrement(const Napi::CallbackInfo& info);
Napi::Value MsgDeviceVendorId(const Napi::CallbackInfo& info);
Napi::Value OpsDeviceVendorId(const Napi::CallbackInfo& info);
Napi::Value MsgGiveDeviceVendorId(const Napi::CallbackInfo& info);
Napi::Value MsgVendorCommand(const Napi::CallbackInfo& info);
Napi::Value OpsVendorCommand(const Napi::CallbackInfo& info);
Napi::Value MsgVendorCommandWithId(const Napi::CallbackInfo& info);
Napi::Value OpsVendorCommandWithId(const Napi::CallbackInfo& info);
Napi::Value MsgVendorRemoteButtonDown(const Napi::CallbackInfo& info);
Napi::Value OpsVendorRemoteButtonDown(const Napi::CallbackInfo& info);
Napi::Value MsgVendorRemoteButtonUp(const Napi::CallbackInfo& info);
Napi::Value MsgSetOsdString(const Napi::CallbackInfo& info);
Napi::Value OpsSetOsdString(const Napi::CallbackInfo& info);
Napi::Value MsgSetOsdName(const Napi::CallbackInfo& info);
Napi::Value OpsSetOsdName(const Napi::CallbackInfo& info);
Napi::Value MsgGiveOsdName(const Napi::CallbackInfo& info);
Napi::Value MsgMenuStatus(const Napi::CallbackInfo& info);
Napi::Value OpsMenuStatus(const Napi::CallbackInfo& info);
Napi::Value MsgMenuRequest(const Napi::CallbackInfo& info);
Napi::Value OpsMenuRequest(const Napi::CallbackInfo& info);
Napi::Value MsgUserControlPressed(const Napi::CallbackInfo& info);
Napi::Value OpsUserControlPressed(const Napi::CallbackInfo& info);
Napi::Value MsgUserControlReleased(const Napi::CallbackInfo& info);
Napi::Value MsgReportPowerStatus(const Napi::CallbackInfo& info);
Napi::Value OpsReportPowerStatus(const Napi::CallbackInfo& info);
Napi::Value MsgGiveDevicePowerStatus(const Napi::CallbackInfo& info);
Napi::Value MsgFeatureAbort(const Napi::CallbackInfo& info);
Napi::Value OpsFeatureAbort(const Napi::CallbackInfo& info);
Napi::Value MsgReplyFeatureAbort(const Napi::CallbackInfo& info);
Napi::Value MsgAbort(const Napi::CallbackInfo& info);
Napi::Value MsgReportAudioStatus(const Napi::CallbackInfo& info);
Napi::Value OpsReportAudioStatus(const Napi::CallbackInfo& info);
Napi::Value MsgGiveAudioStatus(const Napi::CallbackInfo& info);
Napi::Value MsgSetSystemAudioMode(const Napi::CallbackInfo& info);
Napi::Value OpsSetSystemAudioMode(const Napi::CallbackInfo& info);
Napi::Value MsgSystemAudioModeRequest(const Napi::CallbackInfo& info);
Napi::Value OpsSystemAudioModeRequest(const Napi::CallbackInfo& info);
Napi::Value MsgSystemAudioModeStatus(const Napi::CallbackInfo& info);
Napi::Value OpsSystemAudioModeStatus(const Napi::CallbackInfo& info);
Napi::Value MsgGiveSystemAudioModeStatus(const Napi::CallbackInfo& info);
Napi::Value MsgReportShortAudioDescriptor(const Napi::CallbackInfo& info);
Napi::Value OpsReportShortAudioDescriptor(const Napi::CallbackInfo& info);
Napi::Value MsgRequestShortAudioDescriptor(const Napi::CallbackInfo& info);
Napi::Value OpsRequestShortAudioDescriptor(const Napi::CallbackInfo& info);
Napi::Value MsgSetAudioRate(const Napi::CallbackInfo& info);
Napi::Value OpsSetAudioRate(const Napi::CallbackInfo& info);
Napi::Value MsgReportArcInitiated(const Napi::CallbackInfo& info);
Napi::Value MsgInitiateArc(const Napi::CallbackInfo& info);
Napi::Value MsgRequestArcInitiation(const Napi::CallbackInfo& info);
Napi::Value MsgReportArcTerminated(const Napi::CallbackInfo& info);
Napi::Value MsgTerminateArc(const Napi::CallbackInfo& info);
Napi::Value MsgRequestArcTermination(const Napi::CallbackInfo& info);
Napi::Value MsgReportCurrentLatency(const Napi::CallbackInfo& info);
Napi::Value OpsReportCurrentLatency(const Napi::CallbackInfo& info);
Napi::Value MsgRequestCurrentLatency(const Napi::CallbackInfo& info);
Napi::Value OpsRequestCurrentLatency(const Napi::CallbackInfo& info);
Napi::Value MsgCdcHecInquireState(const Napi::CallbackInfo& info);
Napi::Value OpsCdcHecInquireState(const Napi::CallbackInfo& info);
Napi::Value MsgCdcHecReportState(const Napi::CallbackInfo& info);
Napi::Value OpsCdcHecReportState(const Napi::CallbackInfo& info);
Napi::Value MsgCdcHecSetState(const Napi::CallbackInfo& info);
Napi::Value OpsCdcHecSetState(const Napi::CallbackInfo& info);
Napi::Value MsgCdcHecSetStateAdjacent(const Napi::CallbackInfo& info);
Napi::Value OpsCdcHecSetStateAdjacent(const Napi::CallbackInfo& info);
Napi::Value MsgCdcHecRequestDeactivation(const Napi::CallbackInfo& info);
Napi::Value OpsCdcHecRequestDeactivation(const Napi::CallbackInfo& info);
Napi::Value MsgCdcHecNotifyAlive(const Napi::CallbackInfo& info);
Napi::Value OpsCdcHecNotifyAlive(const Napi::CallbackInfo& info);
Napi::Value MsgCdcHecDiscover(const Napi::CallbackInfo& info);
Napi::Value OpsCdcHecDiscover(const Napi::CallbackInfo& info);
Napi::Value MsgCdcHpdSetState(const Napi::CallbackInfo& info);
Napi::Value OpsCdcHpdSetState(const Napi::CallbackInfo& info);
Napi::Value MsgCdcHpdReportState(const Napi::CallbackInfo& info);
Napi::Value OpsCdcHpdReportState(const Napi::CallbackInfo& info);

}  // namespace Cec
}  // namespace nodelinuxcec

#endif  // NODE_LINUX_CEC_CEC_H_
