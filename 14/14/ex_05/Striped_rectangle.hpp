#ifndef STRIPED_RECTANGLE_HPP
#define STRIPED_RECTANGLE_HPP


#include "/home/blanca/bs_ppp/bs_fltk/Simple_window.h"
#include "/home/blanca/bs_ppp/bs_fltk/Graph.h"


class Striped_rectangle : public Rectangle {

public:
  Striped_rectangle(Point xy, int ww, int hh);
  Striped_rectangle(Point x, Point y);

  void draw_lines() const;

};




#endif
