
#include "controller.h"
#include <fcntl.h>
#include <sys/epoll.h>
#include <sys/eventfd.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <string>
#include <system_error>

namespace nodelinuxcec {

Controller::Controller(const std::string& path)
    : _devfd(-1), _ctlfd(-1), _epfd(-1), _path(path) {}

Controller::~Controller() { Close(); }

void Controller::Open() {
  _devfd = open(_path.c_str(), O_RDWR);
  if (_devfd < 0) throw std::system_error(errno, std::generic_category());
  _ctlfd = eventfd(0, 0);
  if (_ctlfd < 0) throw std::system_error(errno, std::generic_category());
  _epfd = epoll_create(2);
  if (_epfd < 0) throw std::system_error(errno, std::generic_category());
  epoll_event event;
  event.data.fd = _ctlfd;
  event.events = EPOLLIN;
  if (epoll_ctl(_epfd, EPOLL_CTL_ADD, _ctlfd, &event))
    throw std::system_error(errno, std::generic_category());
  event.data.fd = _devfd;
  event.events = EPOLLIN | EPOLLPRI;
  if (epoll_ctl(_epfd, EPOLL_CTL_ADD, _devfd, &event))
    throw std::system_error(errno, std::generic_category());
}

void Controller::Close() {
  if (_epfd >= 0) {
    close(_epfd);
    _epfd = -1;
  }
  if (_ctlfd >= 0) {
    close(_ctlfd);
    _ctlfd = -1;
  }
  if (_devfd >= 0) {
    close(_devfd);
    _devfd = -1;
  }
}

void Controller::Interrupt() {
  uint64_t u = 1;
  if (write(_ctlfd, &u, sizeof(uint64_t)) < 0)
    throw std::system_error(errno, std::generic_category());
}

Controller::Event Controller::Poll() {
  int count = epoll_wait(_epfd, _events, CTLR_EVENT_COUNT, -1);
  if (count < 0) throw std::system_error(errno, std::generic_category());
  Event event = {};
  for (int i = 0; i < count; i++) {
    if (_events[i].data.fd == _ctlfd) event.interrupt = true;
    if (_events[i].data.fd != _devfd) continue;
    if (_events[i].events & EPOLLPRI) event.prioritize = true;
    if (_events[i].events & EPOLLIN) event.read = true;
  }
  return event;
}

void Controller::Ioctl(unsigned long int request, void* param) {
  if (ioctl(_devfd, request, param) == -1)
    throw std::system_error(errno, std::generic_category());
}

}  // namespace nodelinuxcec
