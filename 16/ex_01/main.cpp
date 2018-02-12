#include "/home/blanca/bs_ppp/bs_fltk/Simple_window.h"
#include "/home/blanca/bs_ppp/bs_fltk/Graph.h"

#include "My_window.hpp"




int main() {
  using namespace Graph_lib;

  My_window win(Point(100, 100), 1000, 800, "ex-01");

  win.wait_for_button();

  win.wait_for_button();
}	
