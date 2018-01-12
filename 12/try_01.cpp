#include "../bs_fltk/Simple_window.h"
#include "../bs_fltk/Graph.h"

int main() {
  using namespace Graph_lib;

  Point tl(100, 100);
  Simple_window win(tl, 600,400, "Hello");
  Polygon poly;

  poly.add(Point(300, 200));
  poly.add(Point(350, 100));
  poly.add(Point(400, 200));

  poly.set_color(Color::red);

  win.attach(poly);
  win.wait_for_button();
}
