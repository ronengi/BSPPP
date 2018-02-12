#include "/home/blanca/bs_ppp/bs_fltk/Simple_window.h"
#include "/home/blanca/bs_ppp/bs_fltk/Graph.h"

#include "Func1.hpp"
#include "Func2.hpp"



int main() {
  using namespace Graph_lib;

  Simple_window win(Point(100, 100), 1000, 800, "Ex-13");

  Func2 f1(cos, -10, 11, Point(500, 400)); //, 100, 25, 25);

  f1.set_style(Line_style(Line_style::solid, 5));
  f1.set_color(Color::blue);
  win.attach(f1);

  win.wait_for_button();

  f1.set_range(-15, 16);
  win.wait_for_button();

  f1.set_scale(10, 10);
  win.wait_for_button();

  f1.set_func(sin);
  win.wait_for_button();
}	
