#ifndef IMMOBILE_CIRCLE_HPP
#define IMMOBILE_CIRCLE_HPP


#include "/home/blanca/bs_ppp/bs_fltk/Simple_window.h"
#include "/home/blanca/bs_ppp/bs_fltk/Graph.h"


class Immobile_Circle : public Circle {

public:
  Immobile_Circle(Point p, int rr);
private:
  void move(int dx, int dy);
};




#endif
