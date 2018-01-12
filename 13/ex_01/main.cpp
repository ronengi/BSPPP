#include "/home/blanca/bs_ppp/bs_fltk/Simple_window.h"
#include "/home/blanca/bs_ppp/bs_fltk/Graph.h"

#include "Arc.hpp"


int main() {
  using namespace Graph_lib;

  Simple_window win(Point(100, 100), 800, 800, "Ex-01");

  Rectangle r1(Point(200, 0), 400,800);
  r1.set_style(Line_style(Line_style::solid, 2));
  r1.set_color(Color::green);
  win.attach(r1);

  Arc arc1(Point(400, 400), 200, 400, 0, 192);
  arc1.set_style(Line_style(Line_style::solid, 2));
  arc1.set_color(Color::blue);
  win.attach(arc1);

  win.wait_for_button();
}
