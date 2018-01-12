#include "../bs_fltk/Simple_window.h"
#include "../bs_fltk/Graph.h"

int main() {
  using namespace Graph_lib;

  Simple_window win(Point(200, 100), 900, 430, "Olympic Rings");



  Circle c1(Point(150, 150), 130);
  c1.set_style(Line_style(Line_style::solid, 25));
  c1.set_color(Color::blue);

  Circle c2(Point(450, 150), 130);
  c2.set_style(Line_style(Line_style::solid, 25));
  c2.set_color(Color::black);

  Circle c3(Point(750, 150), 130);
  c3.set_style(Line_style(Line_style::solid, 25));
  c3.set_color(Color::red);

  Circle c4(Point(300, 280), 130);
  c4.set_style(Line_style(Line_style::solid, 25));
  c4.set_color(Color::yellow);

  Circle c5(Point(600, 280), 130);
  c5.set_style(Line_style(Line_style::solid, 25));
  c5.set_color(Color::green);








  win.attach(c1);
  win.attach(c2);
  win.attach(c3);
  win.attach(c4);
  win.attach(c5);


  win.wait_for_button();
}
