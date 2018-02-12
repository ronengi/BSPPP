#include "/home/blanca/bs_ppp/bs_fltk/Simple_window.h"
#include "/home/blanca/bs_ppp/bs_fltk/Graph.h"


#include "Clock.hpp"


using namespace Graph_lib;



int main() {

  Simple_window win(Point(100, 100), 1000, 800, "ex-06");

  Clock c1(Point(win.x_max() / 2, win.y_max() / 2), win.x_max() / 2, win.y_max() / 2);
  c1.set_style(Line_style(Line_style::solid, 3));
  c1.set_color(Color::blue);
  c1.set_fill_color(Color::white);
  win.attach(c1);




 
  win.wait_for_button();
}	
