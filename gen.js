// @flow

const {
  promises: {readFile, writeFile}
} = require('fs')
const {spawn} = require('child_process')
const {resolve, basename} = require('path')
const prettier = require('prettier')

const s2p = s => s.replace(/(?:^|_+)([a-zA-Z0-9])/g, (_, l) => l.toUpperCase())
const s2c = s => s.replace(/_+([a-zA-Z0-9])/g, (_, l) => l.toUpperCase())

const formatJs = async (name, src) =>
  // $FlowFixMe:
  prettier.format(
    src,
    // $FlowFixMe:
    await prettier.resolveConfig(process.cwd(), {
      config: resolve('.prettierrc')
    })
  )

const formatCpp = (name, src) =>
  new Promise((resolve, reject) => {
    let out = ''
    const child = spawn('clang-format', [
      '-style=google',
      `-assume-filename=${basename(name)}`
    ])
    child.once(
      'close',
      code =>
        code === 0
          ? resolve(out)
          : reject(new Error(`clang-format failed: ${code}`))
    )
    child.stdout.on('data', data => (out += data.toString('utf8')))
    child.stdin.end(src)
  })

const writeJs = async (name, src) =>
  writeFile(name, await formatJs(name, src), 'utf8')

const writeCpp = async (name, src) =>
  writeFile(name, await formatCpp(name, src), 'utf8')

const cecType = type => ({
  msg: {
    def: (name, value) =>
      `${type} ${name} = ${value}.As<${s2p(type.replace('cec_', ''))}>();`,
    call: name => `&${name}`,
    flow: name => s2p(type.replace('cec_', ''))
  },
  ops: {
    def: name => `${type} ${name} = {};`,
    call: name => `&${name}`,
    ret: (name, value) =>
      `${value} = ${s2p(type.replace('cec_', ''))}::New(info.Env(), ${name});`,
    flow: name => s2p(type.replace('cec_', ''))
  }
})

const numType = (type, vtype) => ({
  msg: {
    def: (name, value) =>
      `${type} ${name} = ${value}.As<${
        name.startsWith('has') ? 'Napi::Boolean' : vtype
      }>();`,
    call: name => name,
    flow: name => (name.startsWith('has') ? 'boolean' : 'number')
  }
})

const numPointerType = (type, vtype) => ({
  msg: {
    def: (name, value) => `Napi::Array ${name}_arr = ${value}.As<Napi::Array>();
      uint32_t ${name}_len = ${name}_arr.Length();
      uint32_t ${name}_i;
      ${type} ${name}[${name}_len] = {0};
      for (${name}_i = 0; ${name}_i < ${name}_len; ${name}_i++)
        ${name}[${name}_i] = ${name}_arr.Get(${name}_i).As<${vtype}>();`,
    call: name => name,
    flow: name => 'number[]'
  },
  ops: {
    def: name => `${type} ${name} = 0;`,
    call: name => `&${name}`,
    ret: (name, value) =>
      `${value} = ${
        name.startsWith('has') ? 'Napi::Boolean' : vtype
      }::New(info.Env(), ${name});`,
    flow: name => (name.startsWith('has') ? 'boolean' : 'number')
  },
  set: {
    def: name => `${type} ${name}[CEC_MAX_MSG_SIZE] = {0};`,
    ret: (
      name,
      value
    ) => `Napi::Array ${name}_arr = Napi::Array::New(info.Env());
      uint32_t ${name}_i;
      for (${name}_i = 0; ${name}_i < CEC_MAX_MSG_SIZE; ${name}_i++)
        ${name}_arr[${name}_i] = ${vtype}::New(info.Env(), ${name}[${name}_i]);
      ${value} = ${name}_arr;`
  }
})

