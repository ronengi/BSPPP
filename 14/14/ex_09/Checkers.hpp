#ifndef CHECKERS_HPP
#define CHECKERS_HPP

#include "/home/blanca/bs_ppp/bs_fltk/Simple_window.h"
#include "/home/blanca/bs_ppp/bs_fltk/Graph.h"

#include "Group.hpp"


class Checkers : public Group {
public:
  Checkers(Point pp, int size);
  ~Checkers();

  void paint_pieces();

private:
  bool pieces[8][8];
};





#endif
