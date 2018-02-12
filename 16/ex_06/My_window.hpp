#ifndef MY_WINDOW_HPP
#define MY_WINDOW_HPP

#include "/home/blanca/bs_ppp/bs_fltk/Simple_window.h"
#include "/home/blanca/bs_ppp/bs_fltk/Graph.h"


using namespace Graph_lib;


class My_window : public Simple_window {

public:
  My_window(Point xy, int w, int h, const string& title );



private:
  Button quit_button;     // the "quit" button

  static void cb_quit(Address, Address pw) { // callback for next_button
    reference_to<My_window>(pw).quit();
  }
  void quit() {  exit(0);  } // action to be done when quit_button is pressed

};




#endif
