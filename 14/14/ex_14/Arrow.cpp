//#include <iostream>
//#include <cmath>

#include "/home/blanca/bs_ppp/bs_fltk/Simple_window.h"
#include "/home/blanca/bs_ppp/bs_fltk/Graph.h"

#include "Arrow.hpp"

#define PI 3.141592654


Arrow::Arrow(Point head, Point tail, int w, int l, string name)
  : H(head), T(tail), ww(w / 2), ll(l), _name(name) {

  int xx, yy;			// helpers

  double aa;
  if (H.x == T.x) {		// vertical arrow
    if (H.y < T.y)
      aa = PI / 2;		// up
    else
      aa = 3 * PI / 2;		// down
  }
  else if (H.y == T.y) {	// horizontal arrow
    if (H.x < T.x)
      aa = PI;			// left
    else
      aa = 0;			// right
  }
  else				// diagonal arrow
    aa = atan2((T.y - H.y), (H.x - T.x));

  yy = (ll * sin(aa)) + (ww * cos(aa));
  xx = (ww * sin(aa)) - (ll * cos(aa));
  Point B(H.x + xx, H.y + yy);

  yy = (ll * sin(aa)) - (ww * cos(aa));
  xx = (ww * sin(aa)) + (ll * cos(aa));
  Point C(H.x - xx, H.y + yy);


  add(H, T); // main line
  add(B, C);
  add(H, B);
  add(H, C);
}


void Arrow::draw_lines() const {
  Lines::draw_lines();

  if (fill_color().visibility()) {
    fl_color(fill_color().as_int());
    fl_begin_complex_polygon();
    fl_vertex(point(0).x, point(0).y);
    fl_vertex(point(2).x, point(2).y);
    fl_vertex(point(3).x, point(3).y);
    fl_end_complex_polygon();
    fl_color(color().as_int());    // reset color
  }
    

  // Text tH(point(0), "H (" + _name + ")");
  // tH.draw_lines();

  // Text tT(point(1), "T");
  // tT.draw_lines();

  // Text tB(point(2), "B");
  // tB.draw_lines();

  // Text tC(point(3), "C");
  // tC.draw_lines();

}
