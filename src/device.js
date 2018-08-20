// @flow

import EventEmitter from 'events'
import {inherits} from 'util'
import bindings from 'bindings'

/*::
import type {Caps, Event, LogAddrs, Msg, bigint} from './types'

// TODO: Flow doesn't support bigint yet
const BigInt = (n: number): bigint => n

class Device extends EventEmitter {
  constructor(path: string) {
    super()
  }
  async open(): Promise<void> {}
  async close(): Promise<void> {}
  async getCaps(): Promise<Caps> {
    return {
      driver: '',
      name: '',
      availableLogAddrs: 0,
      capabilities: 0,
      version: 0
    }
  }
  async getPhysAddr(): Promise<number> {
    return 0
  }
  async setPhysAddr(physAddr: number): Promise<number> {
    return 0
  }
  async getLogAddrs(): Promise<LogAddrs> {
    return {
      logAddr: [],
      logAddrMask: 0,
      cecVersion: 0,
      numLogAddrs: 0,
      vendorId: 0,
      flags: 0,
      osdName: '',
      primaryDeviceType: [],
      logAddrType: [],
      allDeviceTypes: [],
      features: []
    }
  }
  async setLogAddrs(logAddrs: LogAddrs): Promise<LogAddrs> {
    return logAddrs
  }
  async dequeueEvent(): Promise<Event> {
    return {
      ts: BigInt(0),
      event: 0,
      flags: 0
    }
  }
  async receive(): Promise<Msg> {
    return {
      txTs: BigInt(0),
      rxTs: BigInt(0),
      len: 0,
      timeout: 0,
      sequence: 0,
      flags: 0,
      msg: [],
      reply: 0,
      rxStatus: 0,
      txStatus: 0,
      txArbLostCnt: 0,
      txNackCnt: 0,
      txLowDriveCnt: 0,
      txErrorCnt: 0
    }
  }
  async transmit(msg: Msg): Promise<Msg> {
    return msg
  }
  async getMode(): Promise<number> {
    return 0
  }
  async setMode(mode: number): Promise<number> {
    return mode
  }
  now(): bigint {
    return BigInt(0)
  }
}
*/

const cls = (bindings('nodelinuxcec.node').Device: Class<Device>)

inherits(cls, EventEmitter)

export default cls
