#ifndef SHAPE_CONTROLLER_HPP
#define SHAPE_CONTROLLER_HPP

#include "/home/blanca/bs_ppp/bs_fltk/Graph.h"
using namespace Graph_lib;

#include "Controller.hpp"


class Shape_controller : public Controller {
public:
  Shape_controller(Shape& sp);
  void on();
  void off();
  void set_level(int);
  void show();
private:
  Shape& _sp;
};


#endif
