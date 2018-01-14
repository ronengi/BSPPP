#include "Smiley_hat.hpp"

Smiley_hat::Smiley_hat(Point p, int rr)
  : Smiley(p, rr) {
}

void Smiley_hat::draw_lines() const {
  Smiley::draw_lines();
  if (color().visibility()) {
    fl_color(color().as_int());
    int r = radius(), x = point(0).x, y = point(0).y;

    fl_pie(x, y - 3*r/2, r+r, r+r, 230, 310); // hat
  }

}
