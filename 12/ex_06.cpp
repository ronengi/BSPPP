#include "../bs_fltk/Simple_window.h"
#include "../bs_fltk/Graph.h"

int main() {
  using namespace Graph_lib;

  Simple_window win(Point(0, 0), x_max() +200, y_max() - 1, "ex_06");

  Rectangle r1(Point(100, 100), x_max() + 200, y_max() - 1);

  win.attach(r1);

  win.wait_for_button();
}
