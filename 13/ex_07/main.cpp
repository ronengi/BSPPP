#include <cmath>
#define PI 3.141592654

#include "/home/blanca/bs_ppp/bs_fltk/Simple_window.h"
#include "/home/blanca/bs_ppp/bs_fltk/Graph.h"


int main() {
  using namespace Graph_lib;
  Simple_window win(Point(10, 10), 2100, 1200, "Ex-07");
  static const int s = 256;
  int xl = 1;
  int yl = 1;
  unsigned long int c = 0;
  unsigned int cstep = 0xFFFFFFFF / (win.x_max() * win.y_max()) + 1;

  Vector_ref<Rectangle> tab;

  for (int i = 0; i < win.x_max(); i += xl) {
    for (int j = 0; j < win.y_max(); j += yl) {
      tab.push_back(new Rectangle(Point(i, j), xl, yl));
      tab[tab.size() - 1].set_fill_color(Color(c));
      tab[tab.size() - 1].set_color(Color::invisible);
      win.attach(tab[tab.size() - 1]);
      c += cstep;
    }
  }

  win.wait_for_button();
}	
