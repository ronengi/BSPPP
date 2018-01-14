#include "/home/blanca/bs_ppp/bs_fltk/Simple_window.h"
#include "/home/blanca/bs_ppp/bs_fltk/Graph.h"

#include "Binary_tree.hpp"



int main() {
  using namespace Graph_lib;

  Simple_window win(Point(10, 10), 1000, 800, "Ex-08");
  Binary_tree bt1(9);
  bt1.set_style(Line_style(Line_style::solid, 1));
  bt1.set_color(Color::blue);
  bt1.set_fill_color(Color::green);
  win.attach(bt1);


  win.wait_for_button();
}	
