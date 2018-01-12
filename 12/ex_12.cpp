#include <iostream>
#include <cmath>
#include "../bs_fltk/Simple_window.h"
#include "../bs_fltk/Graph.h"

using namespace std;

#define PI 3.14159265


int sgn(double d) {
  if (d > 0)    return 1;
  if (d < 0)    return -1;
  return 0;
}


int main() {
  using namespace Graph_lib;

  Simple_window win(Point(0, 0), 900, 800, "Superellipse");
  int x0 = win.x_max() / 2, y0 = win.y_max() / 2;

  Open_polyline se;
  double x, y, th, s_th, c_th, m = 0.5, n = 0.5, a = 200, b = 200, step = 0.1;


  cin >> a >> b >> m >> n >> step;


  for (th = 0; th <= 2 * PI; th += step) {
    c_th = cos(th);
    s_th = sin(th);

    x = x0 + pow(abs(c_th), (2.0 / m))  * a * sgn(c_th);

    y = y0 + pow(abs(s_th), (2.0 / n))  * b * sgn(s_th);

    se.add(Point(x, y));
    se.add(Point(x0, y0));
  }

  se.set_style(Line_style(Line_style::solid, 2));
  se.set_color(Color::blue);

  win.attach(se);


  win.wait_for_button();
}
