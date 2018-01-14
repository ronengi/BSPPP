#include "Frowny.hpp"

Frowny::Frowny(Point p, int rr)
  : Circle(p, rr) {
}

void Frowny::draw_lines() const {
  Circle::draw_lines();
  if (color().visibility()) {
    fl_color(color().as_int());
    int r = radius(), x = point(0).x, y = point(0).y;
    fl_arc(x + r/2 - r/10, y + r/2, r/5, r/5, 0, 180); // left eye
    fl_arc(x + r*3/2 - r/10, y + r/2, r/5, r/5, 0, 180); // right eye
    fl_arc(x + r - r/4, y + r + r/5, r/2, r/4, 0, 180); // mouth
  }

}
