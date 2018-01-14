#ifndef SMILEY_HPP
#define SMILEY_HPP


#include "/home/blanca/bs_ppp/bs_fltk/Simple_window.h"
#include "/home/blanca/bs_ppp/bs_fltk/Graph.h"


class Smiley : public Circle {

public:
  Smiley(Point p, int rr);
  void draw_lines() const;
};




#endif
