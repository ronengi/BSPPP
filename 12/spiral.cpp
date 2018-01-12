//#include <vector>
#include <cmath>
#include <unistd.h>

#include "../bs_fltk/Simple_window.h"
#include "../bs_fltk/Graph.h"


#define PI 3.14159265


int main() {
  using namespace Graph_lib;

  Simple_window win(Point(0, 0), 1000, 1000, "Spiral");

  // vector<Closed_polyline> p;

  // for (int i = 3; i < 6; ++i) {
  //   for (int j = 0; j < i; ++j) {
  //     // calculate coordinates for each point
  //     Closed_polyline tmp;
  //     tmp.add(Point(50,75));
  //     tmp.set_style(Line_style(Line_style::dash, 2));
  //     tmp.set_fill_color(Color::green);
  //   }
  //   p.push_back(tmp);
  // }

  // for (int i = 0; i < p.size(); ++i)
  //   win.attach(p[i]);



  Open_polyline p;
  double a = 0, r = 0;
  int x0 = win.x_max() / 2, y0 = win.y_max() / 2;
  int x, y;

  for (r = 0.1; r < win.x_max() / 2; r += 0.01) {
    x = x0 + sin(a) * r;
    y = y0 - cos(a) * r;
    p.add(Point(x, y));
    a += 1 / r;
    //p.draw();
    //sleep(50);
  }
  p.set_style(Line_style(Line_style::dash, 2));
  p.set_color(Color::blue);


  win.attach(p);


  win.wait_for_button();
}
