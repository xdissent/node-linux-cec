// @flow

import bindings from 'bindings'
import type {
  LogAddrs,
  Msg,
  OpDigitalServiceId,
  OpRecordSrc,
  OpTunerDeviceInfo,
  OpUiCommand
} from './types'

const {cec} = bindings('nodelinuxcec.node')

export const msgInitiator: (msg: Msg) => number = cec.msgInitiator
export const msgDestination: (msg: Msg) => number = cec.msgDestination
export const msgOpcode: (msg: Msg) => number = cec.msgOpcode
export const msgIsBroadcast: (msg: Msg) => boolean = cec.msgIsBroadcast
export const msgInit: (initiator: number, destination: number) => Msg =
  cec.msgInit
export const msgSetReplyTo: (msg: Msg, orig: Msg) => Msg = cec.msgSetReplyTo
export const msgStatusIsOk: (msg: Msg) => boolean = cec.msgStatusIsOk
export const hasTv: (logAddrMask: number) => boolean = cec.hasTv
export const hasRecord: (logAddrMask: number) => boolean = cec.hasRecord
export const hasTuner: (logAddrMask: number) => boolean = cec.hasTuner
export const hasPlayback: (logAddrMask: number) => boolean = cec.hasPlayback
export const hasAudiosystem: (logAddrMask: number) => boolean =
  cec.hasAudiosystem
export const hasBackup: (logAddrMask: number) => boolean = cec.hasBackup
export const hasSpecific: (logAddrMask: number) => boolean = cec.hasSpecific
export const isUnregistered: (logAddrMask: number) => boolean =
  cec.isUnregistered
export const isUnconfigured: (logAddrMask: number) => boolean =
  cec.isUnconfigured
export const is2ndTv: (las: LogAddrs) => boolean = cec.is2ndTv
export const isProcessor: (las: LogAddrs) => boolean = cec.isProcessor
export const isSwitch: (las: LogAddrs) => boolean = cec.isSwitch
export const isCdcOnly: (las: LogAddrs) => boolean = cec.isCdcOnly
export const msgActiveSource: (msg: Msg, physAddr: number) => Msg =
  cec.msgActiveSource
export const opsActiveSource: (msg: Msg) => number = cec.opsActiveSource
export const msgImageViewOn: (msg: Msg) => Msg = cec.msgImageViewOn
export const msgTextViewOn: (msg: Msg) => Msg = cec.msgTextViewOn
export const msgInactiveSource: (msg: Msg, physAddr: number) => Msg =
  cec.msgInactiveSource
export const opsInactiveSource: (msg: Msg) => number = cec.opsInactiveSource
export const msgRequestActiveSource: (msg: Msg, reply: boolean) => Msg =
  cec.msgRequestActiveSource
export const msgRoutingInformation: (msg: Msg, physAddr: number) => Msg =
  cec.msgRoutingInformation
export const opsRoutingInformation: (msg: Msg) => number =
  cec.opsRoutingInformation
export const msgRoutingChange: (
  msg: Msg,
  reply: boolean,
  origPhysAddr: number,
  newPhysAddr: number
) => Msg = cec.msgRoutingChange
export const opsRoutingChange: (
  msg: Msg
) => {
  origPhysAddr: number,
  newPhysAddr: number
} = cec.opsRoutingChange
export const msgSetStreamPath: (msg: Msg, physAddr: number) => Msg =
  cec.msgSetStreamPath
export const opsSetStreamPath: (msg: Msg) => number = cec.opsSetStreamPath
export const msgStandby: (msg: Msg) => Msg = cec.msgStandby
export const msgRecordOff: (msg: Msg, reply: boolean) => Msg = cec.msgRecordOff
export const setDigitalServiceId: (digital: OpDigitalServiceId) => number[] =
  cec.setDigitalServiceId
export const getDigitalServiceId: (msg: number[]) => OpDigitalServiceId =
  cec.getDigitalServiceId
export const msgRecordOnOwn: (msg: Msg) => Msg = cec.msgRecordOnOwn
export const msgRecordOnDigital: (
  msg: Msg,
  digital: OpDigitalServiceId
) => Msg = cec.msgRecordOnDigital
export const msgRecordOnAnalog: (
  msg: Msg,
  anaBcastType: number,
  anaFreq: number,
  bcastSystem: number
) => Msg = cec.msgRecordOnAnalog
export const msgRecordOnPlug: (msg: Msg, plug: number) => Msg =
  cec.msgRecordOnPlug
export const msgRecordOnPhysAddr: (msg: Msg, physAddr: number) => Msg =
  cec.msgRecordOnPhysAddr
export const msgRecordOn: (
  msg: Msg,
  reply: boolean,
  recSrc: OpRecordSrc
) => Msg = cec.msgRecordOn
export const opsRecordOn: (msg: Msg) => OpRecordSrc = cec.opsRecordOn
export const msgRecordStatus: (msg: Msg, recStatus: number) => Msg =
  cec.msgRecordStatus
export const opsRecordStatus: (msg: Msg) => number = cec.opsRecordStatus
export const msgRecordTvScreen: (msg: Msg, reply: boolean) => Msg =
  cec.msgRecordTvScreen
export const msgTimerStatus: (
  msg: Msg,
  timerOverlapWarning: number,
  mediaInfo: number,
  progInfo: number,
  progError: number,
  durationHr: number,
  durationMin: number
) => Msg = cec.msgTimerStatus
export const opsTimerStatus: (
  msg: Msg
) => {
  timerOverlapWarning: number,
  mediaInfo: number,
  progInfo: number,
  progError: number,
  durationHr: number,
  durationMin: number
} = cec.opsTimerStatus
export const msgTimerClearedStatus: (
  msg: Msg,
  timerClearedStatus: number
) => Msg = cec.msgTimerClearedStatus
export const opsTimerClearedStatus: (msg: Msg) => number =
  cec.opsTimerClearedStatus
export const msgClearAnalogueTimer: (
  msg: Msg,
  reply: boolean,
  day: number,
  month: number,
  startHr: number,
  startMin: number,
  durationHr: number,
  durationMin: number,
  recordingSeq: number,
  anaBcastType: number,
  anaFreq: number,
  bcastSystem: number
) => Msg = cec.msgClearAnalogueTimer
export const opsClearAnalogueTimer: (
  msg: Msg
) => {
  day: number,
  month: number,
  startHr: number,
  startMin: number,
  durationHr: number,
  durationMin: number,
  recordingSeq: number,
  anaBcastType: number,
  anaFreq: number,
  bcastSystem: number
} = cec.opsClearAnalogueTimer
export const msgClearDigitalTimer: (
  msg: Msg,
  reply: boolean,
  day: number,
  month: number,
  startHr: number,
  startMin: number,
  durationHr: number,
  durationMin: number,
  recordingSeq: number,
  digital: OpDigitalServiceId
) => Msg = cec.msgClearDigitalTimer
export const opsClearDigitalTimer: (
  msg: Msg
) => {
  day: number,
  month: number,
  startHr: number,
  startMin: number,
  durationHr: number,
  durationMin: number,
  recordingSeq: number,
  digital: OpDigitalServiceId
} = cec.opsClearDigitalTimer
export const msgClearExtTimer: (
  msg: Msg,
  reply: boolean,
  day: number,
  month: number,
  startHr: number,
  startMin: number,
  durationHr: number,
  durationMin: number,
  recordingSeq: number,
  extSrcSpec: number,
  plug: number,
  physAddr: number
) => Msg = cec.msgClearExtTimer
export const opsClearExtTimer: (
  msg: Msg
) => {
  day: number,
  month: number,
  startHr: number,
  startMin: number,
  durationHr: number,
  durationMin: number,
  recordingSeq: number,
  extSrcSpec: number,
  plug: number,
  physAddr: number
} = cec.opsClearExtTimer
export const msgSetAnalogueTimer: (
  msg: Msg,
  reply: boolean,
  day: number,
  month: number,
  startHr: number,
  startMin: number,
  durationHr: number,
  durationMin: number,
  recordingSeq: number,
  anaBcastType: number,
  anaFreq: number,
  bcastSystem: number
) => Msg = cec.msgSetAnalogueTimer
export const opsSetAnalogueTimer: (
  msg: Msg
) => {
  day: number,
  month: number,
  startHr: number,
  startMin: number,
  durationHr: number,
  durationMin: number,
  recordingSeq: number,
  anaBcastType: number,
  anaFreq: number,
  bcastSystem: number
} = cec.opsSetAnalogueTimer
export const msgSetDigitalTimer: (
  msg: Msg,
  reply: boolean,
  day: number,
  month: number,
  startHr: number,
  startMin: number,
  durationHr: number,
  durationMin: number,
  recordingSeq: number,
  digital: OpDigitalServiceId
) => Msg = cec.msgSetDigitalTimer
export const opsSetDigitalTimer: (
  msg: Msg
) => {
  day: number,
  month: number,
  startHr: number,
  startMin: number,
  durationHr: number,
  durationMin: number,
  recordingSeq: number,
  digital: OpDigitalServiceId
} = cec.opsSetDigitalTimer
export const msgSetExtTimer: (
  msg: Msg,
  reply: boolean,
  day: number,
  month: number,
  startHr: number,
  startMin: number,
  durationHr: number,
  durationMin: number,
  recordingSeq: number,
  extSrcSpec: number,
  plug: number,
  physAddr: number
) => Msg = cec.msgSetExtTimer
export const opsSetExtTimer: (
  msg: Msg
) => {
  day: number,
  month: number,
  startHr: number,
  startMin: number,
  durationHr: number,
  durationMin: number,
  recordingSeq: number,
  extSrcSpec: number,
  plug: number,
  physAddr: number
} = cec.opsSetExtTimer
export const msgSetTimerProgramTitle: (msg: Msg, progTitle: string) => Msg =
  cec.msgSetTimerProgramTitle
