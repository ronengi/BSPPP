#include "../bs_fltk/Simple_window.h"
#include "../bs_fltk/Graph.h"

int main() {
  using namespace Graph_lib;

  Point tl(100, 100);

  Simple_window win(tl, 600,600, "ex_04");

  Rectangle r1(Point(100, 100), 100, 100);
  r1.set_fill_color(Color::red);

  Rectangle r2(Point(200, 100), 100, 100);
  r2.set_fill_color(Color::white);

  Rectangle r3(Point(300, 100), 100, 100);
  r3.set_fill_color(Color::red);



  Rectangle r4(Point(100, 200), 100, 100);
  r4.set_fill_color(Color::white);

  Rectangle r5(Point(200, 200), 100, 100);
  r5.set_fill_color(Color::red);

  Rectangle r6(Point(300, 200), 100, 100);
  r6.set_fill_color(Color::white);


  Rectangle r7(Point(100, 300), 100, 100);
  r7.set_fill_color(Color::red);

  Rectangle r8(Point(200, 300), 100, 100);
  r8.set_fill_color(Color::white);

  Rectangle r9(Point(300, 300), 100, 100);
  r9.set_fill_color(Color::red);


  win.attach(r1);
  win.attach(r2);
  win.attach(r3);
  win.attach(r4);
  win.attach(r5);
  win.attach(r6);
  win.attach(r7);
  win.attach(r8);
  win.attach(r9);

  win.wait_for_button();
}
