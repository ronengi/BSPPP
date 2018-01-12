#include "../bs_fltk/Simple_window.h"
#include "../bs_fltk/Graph.h"

int main() {
  using namespace Graph_lib;

  Point tl(100, 100);

  Simple_window win(tl, 600,400, "ex_01");


  Rectangle r1(Point(100,100), 100, 50);
  r1.set_fill_color(Color::yellow);


  Closed_polyline p1;
  p1.add(Point(100,200));
  p1.add(Point(100,250));
  p1.add(Point(200,250));
  p1.add(Point(200,200));

  p1.set_style(Line_style(Line_style::dash, 2));
  p1.set_fill_color(Color::green);



  win.attach(r1);
  win.attach(p1);


  win.wait_for_button();
}
