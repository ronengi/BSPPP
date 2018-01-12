#include <cmath>
#define PI 3.141592654

#include "/home/blanca/bs_ppp/bs_fltk/Simple_window.h"
#include "/home/blanca/bs_ppp/bs_fltk/Graph.h"

#include "Regular_hexagon.hpp"

int main() {
  using namespace Graph_lib;

  Simple_window win(Point(100, 100), 800, 800, "Ex-08");

  Regular_hexagon rh(Point(400, 400), 300);
  rh.set_style(Line_style(Line_style::solid, 2));
  rh.set_color(Color::red);
  rh.set_fill_color(Color::green);
  win.attach(rh);



  win.wait_for_button();
}	
