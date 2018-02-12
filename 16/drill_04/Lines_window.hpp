#include "/home/blanca/bs_ppp/bs_fltk/Window.h"
#include "/home/blanca/bs_ppp/bs_fltk/Graph.h"
#include "/home/blanca/bs_ppp/bs_fltk/GUI.h"


struct Lines_window : Graph_lib::Window {
  Lines_window(Point xy, int w, int h, const string& title);


private:

  Graph_lib::Open_polyline lines;

  Graph_lib::Button next_button;
  Graph_lib::Button quit_button;
  Graph_lib::In_box next_x;
  Graph_lib::In_box next_y;
  Graph_lib::Out_box xy_out;

  Graph_lib::Menu color_menu;
  Graph_lib::Button color_menu_button;

  Graph_lib::Menu style_menu;
  Graph_lib::Button style_menu_button;




  static void cb_style_menu(Graph_lib::Address, Graph_lib::Address);
  void style_menu_pressed();


  static void cb_solid(Graph_lib::Address, Graph_lib::Address);
  void solid_pressed();

  static void cb_dash(Graph_lib::Address, Graph_lib::Address);
  void dash_pressed();

  static void cb_dot(Graph_lib::Address, Graph_lib::Address);
  void dot_pressed();



  static void cb_color_menu(Graph_lib::Address, Graph_lib::Address);
  void color_menu_pressed();


  static void cb_red(Graph_lib::Address, Graph_lib::Address);
  void red_pressed();

  static void cb_blue(Graph_lib::Address, Graph_lib::Address);
  void blue_pressed();

  static void cb_black(Graph_lib::Address, Graph_lib::Address);
  void black_pressed();



  static void cb_next(Graph_lib::Address, Graph_lib::Address);
  void next();

  static void cb_quit(Graph_lib::Address, Graph_lib::Address);
  void quit();

};
