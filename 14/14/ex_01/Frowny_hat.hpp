#ifndef FROWNY_HAT_HPP
#define FROWNY_HAT_HPP


#include "/home/blanca/bs_ppp/bs_fltk/Simple_window.h"
#include "/home/blanca/bs_ppp/bs_fltk/Graph.h"

#include "Frowny.hpp"


class Frowny_hat : public Frowny {

public:
  Frowny_hat(Point p, int rr);
  void draw_lines() const;
};




#endif
