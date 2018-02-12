#ifndef BUTTON_BOARD_HPP
#define BUTTON_BOARD_HPP


#include "/home/blanca/bs_ppp/bs_fltk/Simple_window.h"
#include "/home/blanca/bs_ppp/bs_fltk/Graph.h"

#include <FL/Fl_Button.H>

#include <vector>
#include <sstream>

class Button_board {

public:
  Button_board(int rows, int cols, int bw, int bh);
  ~Button_board();

  void attach(Graph_lib::Window& win);


private:

  static void cb_push(Address, Address);
  void push(void *pb);

  Graph_lib::Window* own;
  Fl_Button *prev_b;
  Fl_Color prev_c;
  string prev_l;

  Out_box ob;
  vector<Button *> _buttons;
  int _rows;
  int _cols;
  int _bw;
  int _bh;
};


#endif
