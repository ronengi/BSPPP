#include "Striped_rectangle.hpp"


Striped_rectangle::Striped_rectangle(Point xy, int ww, int hh)
  : Rectangle(xy, ww, hh) {
}

Striped_rectangle::Striped_rectangle(Point x, Point y)
  : Rectangle(x, y) {

}



void Striped_rectangle::draw_lines() const {
  int w = width();
  int h = height();

  if (fill_color().visibility()) {    // fill
    fl_color(fill_color().as_int());

    fl_line_style(FL_SOLID, 1); // set style
    for (int y = point(0).y; y < point(0).y + h; y += 3)
      fl_line(point(0).x, y, point(0).x + w, y);
    fl_line_style(0);    // reset line style to default

    fl_color(color().as_int());    // reset color
  }


  if (color().visibility()) {    // lines on top of fill
    fl_color(color().as_int());
    fl_rect(point(0).x,point(0).y,w,h);
  }

}
