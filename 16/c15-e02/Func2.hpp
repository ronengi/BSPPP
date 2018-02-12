#ifndef FUNC2_HPP
#define FUNC2_HPP

#include "/home/blanca/bs_ppp/bs_fltk/Simple_window.h"
#include "/home/blanca/bs_ppp/bs_fltk/Graph.h"


struct Func2 : Shape {

  Func2(Fct f, double r1, double r2, Point orig, int count = 100, double xscale = 25, double yscale = 25);
  ~Func2();

  void set_func(Fct f);
  void set_range(double r1, double r2);
  void set_scale(double xscale, double yscale);

  void draw_lines() const;


private:
  void reset();

  Function *_fff;
  double (*_f)(double);		// Fct _f;
  double _r1;
  double _r2;
  Point _orig;
  int _count;
  double _xscale;
  double _yscale;
};




#endif
