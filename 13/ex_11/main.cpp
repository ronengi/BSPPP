#include <cmath>
#define PI 3.141592654

#include "/home/blanca/bs_ppp/bs_fltk/Simple_window.h"
#include "/home/blanca/bs_ppp/bs_fltk/Graph.h"


int main() {
  using namespace Graph_lib;

  Simple_window win(Point(100, 100), 800, 800, "Ex-11");

  Ellipse e1(Point(400, 400), 300, 200);
  e1.set_style(Line_style(Line_style::solid, 2));
  e1.set_color(Color::red);
  e1.set_fill_color(Color::green);
  win.attach(e1);

  Lines xy;
  xy.add(Point(e1.center().x - 200, e1.center().y), Point(e1.center().x + 200, e1.center().y));
  xy.add(Point(e1.center().x, e1.center().y - 150), Point(e1.center().x, e1.center().y + 150));
  xy.set_style(Line_style(Line_style::dot, 2));
  xy.set_color(Color::blue);
  win.attach(xy);

  Mark f1(e1.focus1(), 'x');
  win.attach(f1);
  Mark f2(e1.focus2(), 'x');
  win.attach(f2);

  Mark p1(Point(e1.center().x + e1.major() * sin(PI / 5), e1.center().y + e1.minor() * cos(PI / 5)), 'x');
  win.attach(p1);

  Lines l1;
  l1.add(f1.point(0), p1.point(0));
  l1.add(f2.point(0), p1.point(0));
  l1.set_style(Line_style(Line_style::dash, 2));
  l1.set_color(Color::yellow);
  win.attach(l1);

  win.wait_for_button();
}
