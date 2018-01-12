#ifndef RIGHT_TRIANGLE_HPP
#define RIGHT_TRIANGLE_HPP

#include "/home/blanca/bs_ppp/bs_fltk/Simple_window.h"
#include "/home/blanca/bs_ppp/bs_fltk/Graph.h"


class Right_triangle : public Polygon {
public:
  Right_triangle(Point p1, Point p2, Point p3);
  void draw_lines() const;

};



#endif
