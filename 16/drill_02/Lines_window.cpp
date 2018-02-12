#include "Lines_window.hpp"


Lines_window::Lines_window(Point xy, int w, int h, const string& title)
  : Window(xy, w, h, title),
    next_button(Point(x_max()-150, 0), 70, 20, "Next point", cb_next),
    quit_button(Point(x_max()-70, 0), 70, 20, "Quit", cb_quit),
    next_x(Point(x_max()-310, 0), 50, 20, "next x:"),
    next_y(Point(x_max()-210, 0), 50, 20, "next y:"),
    xy_out(Point(100, 0), 100, 20, "current (x,y):") {

  attach(next_button);
  attach(quit_button);
  attach(next_x);
  attach(next_y);
  attach(xy_out);
  attach(lines);
}

void Lines_window::cb_quit(Graph_lib::Address, Graph_lib::Address pw) {
  Graph_lib::reference_to<Lines_window>(pw).quit();
}
void Lines_window::quit() {
  hide();
}

void Lines_window::cb_next(Graph_lib::Address, Graph_lib::Address pw) {
  Graph_lib::reference_to<Lines_window>(pw).next();
}
void Lines_window::next() {
  int x = next_x.get_int();
  int y = next_y.get_int();
  lines.add(Point(x, y));

  ostringstream ss;
  ss << '(' << x << ',' << y << ')';
  xy_out.put(ss.str());

  redraw();
}






/*
  Open_polyline lines;

  Button next_button;
  Button quit_button;
  In_box next_x;
  In_box next_y;
  Out_box xy_out;
*/
