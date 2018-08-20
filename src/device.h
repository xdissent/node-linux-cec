
#ifndef NODE_LINUX_CEC_DEVICE_H_
#define NODE_LINUX_CEC_DEVICE_H_

#include <sys/ioctl.h>  // Must load before linux/cec

#include <linux/cec.h>
#include <napi.h>
#include <string>
#include "controller.h"
#include "state.h"
#include "thread.h"
#include "tsfn.h"
#include "worker.h"

namespace nodelinuxcec {

class Device : public Napi::ObjectWrap<Device> {
 public:
  static Napi::Object Init(Napi::Env env, Napi::Object exports);
  Device(const Napi::CallbackInfo& info);
  ~Device() {}

 private:
  enum class States { Closed, Opening, Open, Closing };
  enum class Events { Open, Event, Message };

  struct TsfnData {
    Events event;
    union {
      cec_event event;
      cec_msg msg;
    } cec;
  };

  struct OpenData {
    States state;
  };

  template <typename P, typename V>
  struct IoctlData {
    unsigned long int request;
    P param;
  };

  struct IoctlMethodData {
    unsigned long int request;
    bool write;
  };

  template <typename P, typename V>
  static Napi::ClassPropertyDescriptor<Device> IoctlInstanceMethod(
      const char* name, unsigned long int request, bool write = false);

  void TsfnExecute(void* data, bool closing);
  void TsfnFinalize(void* data);

  void ThreadExecute();

  void OpenInit(WorkerInfo* info, const Napi::CallbackInfo& cb_info);
  void OpenExecute(WorkerInfo* info);
  void OpenOk(WorkerInfo* info);
  void OpenFinalize(WorkerInfo* info);

  void OpeningExecute(WorkerInfo* info);

  void CloseExecute(WorkerInfo* info);

  template <typename P, typename V>
  void IoctlInit(WorkerInfo* info, const Napi::CallbackInfo& cb_info);
  template <typename P, typename V>
  void IoctlExecute(WorkerInfo* info);
  template <typename P, typename V>
  void IoctlOk(WorkerInfo* info);
  template <typename P, typename V>
  void IoctlFinalize(WorkerInfo* info);

  Napi::Value Now(const Napi::CallbackInfo& info);

  bool _opened;
  std::string _path;
  State<States> _state;
  Tsfn<Device>* _tsfn;
  Thread<Device>* _thread;
  Controller* _ctlr;
};

}  // namespace nodelinuxcec

#endif  // NODE_LINUX_CEC_DEVICE_H_
