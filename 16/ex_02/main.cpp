#include "/home/blanca/bs_ppp/bs_fltk/Simple_window.h"
#include "/home/blanca/bs_ppp/bs_fltk/Graph.h"

#include "My_window.hpp"
#include "Button_board.hpp"



int main() {
  using namespace Graph_lib;

  My_window win(Point(100, 100), 1000, 800, "ex-02");

  // Out_box ob(Point(400,200), 100, 30, "");
  // win.attach(ob);
  // ob.put("hello");

  Button_board b1(4, 4, 100, 30);
  //win.attach(b1);
  b1.attach(win);

 
  win.wait_for_button();
}	
