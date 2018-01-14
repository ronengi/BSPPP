#include "/home/blanca/bs_ppp/bs_fltk/Simple_window.h"
#include "/home/blanca/bs_ppp/bs_fltk/Graph.h"

#include "Striped_circle.hpp"


int main() {
  using namespace Graph_lib;

  Simple_window win(Point(100, 100), 1000, 700, "ex-05");


  Striped_circle sc1(Point(250, 300), 150);
  sc1.set_style(Line_style(Line_style::solid, 2));
  sc1.set_color(Color::red);
  sc1.set_fill_color(Color::green);
  win.attach(sc1);


  Circle c1(Point(650, 300), 100);
  c1.set_style(Line_style(Line_style::solid, 2));
  c1.set_color(Color::red);
  c1.set_fill_color(Color::green);
  win.attach(c1);



  win.wait_for_button();
}	
