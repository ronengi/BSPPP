#include "/home/blanca/bs_ppp/bs_fltk/Simple_window.h"
#include "/home/blanca/bs_ppp/bs_fltk/Graph.h"

#include "Smiley.hpp"
#include "Frowny.hpp"
#include "Smiley_hat.hpp"
#include "Frowny_hat.hpp"


int main() {
  using namespace Graph_lib;

  Simple_window win(Point(100, 100), 1000, 700, "ex-01");


  Smiley s1(Point(250, 200), 100);
  s1.set_style(Line_style(Line_style::solid, 2));
  s1.set_color(Color::red);
  s1.set_fill_color(Color::green);
  win.attach(s1);


  Frowny f1(Point(750, 200), 100);
  f1.set_style(Line_style(Line_style::solid, 2));
  f1.set_color(Color::red);
  f1.set_fill_color(Color::green);
  win.attach(f1);


  Smiley_hat sh1(Point(250, 500), 100);
  sh1.set_style(Line_style(Line_style::solid, 2));
  sh1.set_color(Color::red);
  sh1.set_fill_color(Color::green);
  win.attach(sh1);


  Frowny_hat fh1(Point(750, 500), 100);
  fh1.set_style(Line_style(Line_style::solid, 2));
  fh1.set_color(Color::red);
  fh1.set_fill_color(Color::green);
  win.attach(fh1);



  win.wait_for_button();
}	
