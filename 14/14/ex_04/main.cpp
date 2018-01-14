#include "/home/blanca/bs_ppp/bs_fltk/Simple_window.h"
#include "/home/blanca/bs_ppp/bs_fltk/Graph.h"

#include "Immobile_Circle.hpp"


int main() {
  using namespace Graph_lib;

  Simple_window win(Point(100, 100), 1000, 700, "ex-01");


  Immobile_Circle ic1(Point(250, 200), 100);
  ic1.set_style(Line_style(Line_style::solid, 2));
  ic1.set_color(Color::red);
  ic1.set_fill_color(Color::green);
  win.attach(ic1);


  Circle c1(Point(750, 200), 100);
  c1.set_style(Line_style(Line_style::solid, 2));
  c1.set_color(Color::red);
  c1.set_fill_color(Color::green);
  win.attach(c1);


  // ic1.move(0,300);
  c1.move(0,300);




  win.wait_for_button();
}	