export const opsSetTimerProgramTitle: (msg: Msg) => string =
  cec.opsSetTimerProgramTitle
export const msgCecVersion: (msg: Msg, cecVersion: number) => Msg =
  cec.msgCecVersion
export const opsCecVersion: (msg: Msg) => number = cec.opsCecVersion
export const msgGetCecVersion: (msg: Msg, reply: boolean) => Msg =
  cec.msgGetCecVersion
export const msgReportPhysicalAddr: (
  msg: Msg,
  physAddr: number,
  primDevtype: number
) => Msg = cec.msgReportPhysicalAddr
export const opsReportPhysicalAddr: (
  msg: Msg
) => {
  physAddr: number,
  primDevtype: number
} = cec.opsReportPhysicalAddr
export const msgGivePhysicalAddr: (msg: Msg, reply: boolean) => Msg =
  cec.msgGivePhysicalAddr
export const msgSetMenuLanguage: (msg: Msg, language: string) => Msg =
  cec.msgSetMenuLanguage
export const opsSetMenuLanguage: (msg: Msg) => string = cec.opsSetMenuLanguage
export const msgGetMenuLanguage: (msg: Msg, reply: boolean) => Msg =
  cec.msgGetMenuLanguage
export const msgReportFeatures: (
  msg: Msg,
  cecVersion: number,
  allDeviceTypes: number,
  rcProfile: number,
  devFeatures: number
) => Msg = cec.msgReportFeatures
export const opsReportFeatures: (
  msg: Msg
) => {
  cecVersion: number,
  allDeviceTypes: number,
  rcProfile: number,
  devFeatures: number
} = cec.opsReportFeatures
export const msgGiveFeatures: (msg: Msg, reply: boolean) => Msg =
  cec.msgGiveFeatures
export const msgDeckControl: (msg: Msg, deckControlMode: number) => Msg =
  cec.msgDeckControl
export const opsDeckControl: (msg: Msg) => number = cec.opsDeckControl
export const msgDeckStatus: (msg: Msg, deckInfo: number) => Msg =
  cec.msgDeckStatus
export const opsDeckStatus: (msg: Msg) => number = cec.opsDeckStatus
export const msgGiveDeckStatus: (
  msg: Msg,
  reply: boolean,
  statusReq: number
) => Msg = cec.msgGiveDeckStatus
export const opsGiveDeckStatus: (msg: Msg) => number = cec.opsGiveDeckStatus
export const msgPlay: (msg: Msg, playMode: number) => Msg = cec.msgPlay
export const opsPlay: (msg: Msg) => number = cec.opsPlay
export const msgTunerDeviceStatusAnalog: (
  msg: Msg,
  recFlag: number,
  tunerDisplayInfo: number,
  anaBcastType: number,
  anaFreq: number,
  bcastSystem: number
) => Msg = cec.msgTunerDeviceStatusAnalog
export const msgTunerDeviceStatusDigital: (
  msg: Msg,
  recFlag: number,
  tunerDisplayInfo: number,
  digital: OpDigitalServiceId
) => Msg = cec.msgTunerDeviceStatusDigital
export const msgTunerDeviceStatus: (
  msg: Msg,
  tunerDevInfo: OpTunerDeviceInfo
) => Msg = cec.msgTunerDeviceStatus
export const opsTunerDeviceStatus: (msg: Msg) => OpTunerDeviceInfo =
  cec.opsTunerDeviceStatus
export const msgGiveTunerDeviceStatus: (
  msg: Msg,
  reply: boolean,
  statusReq: number
) => Msg = cec.msgGiveTunerDeviceStatus
export const opsGiveTunerDeviceStatus: (msg: Msg) => number =
  cec.opsGiveTunerDeviceStatus
export const msgSelectAnalogueService: (
  msg: Msg,
  anaBcastType: number,
  anaFreq: number,
  bcastSystem: number
) => Msg = cec.msgSelectAnalogueService
export const opsSelectAnalogueService: (
  msg: Msg
) => {
  anaBcastType: number,
  anaFreq: number,
  bcastSystem: number
} = cec.opsSelectAnalogueService
export const msgSelectDigitalService: (
  msg: Msg,
  digital: OpDigitalServiceId
) => Msg = cec.msgSelectDigitalService
export const opsSelectDigitalService: (msg: Msg) => OpDigitalServiceId =
  cec.opsSelectDigitalService
export const msgTunerStepDecrement: (msg: Msg) => Msg =
  cec.msgTunerStepDecrement
export const msgTunerStepIncrement: (msg: Msg) => Msg =
  cec.msgTunerStepIncrement
export const msgDeviceVendorId: (msg: Msg, vendorId: number) => Msg =
  cec.msgDeviceVendorId
export const opsDeviceVendorId: (msg: Msg) => number = cec.opsDeviceVendorId
export const msgGiveDeviceVendorId: (msg: Msg, reply: boolean) => Msg =
  cec.msgGiveDeviceVendorId
export const msgVendorCommand: (
  msg: Msg,
  size: number,
  vendorCmd: number[]
) => Msg = cec.msgVendorCommand
export const opsVendorCommand: (
  msg: Msg
) => {
  size: number,
  vendorCmd: number
} = cec.opsVendorCommand
export const msgVendorCommandWithId: (
  msg: Msg,
  vendorId: number,
  size: number,
  vendorCmd: number[]
) => Msg = cec.msgVendorCommandWithId
export const opsVendorCommandWithId: (
  msg: Msg
) => {
  vendorId: number,
  size: number,
  vendorCmd: number
} = cec.opsVendorCommandWithId
export const msgVendorRemoteButtonDown: (
  msg: Msg,
  size: number,
  rcCode: number[]
) => Msg = cec.msgVendorRemoteButtonDown
export const opsVendorRemoteButtonDown: (
  msg: Msg
) => {
  size: number,
  rcCode: number
} = cec.opsVendorRemoteButtonDown
export const msgVendorRemoteButtonUp: (msg: Msg) => Msg =
  cec.msgVendorRemoteButtonUp
export const msgSetOsdString: (msg: Msg, dispCtl: number, osd: string) => Msg =
  cec.msgSetOsdString
export const opsSetOsdString: (
  msg: Msg
) => {
  dispCtl: number,
  osd: string
} = cec.opsSetOsdString
export const msgSetOsdName: (msg: Msg, name: string) => Msg = cec.msgSetOsdName
export const opsSetOsdName: (msg: Msg) => string = cec.opsSetOsdName
export const msgGiveOsdName: (msg: Msg, reply: boolean) => Msg =
  cec.msgGiveOsdName
export const msgMenuStatus: (msg: Msg, menuState: number) => Msg =
  cec.msgMenuStatus
export const opsMenuStatus: (msg: Msg) => number = cec.opsMenuStatus
export const msgMenuRequest: (
  msg: Msg,
  reply: boolean,
  menuReq: number
) => Msg = cec.msgMenuRequest
export const opsMenuRequest: (msg: Msg) => number = cec.opsMenuRequest
export const msgUserControlPressed: (msg: Msg, uiCmd: OpUiCommand) => Msg =
  cec.msgUserControlPressed
export const opsUserControlPressed: (msg: Msg) => OpUiCommand =
  cec.opsUserControlPressed
export const msgUserControlReleased: (msg: Msg) => Msg =
  cec.msgUserControlReleased
export const msgReportPowerStatus: (msg: Msg, pwrState: number) => Msg =
  cec.msgReportPowerStatus
export const opsReportPowerStatus: (msg: Msg) => number =
  cec.opsReportPowerStatus
export const msgGiveDevicePowerStatus: (msg: Msg, reply: boolean) => Msg =
  cec.msgGiveDevicePowerStatus
export const msgFeatureAbort: (
  msg: Msg,
  abortMsg: number,
  reason: number
) => Msg = cec.msgFeatureAbort
export const opsFeatureAbort: (
  msg: Msg
) => {
  abortMsg: number,
  reason: number
} = cec.opsFeatureAbort
export const msgReplyFeatureAbort: (msg: Msg, reason: number) => Msg =
  cec.msgReplyFeatureAbort
export const msgAbort: (msg: Msg) => Msg = cec.msgAbort
export const msgReportAudioStatus: (
  msg: Msg,
  audMuteStatus: number,
  audVolStatus: number
) => Msg = cec.msgReportAudioStatus
export const opsReportAudioStatus: (
  msg: Msg
) => {
  audMuteStatus: number,
  audVolStatus: number
} = cec.opsReportAudioStatus
export const msgGiveAudioStatus: (msg: Msg, reply: boolean) => Msg =
  cec.msgGiveAudioStatus
export const msgSetSystemAudioMode: (msg: Msg, sysAudStatus: number) => Msg =
  cec.msgSetSystemAudioMode
export const opsSetSystemAudioMode: (msg: Msg) => number =
  cec.opsSetSystemAudioMode
export const msgSystemAudioModeRequest: (
  msg: Msg,
  reply: boolean,
  physAddr: number
) => Msg = cec.msgSystemAudioModeRequest
export const opsSystemAudioModeRequest: (msg: Msg) => number =
  cec.opsSystemAudioModeRequest
export const msgSystemAudioModeStatus: (msg: Msg, sysAudStatus: number) => Msg =
  cec.msgSystemAudioModeStatus
export const opsSystemAudioModeStatus: (msg: Msg) => number =
  cec.opsSystemAudioModeStatus
export const msgGiveSystemAudioModeStatus: (msg: Msg, reply: boolean) => Msg =
  cec.msgGiveSystemAudioModeStatus
