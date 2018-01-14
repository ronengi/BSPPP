#ifndef OCTAGON_HPP
#define OCTAGON_HPP


#include "/home/blanca/bs_ppp/bs_fltk/Simple_window.h"
#include "/home/blanca/bs_ppp/bs_fltk/Graph.h"


class Octagon : public Polygon {

public:
  Octagon(Point center, int radius);
  void draw_lines() const;

private:
  Point _center;
  int _radius;
};





#endif
