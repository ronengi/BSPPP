#include <cmath>
#define PI 3.141592654

#include "/home/blanca/bs_ppp/bs_fltk/Simple_window.h"
#include "/home/blanca/bs_ppp/bs_fltk/Graph.h"

#include "Octagon.hpp"

void test(Shape& s1) {
  s1.move(100, 100);
  s1.set_color(Color::blue);
  s1.set_style(Line_style(Line_style::dash, 5));
  s1.set_fill_color(Color::yellow);
}

int main() {
  using namespace Graph_lib;

  Simple_window win(Point(10, 10), 1000, 800, "Ex-08");

  Octagon o1(Point(500, 400), 200);
  o1.set_style(Line_style(Line_style::solid, 2));
  o1.set_color(Color::red);
  o1.set_fill_color(Color::green);
  win.attach(o1);

  win.wait_for_button();

  test(o1);

  win.wait_for_button();
}	
