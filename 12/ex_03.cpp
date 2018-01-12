#include "../bs_fltk/Simple_window.h"
#include "../bs_fltk/Graph.h"

int main() {
  using namespace Graph_lib;

  Point tl(100, 100);

  Simple_window win(tl, 600,400, "ex_03");


  Text t1(Point(150,200), "R");
  t1.set_font_size(20);
  t1.set_color(Color::dark_red);
  t1.set_font(Graph_lib::Font::times_bold);


  Text t2(Point(171,200), "G");
  t2.set_font_size(20);
  t2.set_color(Color::blue);

  Text t3(Point(192,200), "R");
  t3.set_font_size(20);
  t3.set_color(Color::green);


  win.attach(t1);
  win.attach(t2);
  win.attach(t3);

  win.wait_for_button();
}
