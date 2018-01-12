#include <cmath>
#define PI 3.141592654

#include "/home/blanca/bs_ppp/bs_fltk/Simple_window.h"
#include "/home/blanca/bs_ppp/bs_fltk/Graph.h"

// #include "Arc.hpp"
// #include "Box.hpp"
// #include "Arrow.hpp"



// Rectangle
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


// Circle
Point n(const Circle& c) {
  return Point(c.point(0).x + c.radius(), c.point(0).y);
}
Point e(const Circle& c) {
  return Point(c.point(0).x + c.radius() * 2, c.point(0).y + c.radius());
}
Point s(const Circle& c) {
  return Point(c.point(0).x + c.radius(), c.point(0).y + c.radius() * 2);
}
Point w(const Circle& c) {
  return Point(c.point(0).x, c.point(0).y + c.radius());
}
Point center(const Circle& c) {
  return Point(c.point(0).x + c.radius(), c.point(0).y + c.radius());
}
Point cp(const Circle& c, double a) {
  return Point(center(c).x + sin(a) * c.radius(), center(c).y + cos(a) * c.radius());
}
Point nw(const Circle& c) {
  return cp(c, 5.0 * PI / 4.0);
}
Point ne(const Circle& c) {
  return cp(c, 3.0 * PI / 4.0);
}
Point se(const Circle& c) {
  return cp(c, PI / 4.0);
}
Point sw(const Circle& c) {
  return cp(c, 7.0 * PI / 4.0);
}





// Ellipse
Point n(const Ellipse& e) {
  return Point(e.point(0).x + e.major(), e.point(0).y);
}
Point e(const Ellipse& el) {
  return Point(el.point(0).x + el.major() * 2, el.point(0).y + el.minor());
}
Point s(const Ellipse& e) {
  return Point(e.point(0).x + e.major(), e.point(0).y + e.minor() * 2);
}
Point w(const Ellipse& e) {
  return Point(e.point(0).x, e.point(0).y + e.minor());
}
Point center(const Ellipse& e) {
  return Point(e.point(0).x + e.major(), e.point(0).y + e.minor());
}
Point cp(const Ellipse& e, double a) {
  return Point(center(e).x + sin(a) * e.major(), center(e).y + cos(a) * e.minor());
}
Point nw(const Ellipse& e) {
  return cp(e, 5.0 * PI / 4.0);
}
Point ne(const Ellipse& e) {
  return cp(e, 3.0 * PI / 4.0);
}
Point se(const Ellipse& e) {
  return cp(e, PI / 4.0);
}
Point sw(const Ellipse& e) {
  return cp(e, 7.0 * PI / 4.0);
}





int main() {
  using namespace Graph_lib;

  Simple_window win(Point(100, 100), 800, 800, "Ex-05");

  Rectangle r(Point(100, 100), 300, 200);
  win.attach(r);

  Circle c(Point(200, 450), 100);
  win.attach(c);

  Ellipse el(Point(550, 450), 100, 150);
  win.attach(el);


  Lines l;
  l.add(center(r), n(r));
  l.add(center(r), e(r));
  l.add(center(r), s(r));
  l.add(center(r), w(r));
  l.add(center(r), nw(r));
  l.add(center(r), ne(r));
  l.add(center(r), se(r));
  l.add(center(r), sw(r));

  l.add(center(c), n(c));
  l.add(center(c), e(c));
  l.add(center(c), s(c));
  l.add(center(c), w(c));
  l.add(center(c), nw(c));
  l.add(center(c), ne(c));
  l.add(center(c), se(c));
  l.add(center(c), sw(c));

  l.add(center(el), n(el));
  l.add(center(el), e(el));
  l.add(center(el), s(el));
  l.add(center(el), w(el));
  l.add(center(el), nw(el));
  l.add(center(el), ne(el));
  l.add(center(el), se(el));
  l.add(center(el), sw(el));


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
