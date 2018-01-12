#include "/home/blanca/bs_ppp/bs_fltk/Simple_window.h"
#include "/home/blanca/bs_ppp/bs_fltk/Graph.h"

#include "Box.hpp"


Box::Box(Point tl, int w, int h, int aw, int ah)
  : _w(w), _h(h), _aw(aw), _ah(ah), _tl(tl) {

  add(Point(tl.x + aw, tl.y), Point(tl.x + w - aw, tl.y)); // top line
  add(Point(tl.x + w, tl.y + ah), Point(tl.x + w, tl.y + h - ah)); // right line
  add(Point(tl.x + aw, tl.y + h), Point(tl.x + w - aw, tl.y + h)); // bottom line
  add(Point(tl.x, tl.y + ah), Point(tl.x, tl.y + h - ah)); // left line
}

void Box::draw_lines() const {
  Lines::draw_lines();
  if (color().visibility()) {
    fl_arc(_tl.x, _tl.y, (2 * _aw), (2 * _ah), 90, 180); // top-left
    fl_arc(_tl.x, (_tl.y + _h - 2 * _ah), (2 * _aw), (2 * _ah), 180, 270); // bottom-left
    fl_arc((_tl.x + _w - 2 * _aw), (_tl.y + _h - 2 * _ah), (2 * _aw), (2 * _ah), 270, 360); // botom-right
    fl_arc((_tl.x + _w - 2 * _aw), _tl.y, (2 * _aw), (2 * _ah), 0, 90); // top-right
  }
}
