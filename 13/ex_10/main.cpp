#include <cmath>
#define PI 3.141592654

#include "/home/blanca/bs_ppp/bs_fltk/Simple_window.h"
#include "/home/blanca/bs_ppp/bs_fltk/Graph.h"

#include "Regular_polygon.hpp"

int main() {
  using namespace Graph_lib;

  Simple_window win(Point(100, 100), 800, 800, "Ex-10");

  Regular_polygon rp(Point(400, 400), 5, 300);
  rp.set_style(Line_style(Line_style::solid, 2));
  rp.set_color(Color::red);
  rp.set_fill_color(Color::green);
  win.attach(rp);



  win.wait_for_button();
}	
