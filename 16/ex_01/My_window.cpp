#include "My_window.hpp"


//using namespace Graph_lib;


My_window::My_window(Point xy, int w, int h, const string& title )
  : Simple_window(xy, w, h, title),
    quit_button(Point(x_max()-70,20), 70, 20, "Quit", cb_quit)

{
  attach(quit_button);

}

