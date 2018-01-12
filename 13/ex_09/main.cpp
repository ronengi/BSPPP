#include <cmath>
#define PI 3.141592654

#include "/home/blanca/bs_ppp/bs_fltk/Simple_window.h"
#include "/home/blanca/bs_ppp/bs_fltk/Graph.h"

#include "Regular_hexagon.hpp"

int main() {
  using namespace Graph_lib;

  Simple_window win(Point(100, 100), 800, 800, "Ex-09");

  Vector_ref<Regular_hexagon> htiles;
  int r = 40;
  int a = r * cos(PI / 6);
  int b = r * sin(PI / 6);

  int x = 0, y = 0;

  for (int i = 0; (i * (r + b)) < win.x_max(); ++i) {
    if (i % 2 == 0)
      y = 0;
    else
      y = a;
    for (int j = 0; (j * a * 2) < win.y_max(); ++j) {
      htiles.push_back(new Regular_hexagon(Point(x, y), r));
      htiles[htiles.size() - 1].set_style(Line_style(Line_style::solid, 2));
      htiles[htiles.size() - 1].set_color(Color::red);
      htiles[htiles.size() - 1].set_fill_color(Color::green);
      win.attach(htiles[htiles.size() - 1]);
      y += a * 2;
    }
    x += r + b;
  }


  win.wait_for_button();
}	
