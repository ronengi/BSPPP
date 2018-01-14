//#include <cmath>

#include "/home/blanca/bs_ppp/bs_fltk/Simple_window.h"
#include "/home/blanca/bs_ppp/bs_fltk/Graph.h"

#include "Binary_tree.hpp"
#include "Arrow.hpp"

#define PI 3.141592654


int main() {
  using namespace Graph_lib;

  Simple_window win(Point(10, 10), 1000, 800, "Ex-13");


  Binary_tree bt1(5, 1);
  bt1.set_style(Line_style(Line_style::solid, 1));
  bt1.set_color(Color::blue);
  bt1.set_fill_color(Color::green);
  win.attach(bt1);


  // Arrow a1(Point(300, 200), Point(700, 500), 100, 100, "arrow"); // H, T, ww, ll, name
  // a1.set_style(Line_style(Line_style::solid, 5));
  // a1.set_color(Color::blue);
  // a1.set_fill_color(Color::green);
  // win.attach(a1);


  // Point center(500, 400);
  // Vector_ref<Shape> arrows;
  // Arrow *pa;
  // int r1 = 50, r2 = 51;
  // int ww = 1, ll = 1;
  // double aa = 0;
  // for (aa = 0; aa < 6 * PI; aa += 0.3) {
  //   pa = new Arrow(Point(center.x+r2*cos(aa) ,center.y-r2*sin(aa)), Point(center.x+r1*cos(aa) ,center.y-r1*sin(aa)), ww, ll, "arrow"); // H, T, ww, ll, name
  //   win.attach(*pa);
  //   arrows.push_back(pa);
  //   r2 += 5;
  //   ww += 2;
  //   ll += 2;
  // }

  win.wait_for_button();

}	
