#ifndef ARROW_HPP
#define ARROW_HPP


#include "/home/blanca/bs_ppp/bs_fltk/Simple_window.h"
#include "/home/blanca/bs_ppp/bs_fltk/Graph.h"


struct Arrow : Lines {

  Arrow(Point head, Point tail, int w, int l, string name);
  void draw_lines() const;

private:
  Point H;			// head
  Point T;			// tail
  int ww;			// head's width (at widest part)
  int ll;			// head's length
  string _name;
};




#endif
