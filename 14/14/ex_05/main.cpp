#include "/home/blanca/bs_ppp/bs_fltk/Simple_window.h"
#include "/home/blanca/bs_ppp/bs_fltk/Graph.h"

#include "Striped_rectangle.hpp"


int main() {
  using namespace Graph_lib;

  Simple_window win(Point(100, 100), 1000, 700, "ex-05");


  Striped_rectangle sr1(Point(200, 200), 250, 100);
  sr1.set_style(Line_style(Line_style::solid, 2));
  sr1.set_color(Color::red);
  sr1.set_fill_color(Color::green);
  win.attach(sr1);


  Rectangle r1(Point(600, 200), 200, 100);
  r1.set_style(Line_style(Line_style::solid, 2));
  r1.set_color(Color::red);
  r1.set_fill_color(Color::green);
  win.attach(r1);



  win.wait_for_button();
}	
