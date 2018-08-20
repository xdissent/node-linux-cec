
#ifndef NODE_LINUX_CEC_CONTROLLER_H_
#define NODE_LINUX_CEC_CONTROLLER_H_

#include <sys/epoll.h>
#include <string>

#define CTLR_EVENT_COUNT 5

namespace nodelinuxcec {

class Controller {
 public:
  struct Event {
    bool interrupt;
    bool prioritize;
    bool read;
  };

  Controller(const std::string& path);
  ~Controller();

  void Open();
  void Close();
  void Interrupt();
  Event Poll();
  void Ioctl(unsigned long int request, void* param);

  // private:
  int _devfd;
  int _ctlfd;
  int _epfd;
  epoll_event _events[CTLR_EVENT_COUNT];
  std::string _path;
};

}  // namespace nodelinuxcec

#endif  // NODE_LINUX_CEC_CONTROLLER_H_
