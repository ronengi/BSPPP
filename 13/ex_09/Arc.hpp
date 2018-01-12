#ifndef ARC_HPP
#define ARC_HPP


#include "/home/blanca/bs_ppp/bs_fltk/Simple_window.h"
#include "/home/blanca/bs_ppp/bs_fltk/Graph.h"


struct Arc : Shape {

  Arc(Point c, int rx, int ry, int a1, int a2);	// center, radius x, radius y, begin angle, end angle
  void draw_lines() const;
  Point center() const;

private:
  int _rx;	 // radius x
  int _ry;	 // radius y
  int _a1;	 // begin angle
  int _a2;	 // end angle
};




#endif
