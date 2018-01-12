#include <cmath>

#include "/home/blanca/bs_ppp/bs_fltk/Simple_window.h"
#include "/home/blanca/bs_ppp/bs_fltk/Graph.h"

#include "Arrow.hpp"


Arrow::Arrow(Point head, Point tail, int hw, int hl)
  : _head(head), _tail(tail), _hw(hw), _hl(hl) {

  int a = tail.y - head.y;
  int b = tail.x - head.x;
  int c = sqrt(a * a + b * b);
  int d = sqrt(hw * hw + hl * hl);

  int y = (hl * a + hw * b) / c;
  int x = sqrt(d * d - y * y);
  Point left(head.x - x, head.y + y);

  x = (hl * b + hw * a) / c;
  y = sqrt(d * d - x * x);
  Point right(head.x + x, head.y + y);

  add(tail, head); // main line
  add(head, left);
  add(left, right);
  add(right, head);
}

void Arrow::draw_lines() const {
  Lines::draw_lines();
}
