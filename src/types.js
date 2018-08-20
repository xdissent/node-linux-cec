// @flow

// TODO: Flow doesn't support bigint yet
export type bigint = number

export type Event = {
  ts: bigint,
  event: number,
  flags: number,
  stateChange?: {
    physAddr: number,
    logAddrMask: number
  },
  lostMsgs?: {
    lostMsgs: number
  }
}

export type Msg = {
  txTs: bigint,
  rxTs: bigint,
  len: number,
  timeout: number,
  sequence: number,
  flags: number,
  msg: number[],
  reply: number,
  rxStatus: number,
  txStatus: number,
  txArbLostCnt: number,
  txNackCnt: number,
  txLowDriveCnt: number,
  txErrorCnt: number
}

export type Caps = {
  driver: string,
  name: string,
  availableLogAddrs: number,
  capabilities: number,
  version: number
}

export type LogAddrs = {
  logAddr: number[],
  logAddrMask: number,
  cecVersion: number,
  numLogAddrs: number,
  vendorId: number,
  flags: number,
  osdName: string,
  primaryDeviceType: number[],
  logAddrType: number[],
  allDeviceTypes: number[],
  features: number[][]
}

export type OpAribData = {
  transportId: number,
  serviceId: number,
  origNetworkId: number
}

export type OpAtscData = {
  transportId: number,
  programNumber: number
}

export type OpDvbData = {
  transportId: number,
  serviceId: number,
  origNetworkId: number
}

export type OpChannelData = {
  channelNumberFmt: number,
  major: number,
  minor: number
}

export type OpDigitalServiceId = {
  serviceIdMethod: number,
  digBcastSystem: number,
  arib?: OpAribData,
  atsc?: OpAtscData,
  dvb?: OpDvbData,
  channel?: OpChannelData
}

export type OpRecordSrc = {
  type: number,
  digital?: OpDigitalServiceId,
  analog?: {
    anaBcastType: number,
    anaFreq: number,
    bcastSystem: number
  },
  extPlug?: {
    plug: number
  },
  extPhysAddr?: {
    physAddr: number
  }
}

export type OpTunerDeviceInfo = {
  recFlag: number,
  tunerDisplayInfo: number,
  isAnalog: boolean,
  digital?: OpDigitalServiceId,
  analog?: {
    anaBcastType: number,
    anaFreq: number,
    bcastSystem: number
  }
}

export type OpUiCommand = {
  uiCmd: number,
  hasOptArg: boolean,
  channelIdentifier?: OpChannelData,
  uiBroadcastType?: number,
  uiSoundPresentationControl?: number,
  playMode?: number,
  uiFunctionMedia?: number,
  uiFunctionSelectAvInput?: number,
  uiFunctionSelectAudioInput?: number
}
