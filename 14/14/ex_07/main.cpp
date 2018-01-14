#include "/home/blanca/bs_ppp/bs_fltk/Simple_window.h"
#include "/home/blanca/bs_ppp/bs_fltk/Graph.h"

#include "Striped_closed_polyline.hpp"


int main() {
  using namespace Graph_lib;

  Simple_window win(Point(100, 100), 1000, 700, "ex-05");


  Striped_closed_polyline scp1;
  //Closed_polyline scp1;
  scp1.add(Point(200, 200));
  scp1.add(Point(400, 400));
  scp1.add(Point(600, 200));
  scp1.add(Point(10, 10));
  scp1.add(Point(800, 700));
  scp1.add(Point(600, 400));
  scp1.add(Point(400, 200));
  scp1.add(Point(200, 400));

  scp1.set_style(Line_style(Line_style::solid, 2));
  scp1.set_color(Color::red);
  scp1.set_fill_color(Color::green);
  win.attach(scp1);


  // Closed_polyline cp1;
  // cp1.add(Point(700, 300));
  // cp1.add(Point(800, 400));
  // cp1.add(Point(900, 300));
  // cp1.add(Point(900, 400));
  // cp1.add(Point(800, 300));
  // cp1.add(Point(700, 400));


  // cp1.set_style(Line_style(Line_style::solid, 2));
  // cp1.set_color(Color::red);
  // cp1.set_fill_color(Color::green);
  // win.attach(cp1);



  win.wait_for_button();
}	
