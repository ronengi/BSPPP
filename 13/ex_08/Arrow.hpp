#ifndef ARROW_HPP
#define ARROW_HPP


#include "/home/blanca/bs_ppp/bs_fltk/Simple_window.h"
#include "/home/blanca/bs_ppp/bs_fltk/Graph.h"


struct Arrow : Lines {

  Arrow(Point head, Point tail, int hw, int hl);
  void draw_lines() const;

private:
  Point _head;			// head
  Point _tail;			// tail
  int _hw;			// head's width (at widest part)
  int _hl;			// head's length
};




#endif
