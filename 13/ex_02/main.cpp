#include "/home/blanca/bs_ppp/bs_fltk/Simple_window.h"
#include "/home/blanca/bs_ppp/bs_fltk/Graph.h"

#include "Arc.hpp"
#include "Box.hpp"


int main() {
  using namespace Graph_lib;

  Simple_window win(Point(100, 100), 800, 800, "Ex-02");

  Rectangle r1(Point(200, 100), 400,600);
  r1.set_style(Line_style(Line_style::solid, 2));
  r1.set_color(Color::green);
  win.attach(r1);

  Arc arc1(Point(400, 400), 200, 300, 0, 192);
  arc1.set_style(Line_style(Line_style::solid, 2));
  arc1.set_color(Color::blue);
  win.attach(arc1);


  Box box1(Point(200, 100), 400, 600, 50, 50);
  box1.set_style(Line_style(Line_style::solid, 2));
  box1.set_color(Color::red);
  win.attach(box1);

  win.wait_for_button();
}
