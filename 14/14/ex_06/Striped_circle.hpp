#ifndef STRIPED_CIRCLE_HPP
#define STRIPED_CIRCLE_HPP


#include "/home/blanca/bs_ppp/bs_fltk/Simple_window.h"
#include "/home/blanca/bs_ppp/bs_fltk/Graph.h"


class Striped_circle : public Circle {

public:
  Striped_circle(Point p, int rr);
  void draw_lines() const;
};



#endif
