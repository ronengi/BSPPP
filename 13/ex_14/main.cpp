#include <cmath>
#define PI 3.141592654

#include "/home/blanca/bs_ppp/bs_fltk/Simple_window.h"
#include "/home/blanca/bs_ppp/bs_fltk/Graph.h"

#include "Right_triangle.hpp"

int main() {
  using namespace Graph_lib;

  Simple_window win(Point(10, 10), 2500, 1700, "Ex-14");

  Right_triangle t1(Point(100, 700), Point(400, 100), Point(1346, 700));
  t1.set_style(Line_style(Line_style::solid, 2));
  t1.set_color(Color::red);
  t1.set_fill_color(Color::green);
  win.attach(t1);



  win.wait_for_button();
}	