export const msgReportShortAudioDescriptor: (
  msg: Msg,
  numDescriptors: number,
  descriptors: number[]
) => Msg = cec.msgReportShortAudioDescriptor
export const opsReportShortAudioDescriptor: (
  msg: Msg
) => {
  numDescriptors: number,
  descriptors: number
} = cec.opsReportShortAudioDescriptor
export const msgRequestShortAudioDescriptor: (
  msg: Msg,
  reply: boolean,
  numDescriptors: number,
  audioFormatId: number[],
  audioFormatCode: number[]
) => Msg = cec.msgRequestShortAudioDescriptor
export const opsRequestShortAudioDescriptor: (
  msg: Msg
) => {
  numDescriptors: number,
  audioFormatId: number,
  audioFormatCode: number
} = cec.opsRequestShortAudioDescriptor
export const msgSetAudioRate: (msg: Msg, audioRate: number) => Msg =
  cec.msgSetAudioRate
export const opsSetAudioRate: (msg: Msg) => number = cec.opsSetAudioRate
export const msgReportArcInitiated: (msg: Msg) => Msg =
  cec.msgReportArcInitiated
export const msgInitiateArc: (msg: Msg, reply: boolean) => Msg =
  cec.msgInitiateArc
export const msgRequestArcInitiation: (msg: Msg, reply: boolean) => Msg =
  cec.msgRequestArcInitiation
export const msgReportArcTerminated: (msg: Msg) => Msg =
  cec.msgReportArcTerminated
export const msgTerminateArc: (msg: Msg, reply: boolean) => Msg =
  cec.msgTerminateArc
export const msgRequestArcTermination: (msg: Msg, reply: boolean) => Msg =
  cec.msgRequestArcTermination
export const msgReportCurrentLatency: (
  msg: Msg,
  physAddr: number,
  videoLatency: number,
  lowLatencyMode: number,
  audioOutCompensated: number,
  audioOutDelay: number
) => Msg = cec.msgReportCurrentLatency
export const opsReportCurrentLatency: (
  msg: Msg
) => {
  physAddr: number,
  videoLatency: number,
  lowLatencyMode: number,
  audioOutCompensated: number,
  audioOutDelay: number
} = cec.opsReportCurrentLatency
export const msgRequestCurrentLatency: (
  msg: Msg,
  reply: boolean,
  physAddr: number
) => Msg = cec.msgRequestCurrentLatency
export const opsRequestCurrentLatency: (msg: Msg) => number =
  cec.opsRequestCurrentLatency
export const msgCdcHecInquireState: (
  msg: Msg,
  physAddr1: number,
  physAddr2: number
) => Msg = cec.msgCdcHecInquireState
export const opsCdcHecInquireState: (
  msg: Msg
) => {
  physAddr: number,
  physAddr1: number,
  physAddr2: number
} = cec.opsCdcHecInquireState
export const msgCdcHecReportState: (
  msg: Msg,
  targetPhysAddr: number,
  hecFuncState: number,
  hostFuncState: number,
  encFuncState: number,
  cdcErrcode: number,
  hasField: boolean,
  hecField: number
) => Msg = cec.msgCdcHecReportState
export const opsCdcHecReportState: (
  msg: Msg
) => {
  physAddr: number,
  targetPhysAddr: number,
  hecFuncState: number,
  hostFuncState: number,
  encFuncState: number,
  cdcErrcode: number,
  hasField: boolean,
  hecField: number
} = cec.opsCdcHecReportState
export const msgCdcHecSetState: (
  msg: Msg,
  physAddr1: number,
  physAddr2: number,
  hecSetState: number,
  physAddr3: number,
  physAddr4: number,
  physAddr5: number
) => Msg = cec.msgCdcHecSetState
export const opsCdcHecSetState: (
  msg: Msg
) => {
  physAddr: number,
  physAddr1: number,
  physAddr2: number,
  hecSetState: number,
  physAddr3: number,
  physAddr4: number,
  physAddr5: number
} = cec.opsCdcHecSetState
export const msgCdcHecSetStateAdjacent: (
  msg: Msg,
  physAddr1: number,
  hecSetState: number
) => Msg = cec.msgCdcHecSetStateAdjacent
export const opsCdcHecSetStateAdjacent: (
  msg: Msg
) => {
  physAddr: number,
  physAddr1: number,
  hecSetState: number
} = cec.opsCdcHecSetStateAdjacent
export const msgCdcHecRequestDeactivation: (
  msg: Msg,
  physAddr1: number,
  physAddr2: number,
  physAddr3: number
) => Msg = cec.msgCdcHecRequestDeactivation
export const opsCdcHecRequestDeactivation: (
  msg: Msg
) => {
  physAddr: number,
  physAddr1: number,
  physAddr2: number,
  physAddr3: number
} = cec.opsCdcHecRequestDeactivation
export const msgCdcHecNotifyAlive: (msg: Msg) => Msg = cec.msgCdcHecNotifyAlive
export const opsCdcHecNotifyAlive: (msg: Msg) => number =
  cec.opsCdcHecNotifyAlive
export const msgCdcHecDiscover: (msg: Msg) => Msg = cec.msgCdcHecDiscover
export const opsCdcHecDiscover: (msg: Msg) => number = cec.opsCdcHecDiscover
export const msgCdcHpdSetState: (
  msg: Msg,
  inputPort: number,
  hpdState: number
) => Msg = cec.msgCdcHpdSetState
export const opsCdcHpdSetState: (
  msg: Msg
) => {
  physAddr: number,
  inputPort: number,
  hpdState: number
} = cec.opsCdcHpdSetState
export const msgCdcHpdReportState: (
  msg: Msg,
  hpdState: number,
  hpdError: number
) => Msg = cec.msgCdcHpdReportState
export const opsCdcHpdReportState: (
  msg: Msg
) => {
  physAddr: number,
  hpdState: number,
  hpdError: number
} = cec.opsCdcHpdReportState
export const MAX_MSG_SIZE: number = cec.MAX_MSG_SIZE
export const MSG_FL_REPLY_TO_FOLLOWERS: number = cec.MSG_FL_REPLY_TO_FOLLOWERS
export const TX_STATUS_OK: number = cec.TX_STATUS_OK
export const TX_STATUS_ARB_LOST: number = cec.TX_STATUS_ARB_LOST
export const TX_STATUS_NACK: number = cec.TX_STATUS_NACK
export const TX_STATUS_LOW_DRIVE: number = cec.TX_STATUS_LOW_DRIVE
export const TX_STATUS_ERROR: number = cec.TX_STATUS_ERROR
export const TX_STATUS_MAX_RETRIES: number = cec.TX_STATUS_MAX_RETRIES
export const RX_STATUS_OK: number = cec.RX_STATUS_OK
export const RX_STATUS_TIMEOUT: number = cec.RX_STATUS_TIMEOUT
export const RX_STATUS_FEATURE_ABORT: number = cec.RX_STATUS_FEATURE_ABORT
export const LOG_ADDR_INVALID: number = cec.LOG_ADDR_INVALID
export const PHYS_ADDR_INVALID: number = cec.PHYS_ADDR_INVALID
export const MAX_LOG_ADDRS: number = cec.MAX_LOG_ADDRS
export const LOG_ADDR_TV: number = cec.LOG_ADDR_TV
export const LOG_ADDR_RECORD_1: number = cec.LOG_ADDR_RECORD_1
export const LOG_ADDR_RECORD_2: number = cec.LOG_ADDR_RECORD_2
export const LOG_ADDR_TUNER_1: number = cec.LOG_ADDR_TUNER_1
export const LOG_ADDR_PLAYBACK_1: number = cec.LOG_ADDR_PLAYBACK_1
export const LOG_ADDR_AUDIOSYSTEM: number = cec.LOG_ADDR_AUDIOSYSTEM
export const LOG_ADDR_TUNER_2: number = cec.LOG_ADDR_TUNER_2
export const LOG_ADDR_TUNER_3: number = cec.LOG_ADDR_TUNER_3
export const LOG_ADDR_PLAYBACK_2: number = cec.LOG_ADDR_PLAYBACK_2
export const LOG_ADDR_RECORD_3: number = cec.LOG_ADDR_RECORD_3
export const LOG_ADDR_TUNER_4: number = cec.LOG_ADDR_TUNER_4
export const LOG_ADDR_PLAYBACK_3: number = cec.LOG_ADDR_PLAYBACK_3
export const LOG_ADDR_BACKUP_1: number = cec.LOG_ADDR_BACKUP_1
export const LOG_ADDR_BACKUP_2: number = cec.LOG_ADDR_BACKUP_2
export const LOG_ADDR_SPECIFIC: number = cec.LOG_ADDR_SPECIFIC
export const LOG_ADDR_UNREGISTERED: number = cec.LOG_ADDR_UNREGISTERED
export const LOG_ADDR_BROADCAST: number = cec.LOG_ADDR_BROADCAST
export const LOG_ADDR_TYPE_TV: number = cec.LOG_ADDR_TYPE_TV
export const LOG_ADDR_TYPE_RECORD: number = cec.LOG_ADDR_TYPE_RECORD
export const LOG_ADDR_TYPE_TUNER: number = cec.LOG_ADDR_TYPE_TUNER
export const LOG_ADDR_TYPE_PLAYBACK: number = cec.LOG_ADDR_TYPE_PLAYBACK
export const LOG_ADDR_TYPE_AUDIOSYSTEM: number = cec.LOG_ADDR_TYPE_AUDIOSYSTEM
export const LOG_ADDR_TYPE_SPECIFIC: number = cec.LOG_ADDR_TYPE_SPECIFIC
export const LOG_ADDR_TYPE_UNREGISTERED: number = cec.LOG_ADDR_TYPE_UNREGISTERED
export const LOG_ADDR_MASK_TV: number = cec.LOG_ADDR_MASK_TV
export const LOG_ADDR_MASK_RECORD: number = cec.LOG_ADDR_MASK_RECORD
export const LOG_ADDR_MASK_TUNER: number = cec.LOG_ADDR_MASK_TUNER
export const LOG_ADDR_MASK_PLAYBACK: number = cec.LOG_ADDR_MASK_PLAYBACK
export const LOG_ADDR_MASK_AUDIOSYSTEM: number = cec.LOG_ADDR_MASK_AUDIOSYSTEM
export const LOG_ADDR_MASK_BACKUP: number = cec.LOG_ADDR_MASK_BACKUP
export const LOG_ADDR_MASK_SPECIFIC: number = cec.LOG_ADDR_MASK_SPECIFIC
export const LOG_ADDR_MASK_UNREGISTERED: number = cec.LOG_ADDR_MASK_UNREGISTERED
export const VENDOR_ID_NONE: number = cec.VENDOR_ID_NONE
export const MODE_NO_INITIATOR: number = cec.MODE_NO_INITIATOR
export const MODE_INITIATOR: number = cec.MODE_INITIATOR
export const MODE_EXCL_INITIATOR: number = cec.MODE_EXCL_INITIATOR
export const MODE_INITIATOR_MSK: number = cec.MODE_INITIATOR_MSK
export const MODE_NO_FOLLOWER: number = cec.MODE_NO_FOLLOWER
export const MODE_FOLLOWER: number = cec.MODE_FOLLOWER
export const MODE_EXCL_FOLLOWER: number = cec.MODE_EXCL_FOLLOWER
export const MODE_EXCL_FOLLOWER_PASSTHRU: number =
  cec.MODE_EXCL_FOLLOWER_PASSTHRU
