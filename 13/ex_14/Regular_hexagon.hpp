#ifndef REGULAR_HEXAGON_HPP
#define REGULAR_HEXAGON_HPP


#include "/home/blanca/bs_ppp/bs_fltk/Simple_window.h"
#include "/home/blanca/bs_ppp/bs_fltk/Graph.h"


class Regular_hexagon : public Polygon {

public:
  Regular_hexagon(Point center, int radius);
  void draw_lines() const;

private:
  Point _center;
  int _radius;

};





#endif
