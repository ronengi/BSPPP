#include "../bs_fltk/Simple_window.h"
#include "../bs_fltk/Graph.h"

int main() {
  using namespace Graph_lib;

  Point tl(100, 100);

  Simple_window win(tl, 600,400, "ex_01");


  Rectangle r1(Point(100,100), 100, 30);

  Text t1(Point(130,120), "Howdy!");
  t1.set_font_size(12);

  win.attach(r1);
  win.attach(t1);

  win.wait_for_button();
}
