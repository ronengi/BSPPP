#include "/home/blanca/bs_ppp/bs_fltk/Simple_window.h"
#include "/home/blanca/bs_ppp/bs_fltk/Graph.h"

#include "Arc.hpp"



Arc::Arc(Point c, int rx, int ry, int a1, int a2)
  : _rx(rx), _ry(ry), _a1(a1), _a2(a2) {
  add(Point((c.x - rx), (c.y - ry))); // store top left corner
}

void Arc::draw_lines() const {
  if (color().visibility())
    fl_arc(point(0).x, point(0).y, (2 * _rx), (2 * _ry), _a1, _a2);
}

Point Arc::center() const {
  return Point((point(0).x + _rx), (point(0).y + _ry));
}
