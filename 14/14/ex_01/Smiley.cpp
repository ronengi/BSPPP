#include "Smiley.hpp"

Smiley::Smiley(Point p, int rr)
  : Circle(p, rr) {
}

void Smiley::draw_lines() const {
  Circle::draw_lines();
  if (color().visibility()) {
    fl_color(color().as_int());
    int r = radius(), x = point(0).x, y = point(0).y;
    fl_arc(x + r/2 - r/10, y + r/2, r/5, r/5, 180, 360); // left eye
    fl_arc(x + r*3/2 - r/10, y + r/2, r/5, r/5, 180, 360); // right eye
    fl_arc(x + r - r/4, y + r + r/5, r/2, r/4, 180, 360); // mouth
  }

}
