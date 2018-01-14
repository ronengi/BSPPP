#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP


class Controller {
protected:
  virtual void on() = 0;
  virtual void off() = 0;
  virtual void set_level(int) = 0;
  virtual void show() = 0;
};


#endif
