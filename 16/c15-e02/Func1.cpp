#include "/home/blanca/bs_ppp/bs_fltk/Simple_window.h"
#include "/home/blanca/bs_ppp/bs_fltk/Graph.h"

#include "Func1.hpp"

Func1::Func1(Fct f, double r1, double r2, Point orig, int count, double xscale, double yscale)
  : Function(f, r1, r2, orig, count, xscale, yscale),
    _f(f), _r1(r1), _r2(r2), _orig(orig), _count(count), _xscale(xscale), _yscale(yscale) {
}


void Func1::set_func(Fct f) {
  _f = f;
  reset();
}

void Func1::set_range(double r1, double r2) {
  _r1 = r1;
  _r2 = r2;
  reset();
}


void Func1::set_scale(double xscale, double yscale) {
  _xscale = xscale;
  _yscale = yscale;
  reset();
}

void Func1::reset() {
  clear_points();

  if (_r2-_r1<=0) error("bad graphing range");
  if (_count <=0) error("non-positive graphing count");
  double dist = (_r2-_r1)/_count;
  double r = _r1;
  for (int i = 0; i<_count; ++i) {
    add(Point(_orig.x+int(r*_xscale),_orig.y-int(_f(r)*_yscale)));
    r += dist;
  }
}
