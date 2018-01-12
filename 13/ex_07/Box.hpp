#ifndef BOX_HPP
#define BOX_HPP


#include "/home/blanca/bs_ppp/bs_fltk/Simple_window.h"
#include "/home/blanca/bs_ppp/bs_fltk/Graph.h"


struct Box : Lines {

  Box(Point tl, int w, int h, int aw, int ah);
  void draw_lines() const;

private:
  Point _tl;			// top left corner
  int _w;			// width
  int _h;			// height
  int _aw;			// arc's width
  int _ah;			// arc's height
};




#endif
