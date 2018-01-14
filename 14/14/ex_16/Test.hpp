#ifndef TEST_HPP
#define TEST_HPP


#include "Controller.hpp"


class Test : public Controller {
public:
  Test();
  void on();
  void off();
  void set_level(int);
  void show();
private:
  bool _state;
  int _level;
};


#endif