export const MODE_MONITOR_PIN: number = cec.MODE_MONITOR_PIN
export const MODE_MONITOR: number = cec.MODE_MONITOR
export const MODE_MONITOR_ALL: number = cec.MODE_MONITOR_ALL
export const MODE_FOLLOWER_MSK: number = cec.MODE_FOLLOWER_MSK
export const CAP_PHYS_ADDR: number = cec.CAP_PHYS_ADDR
export const CAP_LOG_ADDRS: number = cec.CAP_LOG_ADDRS
export const CAP_TRANSMIT: number = cec.CAP_TRANSMIT
export const CAP_PASSTHROUGH: number = cec.CAP_PASSTHROUGH
export const CAP_RC: number = cec.CAP_RC
export const CAP_MONITOR_ALL: number = cec.CAP_MONITOR_ALL
export const CAP_NEEDS_HPD: number = cec.CAP_NEEDS_HPD
export const CAP_MONITOR_PIN: number = cec.CAP_MONITOR_PIN
export const LOG_ADDRS_FL_ALLOW_UNREG_FALLBACK: number =
  cec.LOG_ADDRS_FL_ALLOW_UNREG_FALLBACK
export const LOG_ADDRS_FL_ALLOW_RC_PASSTHRU: number =
  cec.LOG_ADDRS_FL_ALLOW_RC_PASSTHRU
export const LOG_ADDRS_FL_CDC_ONLY: number = cec.LOG_ADDRS_FL_CDC_ONLY
export const EVENT_STATE_CHANGE: number = cec.EVENT_STATE_CHANGE
export const EVENT_LOST_MSGS: number = cec.EVENT_LOST_MSGS
export const EVENT_PIN_CEC_LOW: number = cec.EVENT_PIN_CEC_LOW
export const EVENT_PIN_CEC_HIGH: number = cec.EVENT_PIN_CEC_HIGH
export const EVENT_PIN_HPD_LOW: number = cec.EVENT_PIN_HPD_LOW
export const EVENT_PIN_HPD_HIGH: number = cec.EVENT_PIN_HPD_HIGH
export const EVENT_PIN_5V_LOW: number = cec.EVENT_PIN_5V_LOW
export const EVENT_PIN_5V_HIGH: number = cec.EVENT_PIN_5V_HIGH
export const EVENT_FL_INITIAL_STATE: number = cec.EVENT_FL_INITIAL_STATE
export const EVENT_FL_DROPPED_EVENTS: number = cec.EVENT_FL_DROPPED_EVENTS
export const MSG_ACTIVE_SOURCE: number = cec.MSG_ACTIVE_SOURCE
export const MSG_IMAGE_VIEW_ON: number = cec.MSG_IMAGE_VIEW_ON
export const MSG_TEXT_VIEW_ON: number = cec.MSG_TEXT_VIEW_ON
export const MSG_INACTIVE_SOURCE: number = cec.MSG_INACTIVE_SOURCE
export const MSG_REQUEST_ACTIVE_SOURCE: number = cec.MSG_REQUEST_ACTIVE_SOURCE
export const MSG_ROUTING_CHANGE: number = cec.MSG_ROUTING_CHANGE
export const MSG_ROUTING_INFORMATION: number = cec.MSG_ROUTING_INFORMATION
export const MSG_SET_STREAM_PATH: number = cec.MSG_SET_STREAM_PATH
export const MSG_STANDBY: number = cec.MSG_STANDBY
export const MSG_RECORD_OFF: number = cec.MSG_RECORD_OFF
export const MSG_RECORD_ON: number = cec.MSG_RECORD_ON
export const OP_RECORD_SRC_OWN: number = cec.OP_RECORD_SRC_OWN
export const OP_RECORD_SRC_DIGITAL: number = cec.OP_RECORD_SRC_DIGITAL
export const OP_RECORD_SRC_ANALOG: number = cec.OP_RECORD_SRC_ANALOG
export const OP_RECORD_SRC_EXT_PLUG: number = cec.OP_RECORD_SRC_EXT_PLUG
export const OP_RECORD_SRC_EXT_PHYS_ADDR: number =
  cec.OP_RECORD_SRC_EXT_PHYS_ADDR
export const OP_SERVICE_ID_METHOD_BY_DIG_ID: number =
  cec.OP_SERVICE_ID_METHOD_BY_DIG_ID
export const OP_SERVICE_ID_METHOD_BY_CHANNEL: number =
  cec.OP_SERVICE_ID_METHOD_BY_CHANNEL
export const OP_DIG_SERVICE_BCAST_SYSTEM_ARIB_GEN: number =
  cec.OP_DIG_SERVICE_BCAST_SYSTEM_ARIB_GEN
export const OP_DIG_SERVICE_BCAST_SYSTEM_ATSC_GEN: number =
  cec.OP_DIG_SERVICE_BCAST_SYSTEM_ATSC_GEN
export const OP_DIG_SERVICE_BCAST_SYSTEM_DVB_GEN: number =
  cec.OP_DIG_SERVICE_BCAST_SYSTEM_DVB_GEN
export const OP_DIG_SERVICE_BCAST_SYSTEM_ARIB_BS: number =
  cec.OP_DIG_SERVICE_BCAST_SYSTEM_ARIB_BS
export const OP_DIG_SERVICE_BCAST_SYSTEM_ARIB_CS: number =
  cec.OP_DIG_SERVICE_BCAST_SYSTEM_ARIB_CS
export const OP_DIG_SERVICE_BCAST_SYSTEM_ARIB_T: number =
  cec.OP_DIG_SERVICE_BCAST_SYSTEM_ARIB_T
export const OP_DIG_SERVICE_BCAST_SYSTEM_ATSC_CABLE: number =
  cec.OP_DIG_SERVICE_BCAST_SYSTEM_ATSC_CABLE
export const OP_DIG_SERVICE_BCAST_SYSTEM_ATSC_SAT: number =
  cec.OP_DIG_SERVICE_BCAST_SYSTEM_ATSC_SAT
export const OP_DIG_SERVICE_BCAST_SYSTEM_ATSC_T: number =
  cec.OP_DIG_SERVICE_BCAST_SYSTEM_ATSC_T
export const OP_DIG_SERVICE_BCAST_SYSTEM_DVB_C: number =
  cec.OP_DIG_SERVICE_BCAST_SYSTEM_DVB_C
export const OP_DIG_SERVICE_BCAST_SYSTEM_DVB_S: number =
  cec.OP_DIG_SERVICE_BCAST_SYSTEM_DVB_S
export const OP_DIG_SERVICE_BCAST_SYSTEM_DVB_S2: number =
  cec.OP_DIG_SERVICE_BCAST_SYSTEM_DVB_S2
export const OP_DIG_SERVICE_BCAST_SYSTEM_DVB_T: number =
  cec.OP_DIG_SERVICE_BCAST_SYSTEM_DVB_T
export const OP_ANA_BCAST_TYPE_CABLE: number = cec.OP_ANA_BCAST_TYPE_CABLE
export const OP_ANA_BCAST_TYPE_SATELLITE: number =
  cec.OP_ANA_BCAST_TYPE_SATELLITE
export const OP_ANA_BCAST_TYPE_TERRESTRIAL: number =
  cec.OP_ANA_BCAST_TYPE_TERRESTRIAL
export const OP_BCAST_SYSTEM_PAL_BG: number = cec.OP_BCAST_SYSTEM_PAL_BG
export const OP_BCAST_SYSTEM_SECAM_LQ: number = cec.OP_BCAST_SYSTEM_SECAM_LQ
export const OP_BCAST_SYSTEM_PAL_M: number = cec.OP_BCAST_SYSTEM_PAL_M
export const OP_BCAST_SYSTEM_NTSC_M: number = cec.OP_BCAST_SYSTEM_NTSC_M
export const OP_BCAST_SYSTEM_PAL_I: number = cec.OP_BCAST_SYSTEM_PAL_I
export const OP_BCAST_SYSTEM_SECAM_DK: number = cec.OP_BCAST_SYSTEM_SECAM_DK
export const OP_BCAST_SYSTEM_SECAM_BG: number = cec.OP_BCAST_SYSTEM_SECAM_BG
export const OP_BCAST_SYSTEM_SECAM_L: number = cec.OP_BCAST_SYSTEM_SECAM_L
export const OP_BCAST_SYSTEM_PAL_DK: number = cec.OP_BCAST_SYSTEM_PAL_DK
export const OP_BCAST_SYSTEM_OTHER: number = cec.OP_BCAST_SYSTEM_OTHER
export const OP_CHANNEL_NUMBER_FMT_1_PART: number =
  cec.OP_CHANNEL_NUMBER_FMT_1_PART
