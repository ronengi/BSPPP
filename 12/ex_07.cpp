#include "../bs_fltk/Simple_window.h"
#include "../bs_fltk/Graph.h"

int main() {
  using namespace Graph_lib;

  Simple_window win(Point(100, 100), 800, 600, "ex_07");

  Rectangle r1(Point(100, 100), 300, 300); // house
  Rectangle r2(Point(120, 150), 70, 70);   // window 1
  Rectangle r3(Point(300, 150), 70, 70);   // window 2
  Closed_polyline p1;		// roof
  p1.add(Point(100,100));
  p1.add(Point(400,100));
  p1.add(Point(250,70));
  Rectangle r4(Point(200, 250), 70, 150);   // door
  Rectangle r5(Point(330, 10), 20, 80);   // chimney


  r1.set_style(Line_style(Line_style::solid, 2));
  r2.set_style(Line_style(Line_style::solid, 2));
  r3.set_style(Line_style(Line_style::solid, 2));
  p1.set_style(Line_style(Line_style::solid, 2));
  r4.set_style(Line_style(Line_style::solid, 2));
  r5.set_style(Line_style(Line_style::solid, 2));


  win.attach(r1);
  win.attach(r2);
  win.attach(r3);
  win.attach(p1);
  win.attach(r4);
  win.attach(r5);

  win.wait_for_button();
}
