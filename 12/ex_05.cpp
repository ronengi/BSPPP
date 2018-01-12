#include "../bs_fltk/Simple_window.h"
#include "../bs_fltk/Graph.h"

int main() {
  using namespace Graph_lib;

  Simple_window win(Point(0, 0), x_max() - 1, y_max() - 1, "ex_05");

  Rectangle r1(Point(100, 100), (x_max() - 1) * 2 / 3, (y_max() - 1) * 3 / 4);

  r1.set_style(Line_style(Line_style::solid, 10));
  r1.set_color(Color::red);


  win.attach(r1);

  win.wait_for_button();
}