export const OP_CHANNEL_NUMBER_FMT_2_PART: number =
  cec.OP_CHANNEL_NUMBER_FMT_2_PART
export const MSG_RECORD_STATUS: number = cec.MSG_RECORD_STATUS
export const OP_RECORD_STATUS_CUR_SRC: number = cec.OP_RECORD_STATUS_CUR_SRC
export const OP_RECORD_STATUS_DIG_SERVICE: number =
  cec.OP_RECORD_STATUS_DIG_SERVICE
export const OP_RECORD_STATUS_ANA_SERVICE: number =
  cec.OP_RECORD_STATUS_ANA_SERVICE
export const OP_RECORD_STATUS_EXT_INPUT: number = cec.OP_RECORD_STATUS_EXT_INPUT
export const OP_RECORD_STATUS_NO_DIG_SERVICE: number =
  cec.OP_RECORD_STATUS_NO_DIG_SERVICE
export const OP_RECORD_STATUS_NO_ANA_SERVICE: number =
  cec.OP_RECORD_STATUS_NO_ANA_SERVICE
export const OP_RECORD_STATUS_NO_SERVICE: number =
  cec.OP_RECORD_STATUS_NO_SERVICE
export const OP_RECORD_STATUS_INVALID_EXT_PLUG: number =
  cec.OP_RECORD_STATUS_INVALID_EXT_PLUG
export const OP_RECORD_STATUS_INVALID_EXT_PHYS_ADDR: number =
  cec.OP_RECORD_STATUS_INVALID_EXT_PHYS_ADDR
export const OP_RECORD_STATUS_UNSUP_CA: number = cec.OP_RECORD_STATUS_UNSUP_CA
export const OP_RECORD_STATUS_NO_CA_ENTITLEMENTS: number =
  cec.OP_RECORD_STATUS_NO_CA_ENTITLEMENTS
export const OP_RECORD_STATUS_CANT_COPY_SRC: number =
  cec.OP_RECORD_STATUS_CANT_COPY_SRC
export const OP_RECORD_STATUS_NO_MORE_COPIES: number =
  cec.OP_RECORD_STATUS_NO_MORE_COPIES
export const OP_RECORD_STATUS_NO_MEDIA: number = cec.OP_RECORD_STATUS_NO_MEDIA
export const OP_RECORD_STATUS_PLAYING: number = cec.OP_RECORD_STATUS_PLAYING
export const OP_RECORD_STATUS_ALREADY_RECORDING: number =
  cec.OP_RECORD_STATUS_ALREADY_RECORDING
export const OP_RECORD_STATUS_MEDIA_PROT: number =
  cec.OP_RECORD_STATUS_MEDIA_PROT
export const OP_RECORD_STATUS_NO_SIGNAL: number = cec.OP_RECORD_STATUS_NO_SIGNAL
export const OP_RECORD_STATUS_MEDIA_PROBLEM: number =
  cec.OP_RECORD_STATUS_MEDIA_PROBLEM
export const OP_RECORD_STATUS_NO_SPACE: number = cec.OP_RECORD_STATUS_NO_SPACE
export const OP_RECORD_STATUS_PARENTAL_LOCK: number =
  cec.OP_RECORD_STATUS_PARENTAL_LOCK
export const OP_RECORD_STATUS_TERMINATED_OK: number =
  cec.OP_RECORD_STATUS_TERMINATED_OK
export const OP_RECORD_STATUS_ALREADY_TERM: number =
  cec.OP_RECORD_STATUS_ALREADY_TERM
export const OP_RECORD_STATUS_OTHER: number = cec.OP_RECORD_STATUS_OTHER
export const MSG_RECORD_TV_SCREEN: number = cec.MSG_RECORD_TV_SCREEN
export const MSG_CLEAR_ANALOGUE_TIMER: number = cec.MSG_CLEAR_ANALOGUE_TIMER
export const OP_REC_SEQ_SUNDAY: number = cec.OP_REC_SEQ_SUNDAY
export const OP_REC_SEQ_MONDAY: number = cec.OP_REC_SEQ_MONDAY
export const OP_REC_SEQ_TUESDAY: number = cec.OP_REC_SEQ_TUESDAY
export const OP_REC_SEQ_WEDNESDAY: number = cec.OP_REC_SEQ_WEDNESDAY
export const OP_REC_SEQ_THURSDAY: number = cec.OP_REC_SEQ_THURSDAY
export const OP_REC_SEQ_FRIDAY: number = cec.OP_REC_SEQ_FRIDAY
export const OP_REC_SEQ_SATERDAY: number = cec.OP_REC_SEQ_SATERDAY
export const OP_REC_SEQ_ONCE_ONLY: number = cec.OP_REC_SEQ_ONCE_ONLY
export const MSG_CLEAR_DIGITAL_TIMER: number = cec.MSG_CLEAR_DIGITAL_TIMER
export const MSG_CLEAR_EXT_TIMER: number = cec.MSG_CLEAR_EXT_TIMER
export const OP_EXT_SRC_PLUG: number = cec.OP_EXT_SRC_PLUG
export const OP_EXT_SRC_PHYS_ADDR: number = cec.OP_EXT_SRC_PHYS_ADDR
export const MSG_SET_ANALOGUE_TIMER: number = cec.MSG_SET_ANALOGUE_TIMER
export const MSG_SET_DIGITAL_TIMER: number = cec.MSG_SET_DIGITAL_TIMER
export const MSG_SET_EXT_TIMER: number = cec.MSG_SET_EXT_TIMER
export const MSG_SET_TIMER_PROGRAM_TITLE: number =
  cec.MSG_SET_TIMER_PROGRAM_TITLE
export const MSG_TIMER_CLEARED_STATUS: number = cec.MSG_TIMER_CLEARED_STATUS
export const OP_TIMER_CLR_STAT_RECORDING: number =
  cec.OP_TIMER_CLR_STAT_RECORDING
export const OP_TIMER_CLR_STAT_NO_MATCHING: number =
  cec.OP_TIMER_CLR_STAT_NO_MATCHING
export const OP_TIMER_CLR_STAT_NO_INFO: number = cec.OP_TIMER_CLR_STAT_NO_INFO
export const OP_TIMER_CLR_STAT_CLEARED: number = cec.OP_TIMER_CLR_STAT_CLEARED
export const MSG_TIMER_STATUS: number = cec.MSG_TIMER_STATUS
export const OP_TIMER_OVERLAP_WARNING_NO_OVERLAP: number =
  cec.OP_TIMER_OVERLAP_WARNING_NO_OVERLAP
export const OP_TIMER_OVERLAP_WARNING_OVERLAP: number =
  cec.OP_TIMER_OVERLAP_WARNING_OVERLAP
export const OP_MEDIA_INFO_UNPROT_MEDIA: number = cec.OP_MEDIA_INFO_UNPROT_MEDIA
export const OP_MEDIA_INFO_PROT_MEDIA: number = cec.OP_MEDIA_INFO_PROT_MEDIA
export const OP_MEDIA_INFO_NO_MEDIA: number = cec.OP_MEDIA_INFO_NO_MEDIA
export const OP_PROG_IND_NOT_PROGRAMMED: number = cec.OP_PROG_IND_NOT_PROGRAMMED
export const OP_PROG_IND_PROGRAMMED: number = cec.OP_PROG_IND_PROGRAMMED
export const OP_PROG_INFO_ENOUGH_SPACE: number = cec.OP_PROG_INFO_ENOUGH_SPACE
export const OP_PROG_INFO_NOT_ENOUGH_SPACE: number =
  cec.OP_PROG_INFO_NOT_ENOUGH_SPACE
export const OP_PROG_INFO_MIGHT_NOT_BE_ENOUGH_SPACE: number =
  cec.OP_PROG_INFO_MIGHT_NOT_BE_ENOUGH_SPACE
export const OP_PROG_INFO_NONE_AVAILABLE: number =
  cec.OP_PROG_INFO_NONE_AVAILABLE
export const OP_PROG_ERROR_NO_FREE_TIMER: number =
  cec.OP_PROG_ERROR_NO_FREE_TIMER
export const OP_PROG_ERROR_DATE_OUT_OF_RANGE: number =
  cec.OP_PROG_ERROR_DATE_OUT_OF_RANGE
export const OP_PROG_ERROR_REC_SEQ_ERROR: number =
  cec.OP_PROG_ERROR_REC_SEQ_ERROR
export const OP_PROG_ERROR_INV_EXT_PLUG: number = cec.OP_PROG_ERROR_INV_EXT_PLUG
export const OP_PROG_ERROR_INV_EXT_PHYS_ADDR: number =
  cec.OP_PROG_ERROR_INV_EXT_PHYS_ADDR
export const OP_PROG_ERROR_CA_UNSUPP: number = cec.OP_PROG_ERROR_CA_UNSUPP
export const OP_PROG_ERROR_INSUF_CA_ENTITLEMENTS: number =
  cec.OP_PROG_ERROR_INSUF_CA_ENTITLEMENTS
export const OP_PROG_ERROR_RESOLUTION_UNSUPP: number =
  cec.OP_PROG_ERROR_RESOLUTION_UNSUPP
export const OP_PROG_ERROR_PARENTAL_LOCK: number =
  cec.OP_PROG_ERROR_PARENTAL_LOCK
export const OP_PROG_ERROR_CLOCK_FAILURE: number =
  cec.OP_PROG_ERROR_CLOCK_FAILURE
