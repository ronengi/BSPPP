#include <cmath>
//#include <unistd.h>

#include "../bs_fltk/Simple_window.h"
#include "../bs_fltk/Graph.h"
#include "../bs_fltk/Graph.h"


#define PI 3.14159265


int main() {
  using namespace Graph_lib;

  Simple_window win(Point(0, 0), 900, 800, "Polygons");
  int x0 = win.x_max() / 2, y0 = win.y_max() / 2;
  int r = 50;

  Circle *c;
  Polygon *p;
  double a = 0;
  int x, y;

  for (int i = 3; i < 20; ++i, r += 20) {

    c = new Circle(Point(x0,y0), r);
    (*c).set_color(Color::green);
    p = new Polygon;
    (*p).set_style(Line_style(Line_style::solid, 2));
    (*p).set_color(Color::blue);
    for (int j = 0; j < i; ++j) {
      x = x0 + sin(a) * r;
      y = y0 - cos(a) * r;
      (*p).add(Point(x, y));
      a += 2 * PI / i;
    }
    win.attach(*p);
    win.attach(*c);

  }



  win.wait_for_button();
}
