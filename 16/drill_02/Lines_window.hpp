#include "/home/blanca/bs_ppp/bs_fltk/Window.h"
#include "/home/blanca/bs_ppp/bs_fltk/Graph.h"
#include "/home/blanca/bs_ppp/bs_fltk/GUI.h"


struct Lines_window : Graph_lib::Window {
  Lines_window(Point xy, int w, int h, const string& title);
  Graph_lib::Open_polyline lines;

private:
  Graph_lib::Button next_button;
  Graph_lib::Button quit_button;
  Graph_lib::In_box next_x;
  Graph_lib::In_box next_y;
  Graph_lib::Out_box xy_out;

  static void cb_next(Graph_lib::Address, Graph_lib::Address);
  void next();
  static void cb_quit(Graph_lib::Address, Graph_lib::Address);
  void quit();
};