const TYPES = {
  __u8: numType('__u8', 'SmallInt'),
  '__u8*': numPointerType('__u8', 'SmallInt'),
  '__u8**': {
    ops: {
      def: name => `const __u8* ${name} = NULL;`,
      call: name => `&${name}`,
      ret: (name, value) => `if (${name} == NULL) {
        ${value} = info.Env().Undefined();
      } else {
        Napi::Array ${name}_arr = Napi::Array::New(info.Env());
        uint32_t ${name}_len = (msg.msg + CEC_MAX_MSG_SIZE) - ${name};
        uint32_t ${name}_i;
        for (${name}_i = 0; ${name}_i < ${name}_len; ${name}_i++)
          ${name}_arr[${name}_i] = SmallInt::New(info.Env(), ${name}[${name}_i]);
        ${value} = ${name}_arr;
      }`,
      flow: name => 'number[]'
    }
  },
  __u16: numType('__u16', 'SmallInt'),
  '__u16*': numPointerType('__u16', 'SmallInt'),
  __u32: numType('__u32', 'Napi::Number'),
  '__u32*': numPointerType('__u32', 'Napi::Number'),
  int: {
    msg: {
      def: (name, value) => `int ${name} = ${value}.As<Napi::Boolean>();`,
      call: name => name,
      flow: name => 'boolean'
    }
  },
  'char*': {
    msg: {
      def: (name, value) =>
        `std::string ${name} = ${value}.As<Napi::String>();`,
      call: name => `${name}.c_str()`,
      flow: name => 'string'
    },
    ops: {
      def: name => `char ${name}[CEC_MAX_MSG_SIZE] = {0};`,
      call: name => `${name}`,
      ret: (name, value) =>
        `${value} = Napi::String::New(info.Env(), ${name});`,
      flow: name => 'string'
    }
  },
  'cec_msg*': cecType('cec_msg'),
  'cec_log_addrs*': cecType('cec_log_addrs'),
  'cec_op_ui_command*': cecType('cec_op_ui_command'),
  'cec_op_digital_service_id*': cecType('cec_op_digital_service_id'),
  'cec_op_tuner_device_info*': cecType('cec_op_tuner_device_info'),
  'cec_op_record_src*': cecType('cec_op_record_src')
}

