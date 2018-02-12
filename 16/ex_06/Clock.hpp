#ifndef CLOCK_HPP
#define CLOCK_HPP


#include "/home/blanca/bs_ppp/bs_fltk/Simple_window.h"
#include "/home/blanca/bs_ppp/bs_fltk/Graph.h"

#include <ctime>
#include <cmath>

#define PI 3.141592654

// #include <vector>
// #include <sstream>


class Clock : public Ellipse {

public:
  Clock(Point c, int rx, int ry);



  void draw_lines() const;



  Lines _h_hand;
  Lines _m_hand;
  Lines _s_hand;


private:

  static void callback(void*);

  Point get_hour();
  Point get_minute();
  Point get_second();


  double _hr;
  double _mr;
  double _sr;

  Point _c;
  int _rx;
  int _ry;
};


#endif
