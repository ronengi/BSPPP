#include "/home/blanca/bs_ppp/bs_fltk/Simple_window.h"
#include "/home/blanca/bs_ppp/bs_fltk/Graph.h"

#include "Shape_controller.hpp"


int main() {
  using namespace Graph_lib;

  Simple_window win(Point(10, 10), 1000, 800, "Ex-16");

  Rectangle r1(Point(100, 100), 500, 400);
  r1.set_style(Line_style(Line_style::solid, 1));
  r1.set_color(Color::blue);
  r1.set_fill_color(Color::green);
  win.attach(r1);

  // Circle c1(Point(700, 500), 100);
  // win.attach(c1);

  win.wait_for_button();

  Shape_controller sc1(r1);
  win.wait_for_button();

  sc1.off();
  win.wait_for_button();


  sc1.on();
  win.wait_for_button();

  sc1.set_level(13);
  win.wait_for_button();

  sc1.show();
  win.wait_for_button();

}	
