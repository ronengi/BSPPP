#ifndef SMILEY_HAT_HPP
#define SMILEY_HAT_HPP


#include "/home/blanca/bs_ppp/bs_fltk/Simple_window.h"
#include "/home/blanca/bs_ppp/bs_fltk/Graph.h"

#include "Smiley.hpp"


class Smiley_hat : public Smiley {

public:
  Smiley_hat(Point p, int rr);
  void draw_lines() const;
};




#endif
