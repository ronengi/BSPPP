#ifndef FROWNY_HPP
#define FROWNY_HPP


#include "/home/blanca/bs_ppp/bs_fltk/Simple_window.h"
#include "/home/blanca/bs_ppp/bs_fltk/Graph.h"


class Frowny : public Circle {

public:
  Frowny(Point p, int rr);
  void draw_lines() const;
};




#endif
