#ifndef FUNC1_HPP
#define FUNC1_HPP

#include "/home/blanca/bs_ppp/bs_fltk/Simple_window.h"
#include "/home/blanca/bs_ppp/bs_fltk/Graph.h"


struct Func1 : Function {

  Func1(Fct f, double r1, double r2, Point orig, int count = 100, double xscale = 25, double yscale = 25);

  void set_func(Fct f);
  void set_range(double r1, double r2);
  void set_scale(double xscale, double yscale);



private:

  void reset();

  double (*_f)(double);		// Fct _f;
  double _r1;
  double _r2;
  Point _orig;
  int _count;
  double _xscale;
  double _yscale;
};




#endif