export const OP_PROG_ERROR_DUPLICATE: number = cec.OP_PROG_ERROR_DUPLICATE
export const MSG_CEC_VERSION: number = cec.MSG_CEC_VERSION
export const OP_CEC_VERSION_1_3A: number = cec.OP_CEC_VERSION_1_3A
export const OP_CEC_VERSION_1_4: number = cec.OP_CEC_VERSION_1_4
export const OP_CEC_VERSION_2_0: number = cec.OP_CEC_VERSION_2_0
export const MSG_GET_CEC_VERSION: number = cec.MSG_GET_CEC_VERSION
export const MSG_GIVE_PHYSICAL_ADDR: number = cec.MSG_GIVE_PHYSICAL_ADDR
export const MSG_GET_MENU_LANGUAGE: number = cec.MSG_GET_MENU_LANGUAGE
export const MSG_REPORT_PHYSICAL_ADDR: number = cec.MSG_REPORT_PHYSICAL_ADDR
export const OP_PRIM_DEVTYPE_TV: number = cec.OP_PRIM_DEVTYPE_TV
export const OP_PRIM_DEVTYPE_RECORD: number = cec.OP_PRIM_DEVTYPE_RECORD
export const OP_PRIM_DEVTYPE_TUNER: number = cec.OP_PRIM_DEVTYPE_TUNER
export const OP_PRIM_DEVTYPE_PLAYBACK: number = cec.OP_PRIM_DEVTYPE_PLAYBACK
export const OP_PRIM_DEVTYPE_AUDIOSYSTEM: number =
  cec.OP_PRIM_DEVTYPE_AUDIOSYSTEM
export const OP_PRIM_DEVTYPE_SWITCH: number = cec.OP_PRIM_DEVTYPE_SWITCH
export const OP_PRIM_DEVTYPE_PROCESSOR: number = cec.OP_PRIM_DEVTYPE_PROCESSOR
export const MSG_SET_MENU_LANGUAGE: number = cec.MSG_SET_MENU_LANGUAGE
export const MSG_REPORT_FEATURES: number = cec.MSG_REPORT_FEATURES
export const OP_ALL_DEVTYPE_TV: number = cec.OP_ALL_DEVTYPE_TV
export const OP_ALL_DEVTYPE_RECORD: number = cec.OP_ALL_DEVTYPE_RECORD
export const OP_ALL_DEVTYPE_TUNER: number = cec.OP_ALL_DEVTYPE_TUNER
export const OP_ALL_DEVTYPE_PLAYBACK: number = cec.OP_ALL_DEVTYPE_PLAYBACK
export const OP_ALL_DEVTYPE_AUDIOSYSTEM: number = cec.OP_ALL_DEVTYPE_AUDIOSYSTEM
export const OP_ALL_DEVTYPE_SWITCH: number = cec.OP_ALL_DEVTYPE_SWITCH
export const OP_FEAT_EXT: number = cec.OP_FEAT_EXT
export const OP_FEAT_RC_TV_PROFILE_NONE: number = cec.OP_FEAT_RC_TV_PROFILE_NONE
export const OP_FEAT_RC_TV_PROFILE_1: number = cec.OP_FEAT_RC_TV_PROFILE_1
export const OP_FEAT_RC_TV_PROFILE_2: number = cec.OP_FEAT_RC_TV_PROFILE_2
export const OP_FEAT_RC_TV_PROFILE_3: number = cec.OP_FEAT_RC_TV_PROFILE_3
export const OP_FEAT_RC_TV_PROFILE_4: number = cec.OP_FEAT_RC_TV_PROFILE_4
export const OP_FEAT_RC_SRC_HAS_DEV_ROOT_MENU: number =
  cec.OP_FEAT_RC_SRC_HAS_DEV_ROOT_MENU
export const OP_FEAT_RC_SRC_HAS_DEV_SETUP_MENU: number =
  cec.OP_FEAT_RC_SRC_HAS_DEV_SETUP_MENU
export const OP_FEAT_RC_SRC_HAS_CONTENTS_MENU: number =
  cec.OP_FEAT_RC_SRC_HAS_CONTENTS_MENU
export const OP_FEAT_RC_SRC_HAS_MEDIA_TOP_MENU: number =
  cec.OP_FEAT_RC_SRC_HAS_MEDIA_TOP_MENU
export const OP_FEAT_RC_SRC_HAS_MEDIA_CONTEXT_MENU: number =
  cec.OP_FEAT_RC_SRC_HAS_MEDIA_CONTEXT_MENU
export const OP_FEAT_DEV_HAS_RECORD_TV_SCREEN: number =
  cec.OP_FEAT_DEV_HAS_RECORD_TV_SCREEN
export const OP_FEAT_DEV_HAS_SET_OSD_STRING: number =
  cec.OP_FEAT_DEV_HAS_SET_OSD_STRING
export const OP_FEAT_DEV_HAS_DECK_CONTROL: number =
  cec.OP_FEAT_DEV_HAS_DECK_CONTROL
export const OP_FEAT_DEV_HAS_SET_AUDIO_RATE: number =
  cec.OP_FEAT_DEV_HAS_SET_AUDIO_RATE
export const OP_FEAT_DEV_SINK_HAS_ARC_TX: number =
  cec.OP_FEAT_DEV_SINK_HAS_ARC_TX
export const OP_FEAT_DEV_SOURCE_HAS_ARC_RX: number =
  cec.OP_FEAT_DEV_SOURCE_HAS_ARC_RX
export const MSG_GIVE_FEATURES: number = cec.MSG_GIVE_FEATURES
export const MSG_DECK_CONTROL: number = cec.MSG_DECK_CONTROL
export const OP_DECK_CTL_MODE_SKIP_FWD: number = cec.OP_DECK_CTL_MODE_SKIP_FWD
export const OP_DECK_CTL_MODE_SKIP_REV: number = cec.OP_DECK_CTL_MODE_SKIP_REV
export const OP_DECK_CTL_MODE_STOP: number = cec.OP_DECK_CTL_MODE_STOP
export const OP_DECK_CTL_MODE_EJECT: number = cec.OP_DECK_CTL_MODE_EJECT
export const MSG_DECK_STATUS: number = cec.MSG_DECK_STATUS
export const OP_DECK_INFO_PLAY: number = cec.OP_DECK_INFO_PLAY
export const OP_DECK_INFO_RECORD: number = cec.OP_DECK_INFO_RECORD
export const OP_DECK_INFO_PLAY_REV: number = cec.OP_DECK_INFO_PLAY_REV
export const OP_DECK_INFO_STILL: number = cec.OP_DECK_INFO_STILL
export const OP_DECK_INFO_SLOW: number = cec.OP_DECK_INFO_SLOW
export const OP_DECK_INFO_SLOW_REV: number = cec.OP_DECK_INFO_SLOW_REV
export const OP_DECK_INFO_FAST_FWD: number = cec.OP_DECK_INFO_FAST_FWD
export const OP_DECK_INFO_FAST_REV: number = cec.OP_DECK_INFO_FAST_REV
export const OP_DECK_INFO_NO_MEDIA: number = cec.OP_DECK_INFO_NO_MEDIA
export const OP_DECK_INFO_STOP: number = cec.OP_DECK_INFO_STOP
export const OP_DECK_INFO_SKIP_FWD: number = cec.OP_DECK_INFO_SKIP_FWD
export const OP_DECK_INFO_SKIP_REV: number = cec.OP_DECK_INFO_SKIP_REV
export const OP_DECK_INFO_INDEX_SEARCH_FWD: number =
  cec.OP_DECK_INFO_INDEX_SEARCH_FWD
export const OP_DECK_INFO_INDEX_SEARCH_REV: number =
  cec.OP_DECK_INFO_INDEX_SEARCH_REV
export const OP_DECK_INFO_OTHER: number = cec.OP_DECK_INFO_OTHER
export const MSG_GIVE_DECK_STATUS: number = cec.MSG_GIVE_DECK_STATUS
export const OP_STATUS_REQ_ON: number = cec.OP_STATUS_REQ_ON
export const OP_STATUS_REQ_OFF: number = cec.OP_STATUS_REQ_OFF
export const OP_STATUS_REQ_ONCE: number = cec.OP_STATUS_REQ_ONCE
export const MSG_PLAY: number = cec.MSG_PLAY
export const OP_PLAY_MODE_PLAY_FWD: number = cec.OP_PLAY_MODE_PLAY_FWD
export const OP_PLAY_MODE_PLAY_REV: number = cec.OP_PLAY_MODE_PLAY_REV
export const OP_PLAY_MODE_PLAY_STILL: number = cec.OP_PLAY_MODE_PLAY_STILL
export const OP_PLAY_MODE_PLAY_FAST_FWD_MIN: number =
  cec.OP_PLAY_MODE_PLAY_FAST_FWD_MIN
export const OP_PLAY_MODE_PLAY_FAST_FWD_MED: number =
  cec.OP_PLAY_MODE_PLAY_FAST_FWD_MED
export const OP_PLAY_MODE_PLAY_FAST_FWD_MAX: number =
  cec.OP_PLAY_MODE_PLAY_FAST_FWD_MAX
export const OP_PLAY_MODE_PLAY_FAST_REV_MIN: number =
  cec.OP_PLAY_MODE_PLAY_FAST_REV_MIN
export const OP_PLAY_MODE_PLAY_FAST_REV_MED: number =
  cec.OP_PLAY_MODE_PLAY_FAST_REV_MED
export const OP_PLAY_MODE_PLAY_FAST_REV_MAX: number =
  cec.OP_PLAY_MODE_PLAY_FAST_REV_MAX
export const OP_PLAY_MODE_PLAY_SLOW_FWD_MIN: number =
  cec.OP_PLAY_MODE_PLAY_SLOW_FWD_MIN
export const OP_PLAY_MODE_PLAY_SLOW_FWD_MED: number =
  cec.OP_PLAY_MODE_PLAY_SLOW_FWD_MED
