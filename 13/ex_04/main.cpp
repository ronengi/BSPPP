#include "/home/blanca/bs_ppp/bs_fltk/Simple_window.h"
#include "/home/blanca/bs_ppp/bs_fltk/Graph.h"

// #include "Arc.hpp"
// #include "Box.hpp"
// #include "Arrow.hpp"




Point n(const Rectangle& r) {
  return Point(r.point(0).x + r.width() / 2, r.point(0).y);
}
Point e(const Rectangle& r) {
  return Point(r.point(0).x + r.width(), r.point(0).y + r.height() / 2);
}
Point s(const Rectangle& r) {
  return Point(r.point(0).x + r.width() / 2, r.point(0).y + r.height());
}
Point w(const Rectangle& r) {
  return Point(r.point(0).x, r.point(0).y + r.height() / 2);
}
Point center(const Rectangle& r) {
  return Point(r.point(0).x + r.width() / 2, r.point(0).y + r.height() / 2);
}
Point nw(const Rectangle& r) {
  return r.point(0);
}
Point ne(const Rectangle& r) {
  return Point(r.point(0).x + r.width(), r.point(0).y);
}
Point se(const Rectangle& r) {
  return Point(r.point(0).x + r.width(), r.point(0).y + r.height());
}
Point sw(const Rectangle& r) {
  return Point(r.point(0).x, r.point(0).y + r.height());
}




int main() {
  using namespace Graph_lib;

  Simple_window win(Point(100, 100), 800, 800, "Ex-04");

  Rectangle r(Point(100, 100), 300, 200);
  win.attach(r);

  Lines l;
  l.add(n(r), s(r));
  l.add(center(r), n(r));
  l.add(center(r), e(r));
  l.add(center(r), s(r));
  l.add(center(r), w(r));
  l.add(center(r), nw(r));
  l.add(center(r), ne(r));
  l.add(center(r), se(r));
  l.add(center(r), sw(r));
  win.attach(l);



  // Arrow arrow1(Point(400,200), Point(200,100), 20, 50);
  // win.attach(arrow1);

  // Rectangle r1(Point(200, 100), 400,600);
  // r1.set_style(Line_style(Line_style::solid, 2));
  // r1.set_color(Color::green);
  // win.attach(r1);

  // Arc arc1(Point(400, 400), 200, 300, 0, 192);
  // arc1.set_style(Line_style(Line_style::solid, 2));
  // arc1.set_color(Color::blue);
  // win.attach(arc1);

  // Box box1(Point(200, 100), 400, 600, 50, 50);
  // box1.set_style(Line_style(Line_style::solid, 2));
  // box1.set_color(Color::red);
  // win.attach(box1);

  win.wait_for_button();
}	
