#ifndef REGULAR_POLYGON_HPP
#define REGULAR_POLYGON_HPP


#include "/home/blanca/bs_ppp/bs_fltk/Simple_window.h"
#include "/home/blanca/bs_ppp/bs_fltk/Graph.h"


class Regular_polygon : public Polygon {

public:
  Regular_polygon(Point center, int sides, int radius);
  void draw_lines() const;

private:
  Point _center;
  int _sides;
  int _radius;
};





#endif