export const OP_PLAY_MODE_PLAY_SLOW_FWD_MAX: number =
  cec.OP_PLAY_MODE_PLAY_SLOW_FWD_MAX
export const OP_PLAY_MODE_PLAY_SLOW_REV_MIN: number =
  cec.OP_PLAY_MODE_PLAY_SLOW_REV_MIN
export const OP_PLAY_MODE_PLAY_SLOW_REV_MED: number =
  cec.OP_PLAY_MODE_PLAY_SLOW_REV_MED
export const OP_PLAY_MODE_PLAY_SLOW_REV_MAX: number =
  cec.OP_PLAY_MODE_PLAY_SLOW_REV_MAX
export const MSG_GIVE_TUNER_DEVICE_STATUS: number =
  cec.MSG_GIVE_TUNER_DEVICE_STATUS
export const MSG_SELECT_ANALOGUE_SERVICE: number =
  cec.MSG_SELECT_ANALOGUE_SERVICE
export const MSG_SELECT_DIGITAL_SERVICE: number = cec.MSG_SELECT_DIGITAL_SERVICE
export const MSG_TUNER_DEVICE_STATUS: number = cec.MSG_TUNER_DEVICE_STATUS
export const OP_REC_FLAG_USED: number = cec.OP_REC_FLAG_USED
export const OP_REC_FLAG_NOT_USED: number = cec.OP_REC_FLAG_NOT_USED
export const OP_TUNER_DISPLAY_INFO_DIGITAL: number =
  cec.OP_TUNER_DISPLAY_INFO_DIGITAL
export const OP_TUNER_DISPLAY_INFO_NONE: number = cec.OP_TUNER_DISPLAY_INFO_NONE
export const OP_TUNER_DISPLAY_INFO_ANALOGUE: number =
  cec.OP_TUNER_DISPLAY_INFO_ANALOGUE
export const MSG_TUNER_STEP_DECREMENT: number = cec.MSG_TUNER_STEP_DECREMENT
export const MSG_TUNER_STEP_INCREMENT: number = cec.MSG_TUNER_STEP_INCREMENT
export const MSG_DEVICE_VENDOR_ID: number = cec.MSG_DEVICE_VENDOR_ID
export const MSG_GIVE_DEVICE_VENDOR_ID: number = cec.MSG_GIVE_DEVICE_VENDOR_ID
export const MSG_VENDOR_COMMAND: number = cec.MSG_VENDOR_COMMAND
export const MSG_VENDOR_COMMAND_WITH_ID: number = cec.MSG_VENDOR_COMMAND_WITH_ID
export const MSG_VENDOR_REMOTE_BUTTON_DOWN: number =
  cec.MSG_VENDOR_REMOTE_BUTTON_DOWN
export const MSG_VENDOR_REMOTE_BUTTON_UP: number =
  cec.MSG_VENDOR_REMOTE_BUTTON_UP
export const MSG_SET_OSD_STRING: number = cec.MSG_SET_OSD_STRING
export const OP_DISP_CTL_DEFAULT: number = cec.OP_DISP_CTL_DEFAULT
export const OP_DISP_CTL_UNTIL_CLEARED: number = cec.OP_DISP_CTL_UNTIL_CLEARED
export const OP_DISP_CTL_CLEAR: number = cec.OP_DISP_CTL_CLEAR
export const MSG_GIVE_OSD_NAME: number = cec.MSG_GIVE_OSD_NAME
export const MSG_SET_OSD_NAME: number = cec.MSG_SET_OSD_NAME
export const MSG_MENU_REQUEST: number = cec.MSG_MENU_REQUEST
export const OP_MENU_REQUEST_ACTIVATE: number = cec.OP_MENU_REQUEST_ACTIVATE
export const OP_MENU_REQUEST_DEACTIVATE: number = cec.OP_MENU_REQUEST_DEACTIVATE
export const OP_MENU_REQUEST_QUERY: number = cec.OP_MENU_REQUEST_QUERY
export const MSG_MENU_STATUS: number = cec.MSG_MENU_STATUS
export const OP_MENU_STATE_ACTIVATED: number = cec.OP_MENU_STATE_ACTIVATED
export const OP_MENU_STATE_DEACTIVATED: number = cec.OP_MENU_STATE_DEACTIVATED
export const MSG_USER_CONTROL_PRESSED: number = cec.MSG_USER_CONTROL_PRESSED
export const OP_UI_BCAST_TYPE_TOGGLE_ALL: number =
  cec.OP_UI_BCAST_TYPE_TOGGLE_ALL
export const OP_UI_BCAST_TYPE_TOGGLE_DIG_ANA: number =
  cec.OP_UI_BCAST_TYPE_TOGGLE_DIG_ANA
export const OP_UI_BCAST_TYPE_ANALOGUE: number = cec.OP_UI_BCAST_TYPE_ANALOGUE
export const OP_UI_BCAST_TYPE_ANALOGUE_T: number =
  cec.OP_UI_BCAST_TYPE_ANALOGUE_T
export const OP_UI_BCAST_TYPE_ANALOGUE_CABLE: number =
  cec.OP_UI_BCAST_TYPE_ANALOGUE_CABLE
export const OP_UI_BCAST_TYPE_ANALOGUE_SAT: number =
  cec.OP_UI_BCAST_TYPE_ANALOGUE_SAT
export const OP_UI_BCAST_TYPE_DIGITAL: number = cec.OP_UI_BCAST_TYPE_DIGITAL
export const OP_UI_BCAST_TYPE_DIGITAL_T: number = cec.OP_UI_BCAST_TYPE_DIGITAL_T
export const OP_UI_BCAST_TYPE_DIGITAL_CABLE: number =
  cec.OP_UI_BCAST_TYPE_DIGITAL_CABLE
export const OP_UI_BCAST_TYPE_DIGITAL_SAT: number =
  cec.OP_UI_BCAST_TYPE_DIGITAL_SAT
export const OP_UI_BCAST_TYPE_DIGITAL_COM_SAT: number =
  cec.OP_UI_BCAST_TYPE_DIGITAL_COM_SAT
export const OP_UI_BCAST_TYPE_DIGITAL_COM_SAT2: number =
  cec.OP_UI_BCAST_TYPE_DIGITAL_COM_SAT2
export const OP_UI_BCAST_TYPE_IP: number = cec.OP_UI_BCAST_TYPE_IP
export const OP_UI_SND_PRES_CTL_DUAL_MONO: number =
  cec.OP_UI_SND_PRES_CTL_DUAL_MONO
export const OP_UI_SND_PRES_CTL_KARAOKE: number = cec.OP_UI_SND_PRES_CTL_KARAOKE
export const OP_UI_SND_PRES_CTL_DOWNMIX: number = cec.OP_UI_SND_PRES_CTL_DOWNMIX
export const OP_UI_SND_PRES_CTL_REVERB: number = cec.OP_UI_SND_PRES_CTL_REVERB
export const OP_UI_SND_PRES_CTL_EQUALIZER: number =
  cec.OP_UI_SND_PRES_CTL_EQUALIZER
export const OP_UI_SND_PRES_CTL_BASS_UP: number = cec.OP_UI_SND_PRES_CTL_BASS_UP
export const OP_UI_SND_PRES_CTL_BASS_NEUTRAL: number =
  cec.OP_UI_SND_PRES_CTL_BASS_NEUTRAL
export const OP_UI_SND_PRES_CTL_BASS_DOWN: number =
  cec.OP_UI_SND_PRES_CTL_BASS_DOWN
export const OP_UI_SND_PRES_CTL_TREBLE_UP: number =
  cec.OP_UI_SND_PRES_CTL_TREBLE_UP
export const OP_UI_SND_PRES_CTL_TREBLE_NEUTRAL: number =
  cec.OP_UI_SND_PRES_CTL_TREBLE_NEUTRAL
export const OP_UI_SND_PRES_CTL_TREBLE_DOWN: number =
  cec.OP_UI_SND_PRES_CTL_TREBLE_DOWN
export const MSG_USER_CONTROL_RELEASED: number = cec.MSG_USER_CONTROL_RELEASED
export const MSG_GIVE_DEVICE_POWER_STATUS: number =
  cec.MSG_GIVE_DEVICE_POWER_STATUS
export const MSG_REPORT_POWER_STATUS: number = cec.MSG_REPORT_POWER_STATUS
export const OP_POWER_STATUS_ON: number = cec.OP_POWER_STATUS_ON
export const OP_POWER_STATUS_STANDBY: number = cec.OP_POWER_STATUS_STANDBY
export const OP_POWER_STATUS_TO_ON: number = cec.OP_POWER_STATUS_TO_ON
export const OP_POWER_STATUS_TO_STANDBY: number = cec.OP_POWER_STATUS_TO_STANDBY
export const MSG_FEATURE_ABORT: number = cec.MSG_FEATURE_ABORT
export const OP_ABORT_UNRECOGNIZED_OP: number = cec.OP_ABORT_UNRECOGNIZED_OP
export const OP_ABORT_INCORRECT_MODE: number = cec.OP_ABORT_INCORRECT_MODE
export const OP_ABORT_NO_SOURCE: number = cec.OP_ABORT_NO_SOURCE
export const OP_ABORT_INVALID_OP: number = cec.OP_ABORT_INVALID_OP
export const OP_ABORT_REFUSED: number = cec.OP_ABORT_REFUSED
export const OP_ABORT_UNDETERMINED: number = cec.OP_ABORT_UNDETERMINED
export const MSG_ABORT: number = cec.MSG_ABORT
export const MSG_GIVE_AUDIO_STATUS: number = cec.MSG_GIVE_AUDIO_STATUS
export const MSG_GIVE_SYSTEM_AUDIO_MODE_STATUS: number =
  cec.MSG_GIVE_SYSTEM_AUDIO_MODE_STATUS
