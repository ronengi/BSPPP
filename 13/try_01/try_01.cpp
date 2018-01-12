#include "../bs_fltk/Simple_window.h"
#include "../bs_fltk/Graph.h"


int main() {
  using namespace Graph_lib;

  Simple_window win(Point(0, 0), 900, 800, "Rectangles");
  int a = win.x_max() / 16;
  int b = win.y_max() / 16;

  Vector_ref<Rectangle> vr;

  for (int i = 0; i < 16; ++i) {
    for (int j = 0; j < 16; ++j) {
      vr.push_back(new Rectangle(Point(i * a, j * b), a, b));
      vr[vr.size() - 1].set_style(Line_style(Line_style::solid, 1));
      vr[vr.size() - 1].set_fill_color(Color(i * 16 + j));
      win.attach(vr[vr.size() - 1]);
    }
  }

  win.wait_for_button();
}
