#include "/home/blanca/bs_ppp/bs_fltk/Simple_window.h"
#include "/home/blanca/bs_ppp/bs_fltk/Graph.h"

#include "Func2.hpp"

Func2::Func2(Fct f, double r1, double r2, Point orig, int count, double xscale, double yscale)
  : _fff(new Function(f, r1, r2, orig, count, xscale, yscale)),
    _f(f), _r1(r1), _r2(r2), _orig(orig), _count(count), _xscale(xscale), _yscale(yscale) {
}

Func2::~Func2() {
  free(_fff);
}

void Func2::set_func(Fct f) {
  _f = f;
  reset();
}

void Func2::set_range(double r1, double r2) {
  _r1 = r1;
  _r2 = r2;
  reset();
}


void Func2::set_scale(double xscale, double yscale) {
  _xscale = xscale;
  _yscale = yscale;
  reset();
}


void Func2::reset() {
  free(_fff);
  _fff = new Function(_f, _r1, _r2, _orig, _count, _xscale, _yscale);
}


void Func2::draw_lines() const {
  _fff->set_color(color());
  _fff->set_style(style());

  _fff->draw();
}
