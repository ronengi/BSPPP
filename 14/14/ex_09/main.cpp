#include "/home/blanca/bs_ppp/bs_fltk/Simple_window.h"
#include "/home/blanca/bs_ppp/bs_fltk/Graph.h"

#include "Checkers.hpp"



int main() {
  using namespace Graph_lib;

  Simple_window win(Point(10, 10), 1000, 800, "Ex-08");

  Checkers board1(Point(150, 90), 80);
  board1.set_colors(Color::red);
  board1.paint_pieces();


  win.attach(board1);

  win.wait_for_button();
}	
