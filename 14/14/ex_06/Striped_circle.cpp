#include <cmath>

#include "Striped_circle.hpp"


Striped_circle::Striped_circle(Point p, int rr)
  : Circle(p, rr) {
}



void Striped_circle::draw_lines() const {

  int x, y, r = radius();
  double a;

  if (fill_color().visibility()) {	// fill
    fl_color(fill_color().as_int());

    fl_line_style(FL_SOLID, 1); // set style
    for (y = (-1)*r; y < r; y += 3) {

      a = asin(double(y) / double(r));
      x = r * cos(a);

      fl_line(point(0).x + r - x, point(0).y + r + y, point(0).x + r + x, point(0).y + r + y);

    }
    fl_line_style(0);    // reset line style to default



    fl_color(color().as_int());	// reset color
  }

  if (color().visibility()) {
    fl_color(color().as_int());
    fl_arc(point(0).x,point(0).y,r+r,r+r,0,360);
  }

}