export const MSG_REPORT_AUDIO_STATUS: number = cec.MSG_REPORT_AUDIO_STATUS
export const OP_AUD_MUTE_STATUS_OFF: number = cec.OP_AUD_MUTE_STATUS_OFF
export const OP_AUD_MUTE_STATUS_ON: number = cec.OP_AUD_MUTE_STATUS_ON
export const MSG_REPORT_SHORT_AUDIO_DESCRIPTOR: number =
  cec.MSG_REPORT_SHORT_AUDIO_DESCRIPTOR
export const MSG_REQUEST_SHORT_AUDIO_DESCRIPTOR: number =
  cec.MSG_REQUEST_SHORT_AUDIO_DESCRIPTOR
export const MSG_SET_SYSTEM_AUDIO_MODE: number = cec.MSG_SET_SYSTEM_AUDIO_MODE
export const OP_SYS_AUD_STATUS_OFF: number = cec.OP_SYS_AUD_STATUS_OFF
export const OP_SYS_AUD_STATUS_ON: number = cec.OP_SYS_AUD_STATUS_ON
export const MSG_SYSTEM_AUDIO_MODE_REQUEST: number =
  cec.MSG_SYSTEM_AUDIO_MODE_REQUEST
export const MSG_SYSTEM_AUDIO_MODE_STATUS: number =
  cec.MSG_SYSTEM_AUDIO_MODE_STATUS
export const OP_AUD_FMT_ID_CEA861: number = cec.OP_AUD_FMT_ID_CEA861
export const OP_AUD_FMT_ID_CEA861_CXT: number = cec.OP_AUD_FMT_ID_CEA861_CXT
export const MSG_SET_AUDIO_RATE: number = cec.MSG_SET_AUDIO_RATE
export const OP_AUD_RATE_OFF: number = cec.OP_AUD_RATE_OFF
export const OP_AUD_RATE_WIDE_STD: number = cec.OP_AUD_RATE_WIDE_STD
export const OP_AUD_RATE_WIDE_FAST: number = cec.OP_AUD_RATE_WIDE_FAST
export const OP_AUD_RATE_WIDE_SLOW: number = cec.OP_AUD_RATE_WIDE_SLOW
export const OP_AUD_RATE_NARROW_STD: number = cec.OP_AUD_RATE_NARROW_STD
export const OP_AUD_RATE_NARROW_FAST: number = cec.OP_AUD_RATE_NARROW_FAST
export const OP_AUD_RATE_NARROW_SLOW: number = cec.OP_AUD_RATE_NARROW_SLOW
export const MSG_INITIATE_ARC: number = cec.MSG_INITIATE_ARC
export const MSG_REPORT_ARC_INITIATED: number = cec.MSG_REPORT_ARC_INITIATED
export const MSG_REPORT_ARC_TERMINATED: number = cec.MSG_REPORT_ARC_TERMINATED
export const MSG_REQUEST_ARC_INITIATION: number = cec.MSG_REQUEST_ARC_INITIATION
export const MSG_REQUEST_ARC_TERMINATION: number =
  cec.MSG_REQUEST_ARC_TERMINATION
export const MSG_TERMINATE_ARC: number = cec.MSG_TERMINATE_ARC
export const MSG_REQUEST_CURRENT_LATENCY: number =
  cec.MSG_REQUEST_CURRENT_LATENCY
export const MSG_REPORT_CURRENT_LATENCY: number = cec.MSG_REPORT_CURRENT_LATENCY
export const OP_LOW_LATENCY_MODE_OFF: number = cec.OP_LOW_LATENCY_MODE_OFF
export const OP_LOW_LATENCY_MODE_ON: number = cec.OP_LOW_LATENCY_MODE_ON
export const OP_AUD_OUT_COMPENSATED_NA: number = cec.OP_AUD_OUT_COMPENSATED_NA
export const OP_AUD_OUT_COMPENSATED_DELAY: number =
  cec.OP_AUD_OUT_COMPENSATED_DELAY
export const OP_AUD_OUT_COMPENSATED_NO_DELAY: number =
  cec.OP_AUD_OUT_COMPENSATED_NO_DELAY
export const OP_AUD_OUT_COMPENSATED_PARTIAL_DELAY: number =
  cec.OP_AUD_OUT_COMPENSATED_PARTIAL_DELAY
export const MSG_CDC_MESSAGE: number = cec.MSG_CDC_MESSAGE
export const MSG_CDC_HEC_INQUIRE_STATE: number = cec.MSG_CDC_HEC_INQUIRE_STATE
export const MSG_CDC_HEC_REPORT_STATE: number = cec.MSG_CDC_HEC_REPORT_STATE
export const OP_HEC_FUNC_STATE_NOT_SUPPORTED: number =
  cec.OP_HEC_FUNC_STATE_NOT_SUPPORTED
export const OP_HEC_FUNC_STATE_INACTIVE: number = cec.OP_HEC_FUNC_STATE_INACTIVE
export const OP_HEC_FUNC_STATE_ACTIVE: number = cec.OP_HEC_FUNC_STATE_ACTIVE
export const OP_HEC_FUNC_STATE_ACTIVATION_FIELD: number =
  cec.OP_HEC_FUNC_STATE_ACTIVATION_FIELD
export const OP_HOST_FUNC_STATE_NOT_SUPPORTED: number =
  cec.OP_HOST_FUNC_STATE_NOT_SUPPORTED
export const OP_HOST_FUNC_STATE_INACTIVE: number =
  cec.OP_HOST_FUNC_STATE_INACTIVE
export const OP_HOST_FUNC_STATE_ACTIVE: number = cec.OP_HOST_FUNC_STATE_ACTIVE
export const OP_ENC_FUNC_STATE_EXT_CON_NOT_SUPPORTED: number =
  cec.OP_ENC_FUNC_STATE_EXT_CON_NOT_SUPPORTED
export const OP_ENC_FUNC_STATE_EXT_CON_INACTIVE: number =
  cec.OP_ENC_FUNC_STATE_EXT_CON_INACTIVE
export const OP_ENC_FUNC_STATE_EXT_CON_ACTIVE: number =
  cec.OP_ENC_FUNC_STATE_EXT_CON_ACTIVE
export const OP_CDC_ERROR_CODE_NONE: number = cec.OP_CDC_ERROR_CODE_NONE
export const OP_CDC_ERROR_CODE_CAP_UNSUPPORTED: number =
  cec.OP_CDC_ERROR_CODE_CAP_UNSUPPORTED
export const OP_CDC_ERROR_CODE_WRONG_STATE: number =
  cec.OP_CDC_ERROR_CODE_WRONG_STATE
export const OP_CDC_ERROR_CODE_OTHER: number = cec.OP_CDC_ERROR_CODE_OTHER
export const OP_HEC_SUPPORT_NO: number = cec.OP_HEC_SUPPORT_NO
export const OP_HEC_SUPPORT_YES: number = cec.OP_HEC_SUPPORT_YES
export const OP_HEC_ACTIVATION_ON: number = cec.OP_HEC_ACTIVATION_ON
export const OP_HEC_ACTIVATION_OFF: number = cec.OP_HEC_ACTIVATION_OFF
export const MSG_CDC_HEC_SET_STATE_ADJACENT: number =
  cec.MSG_CDC_HEC_SET_STATE_ADJACENT
export const MSG_CDC_HEC_SET_STATE: number = cec.MSG_CDC_HEC_SET_STATE
export const OP_HEC_SET_STATE_DEACTIVATE: number =
  cec.OP_HEC_SET_STATE_DEACTIVATE
export const OP_HEC_SET_STATE_ACTIVATE: number = cec.OP_HEC_SET_STATE_ACTIVATE
export const MSG_CDC_HEC_REQUEST_DEACTIVATION: number =
  cec.MSG_CDC_HEC_REQUEST_DEACTIVATION
export const MSG_CDC_HEC_NOTIFY_ALIVE: number = cec.MSG_CDC_HEC_NOTIFY_ALIVE
export const MSG_CDC_HEC_DISCOVER: number = cec.MSG_CDC_HEC_DISCOVER
export const MSG_CDC_HPD_SET_STATE: number = cec.MSG_CDC_HPD_SET_STATE
export const OP_HPD_STATE_CP_EDID_DISABLE: number =
  cec.OP_HPD_STATE_CP_EDID_DISABLE
export const OP_HPD_STATE_CP_EDID_ENABLE: number =
  cec.OP_HPD_STATE_CP_EDID_ENABLE
export const OP_HPD_STATE_CP_EDID_DISABLE_ENABLE: number =
  cec.OP_HPD_STATE_CP_EDID_DISABLE_ENABLE
export const OP_HPD_STATE_EDID_DISABLE: number = cec.OP_HPD_STATE_EDID_DISABLE
export const OP_HPD_STATE_EDID_ENABLE: number = cec.OP_HPD_STATE_EDID_ENABLE
export const OP_HPD_STATE_EDID_DISABLE_ENABLE: number =
  cec.OP_HPD_STATE_EDID_DISABLE_ENABLE
export const MSG_CDC_HPD_REPORT_STATE: number = cec.MSG_CDC_HPD_REPORT_STATE
export const OP_HPD_ERROR_NONE: number = cec.OP_HPD_ERROR_NONE
export const OP_HPD_ERROR_INITIATOR_NOT_CAPABLE: number =
  cec.OP_HPD_ERROR_INITIATOR_NOT_CAPABLE
export const OP_HPD_ERROR_INITIATOR_WRONG_STATE: number =
  cec.OP_HPD_ERROR_INITIATOR_WRONG_STATE
export const OP_HPD_ERROR_OTHER: number = cec.OP_HPD_ERROR_OTHER
export const OP_HPD_ERROR_NONE_NO_VIDEO: number = cec.OP_HPD_ERROR_NONE_NO_VIDEO
