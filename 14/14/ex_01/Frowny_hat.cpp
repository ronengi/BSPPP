#include "Frowny_hat.hpp"

Frowny_hat::Frowny_hat(Point p, int rr)
  : Frowny(p, rr) {
}

void Frowny_hat::draw_lines() const {
  Frowny::draw_lines();
  if (color().visibility()) {
    fl_color(color().as_int());
    int r = radius(), x = point(0).x, y = point(0).y;

    fl_pie(x, y - r/2, r+r, r+r, 45, 135); // hat
  }

}