const findConstants = src =>
  src
    .split('#define CEC_')
    .slice(1)
    .map(s =>
      s
        .replace(/\\\n/g, ' ')
        .split('\n')[0]
        .replace(/\s+CEC_/g, ' ')
        .replace(/\/\*.*\*\//g, '')
    )
    .filter(s => !s.includes('_IO'))
    .map(s => ({
      name: `CEC_${s.replace(/^([A-Z0-9_]+)\s+.*$/, '$1')}`,
      value: s.replace(/^[A-Z0-9_]+\s+(.*)$/, '$1')
    }))

const parseArg = arg => {
  const name = arg.replace(/^.*\s+\**(\w+)$/, '$1')
  const type = arg.replace(/^(?:\w+\s+)*(\w+)\s+(\**)\w+$/, '$1$2')
  return {name, type}
}

const parseSig = sig => {
  const [retName, ...args] = sig
    .slice(0, -1)
    .split(/\(|,/)
    .map(s => s.trim())
  const [ret, name] = retName.split(/\s+/)
  return {
    name,
    ret,
    args: args.map(parseArg)
  }
}

const findSigs = src =>
  src
    .split(/static (?:__)?inline(?:__)? /)
    .slice(1)
    .map(
      s =>
        s
          .split(')')[0]
          .replace(/\n/gm, '')
          .replace(/\s{2,}/g, ' ') + ')'
    )
    .map(parseSig)

const funcSig = ({name, args}) =>
  `Napi::Value ${s2p(
    name.replace(/^cec_/, '')
  )}(const Napi::CallbackInfo& info)`

const funcDef = fn => `${funcSig(fn)};`

const funcExp = fn =>
  `cec.Set(Napi::String::New(env, "${s2c(
    fn.name.replace(/^cec_/, '')
  )}"), Napi::Function::New(env, ${s2p(fn.name.replace(/^cec_/, ''))}));`

const msgFuncImpl = fn => `${funcSig(fn)} {
  ${fn.args
    .map((a, i) => TYPES[a.type].msg.def(a.name, `info[${i}]`))
    .join('\n  ')}
  ${fn.name}(${fn.args.map(a => TYPES[a.type].msg.call(a.name)).join(', ')});
  return Msg::New(info.Env(), msg);
}
`

const msgFuncFlow = fn =>
  `export const ${s2c(fn.name.replace(/^cec_/, ''))}: (${fn.args
    .map(a => `${s2c(a.name)}: ${TYPES[a.type].msg.flow(a.name)}`)
    .join(', ')}) => Msg = cec.${s2c(fn.name.replace(/^cec_/, ''))}`

const getFuncImpl = fn => `${funcSig(fn)} {
  ${TYPES[fn.args[0].type].msg.def(fn.args[0].name, `info[0]`)}
  ${TYPES[fn.args[1].type].ops.def(fn.args[1].name)}
  ${fn.name}(${fn.args.map(a => TYPES[a.type].msg.call(a.name)).join(', ')});
  ${TYPES[fn.args[1].type].ops.ret(fn.args[1].name, 'Napi::Value ret')}
  return ret;
}
`

const getFuncFlow = fn =>
  `export const ${s2c(fn.name.replace(/^cec_/, ''))}: (${s2c(
    fn.args[0].name
  )}: ${TYPES[fn.args[0].type].msg.flow(fn.args[0].name)}) => ${TYPES[
    fn.args[1].type
  ].msg.flow(fn.args[1].name)} = cec.${s2c(fn.name.replace(/^cec_/, ''))}`

const setFuncImpl = fn => `${funcSig(fn)} {
  ${TYPES[fn.args[0].type].set.def(fn.args[0].name)}
  ${TYPES[fn.args[1].type].msg.def(fn.args[1].name, `info[0]`)}
  ${fn.name}(${fn.args.map(a => TYPES[a.type].msg.call(a.name)).join(', ')});
  ${TYPES[fn.args[0].type].set.ret(fn.args[0].name, 'Napi::Value ret')}
  return ret;
}
`

const setFuncFlow = fn =>
  `export const ${s2c(fn.name.replace(/^cec_/, ''))}: (${s2c(
    fn.args[1].name
  )}: ${TYPES[fn.args[1].type].msg.flow(fn.args[1].name)}) => ${TYPES[
    fn.args[0].type
  ].msg.flow(fn.args[0].name)} = cec.${s2c(fn.name.replace(/^cec_/, ''))}`

const opsFuncImpl = fn => `${funcSig(fn)} {
  cec_msg msg = info[0].As<Msg>();
  ${fn.args
    .slice(1)
    .map(a => TYPES[a.type].ops.def(a.name))
    .join('\n  ')}
  ${fn.name}(&msg, ${fn.args
  .slice(1)
  .map(a => TYPES[a.type].ops.call(a.name))
  .join(', ')});
  ${
    fn.args.length === 2
      ? `${TYPES[fn.args[1].type].ops.ret(fn.args[1].name, 'Napi::Value ret')}`
      : `Napi::Object ret = Napi::Object::New(info.Env());
  ${fn.args
    .slice(1)
    .map(a => TYPES[a.type].ops.ret(a.name, `ret["${s2c(a.name)}"]`))
    .join('\n')}`
  }
  return ret;
}
`

const opsFuncFlow = fn =>
  `export const ${s2c(fn.name.replace(/^cec_/, ''))}: (${fn.args
    .slice(0, 1)
    .map(a => `${s2c(a.name)}: ${TYPES[a.type].ops.flow(a.name)}`)
    .join(', ')}) => ${
    fn.args.length === 2
      ? TYPES[fn.args[1].type].ops.flow(fn.args[1].name)
      : `{
      ${fn.args
        .slice(1)
        .map(a => `${s2c(a.name)}: ${TYPES[a.type].ops.flow(a.name)}`)
        .join(',\n')}
    }`
  } = cec.${s2c(fn.name.replace(/^cec_/, ''))}`

const valFuncImpl = (fn, type) => `${funcSig(fn)} {
    ${fn.args
      .map((a, i) => TYPES[a.type].msg.def(a.name, `info[${i}]`))
      .join('\n  ')}
    return ${type}::New(info.Env(), ${fn.name}(${fn.args
  .map(a => TYPES[a.type].msg.call(a.name))
  .join(', ')}));
  }
  `

const valFuncFlow = (fn, type) =>
  `export const ${s2c(fn.name.replace(/^cec_/, ''))}: (${fn.args
    .map(a => `${s2c(a.name)}: ${TYPES[a.type].msg.flow(a.name)}`)
    .join(', ')}) => ${type} = cec.${s2c(fn.name.replace(/^cec_/, ''))}`

const msgInitImpl = fn => `${funcSig(fn)} {
  cec_msg msg;
  __u8 initiator = info[0].As<SmallInt>();
  __u8 destination = info[1].As<SmallInt>();
  cec_msg_init(&msg, initiator, destination);
  return Msg::New(info.Env(), msg);
}
`

const msgInitFlow = fn =>
  `export const msgInit: (initiator: number, destination: number) => Msg = cec.msgInit`

const genFunc = fn => {
  switch (fn.name.replace(/^cec_([^_]+)_.*$/, '$1')) {
    case 'get':
      return {
        def: funcDef(fn),
        impl: getFuncImpl(fn),
        exp: funcExp(fn),
        flow: getFuncFlow(fn)
      }
    case 'set':
      return {
        def: funcDef(fn),
        impl: setFuncImpl(fn),
        exp: funcExp(fn),
        flow: setFuncFlow(fn)
      }
    case 'msg':
      return fn.name === 'cec_msg_init'
        ? {
            def: funcDef(fn),
            impl: msgInitImpl(fn),
            exp: funcExp(fn),
            flow: msgInitFlow(fn)
          }
        : fn.ret === 'void'
          ? {
              def: funcDef(fn),
              impl: msgFuncImpl(fn),
              exp: funcExp(fn),
              flow: msgFuncFlow(fn)
            }
          : fn.name.includes('_is_')
            ? {
                def: funcDef(fn),
                impl: valFuncImpl(fn, 'Napi::Boolean'),
                exp: funcExp(fn),
                flow: valFuncFlow(fn, 'boolean')
              }
            : {
                def: funcDef(fn),
                impl: valFuncImpl(
                  fn,
                  fn.ret === 'int' ? 'Napi::Number' : 'SmallInt'
                ),
                exp: funcExp(fn),
                flow: valFuncFlow(fn, 'number')
              }
    case 'ops':
      return {
        def: funcDef(fn),
        impl: opsFuncImpl(fn),
        exp: funcExp(fn),
        flow: opsFuncFlow(fn)
      }
    case 'has':
    case 'is':
      return {
        def: funcDef(fn),
        impl: valFuncImpl(fn, 'Napi::Boolean'),
        exp: funcExp(fn),
        flow: valFuncFlow(fn, 'boolean')
      }
    default:
      return {
        def: `// ${fn.name}`,
        exp: `// ${fn.name}`,
        impl: `// ${fn.name}\n`,
        flow: `// ${fn.name},`
      }
  }
}

const genConstant = c => ({
  exp: `Napi::PropertyDescriptor::Value("${c.name.replace(
    /^CEC_/,
    ''
  )}", Napi::Number::New(env, ${c.name}), napi_enumerable),`,
  flow: `export const ${c.name.replace(
    /^CEC_/,
    ''
  )}: number = cec.${c.name.replace(/^CEC_/, '')}`
})

const nsOpen = `
namespace nodelinuxcec {
namespace Cec {`

const nsClose = `
}  // namespace Cec
}  // namespace nodelinuxcec
`

const includes = `
#include <linux/cec-funcs.h>
#include <linux/cec.h>
#include <napi.h>
#include "small-int.h"
#include "types.h"`

const cppOpen = `
#include "cec.h"${includes}
${nsOpen}
`

const cppClose = `${nsClose}`

const hppOpen = `
#ifndef NODE_LINUX_CEC_CEC_H_
#define NODE_LINUX_CEC_CEC_H_

#include <sys/ioctl.h>  // Must load before linux/cec
${includes}

#ifndef CEC_EVENT_PIN_5V_LOW
#define CEC_EVENT_PIN_5V_LOW 7
#endif

#ifndef CEC_EVENT_PIN_5V_HIGH
#define CEC_EVENT_PIN_5V_HIGH 8
#endif
${nsOpen}

Napi::Object Init(Napi::Env env, Napi::Object exports);
`

const hppClose = `${nsClose}
#endif  // NODE_LINUX_CEC_CEC_H_
`

const initOpen = `Napi::Object Init(Napi::Env env, Napi::Object exports) {
  Napi::Object cec = Napi::Object::New(env);
`

const initClose = `
  exports.Set(Napi::String::New(env, "cec"), cec);
  return exports;
}`

const jsOpen = `// @flow

import bindings from 'bindings'
import type {LogAddrs, Msg, OpDigitalServiceId, OpRecordSrc, OpTunerDeviceInfo, OpUiCommand} from './types'

const {cec} = bindings('nodelinuxcec.node')
`

const constantsOpen = `  cec.DefineProperties({`
const constantsClose = `  });`

const main = async path => {
  const src = [
    (await readFile(resolve(path, 'cec.h'))).toString('utf8'),
    (await readFile(resolve(path, 'cec-funcs.h'))).toString('utf8')
  ].join('\n')

  const funcs = findSigs(src).map(genFunc)
  const constants = findConstants(src).map(genConstant)

  const cpp = [
    cppOpen,
    ...funcs.map(fn => fn.impl),
    initOpen,
    ...funcs.map(fn => fn.exp),
    constantsOpen,
    ...constants.map(c => c.exp),
    constantsClose,
    initClose,
    cppClose
  ].join('\n')

  const hpp = [hppOpen, ...funcs.map(fn => fn.def), hppClose].join('\n')

  const js = [
    jsOpen,
    ...funcs.map(fn => fn.flow),
    ...constants.map(c => c.flow)
  ].join('\n')

  await writeCpp('./src/cec.h', hpp)
  await writeCpp('./src/cec.cc', cpp)
  await writeJs('./src/cec.js', js)
}

main(resolve(process.argv[2] || '.')).then(() => {}, err => console.error(err))
