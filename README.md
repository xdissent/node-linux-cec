# node-linux-cec

> Linux CEC bindings for Node.js

This package includes native bindings for the [Linux Consumer Electronics Control API](https://www.kernel.org/doc/html/latest/media/uapi/cec/cec-api.html). All constants and functions from [`linux/cec.h`](https://github.com/torvalds/linux/blob/master/include/uapi/linux/cec.h) and [`linux/cec-funcs.h`](https://github.com/torvalds/linux/blob/master/include/uapi/linux/cec-funcs.h) are included, as well as a `Device` class for managing CEC adapters.

## Requirements

- Node >= 10.7 (requires napi bigint support)

## API

The api is the same as found in the linux CEC headers, with the following changes:

- All functions, variables, arguments and properties are in camel case.
- All types/structs are in pascal case.
- The `CEC_` prefix has been removed from all constants.
- The `cec_` prefix has been removed from all functions.
- The `cec_msg_init` implementation doesn't accept an existing message as its first argument.
- All `cec_msg_*` functions return a new message object and do not alter the existing message.
- All `cec_ops_*` functions with one output value return that value directly.
- All `cec_ops_*` functions with more than one output value return an object with the output values as properties.
- All number values that are inherently boolean flags are cast as boolean values.

## Usage

```js
import * as cec from 'node-linux-cec'

const main = async () => {
  const device = new cec.Device('/dev/cec0')

  device.on('event', event => {
    // handle CEC event
  })

  device.on('message', async msg => {
    // handle CEC message
    if (cec.msgIsBroadcast(msg)) return
    msg = cec.msgReplyFeatureAbort(msg, cec.OP_ABORT_UNRECOGNIZED_OP)
    // Transmit reply
    await device.transmit(msg)
  })

  // Open the device
  await device.open()

  // Change device mode
  await device.setMode(cec.MODE_INITIATOR | cec.MODE_FOLLOWER)

  // ...

  // Reset mode and close device
  await device.setMode(cec.MODE_INITIATOR)
  await device.close()
}
```

## Development

Ensure `clang-format` and linux headers are installed. Run `yarn gen <path-to-cec-headers>` (`/usr/include/linux` on most systems) to update the generated bindings. Then build the module with `yarn build`.
