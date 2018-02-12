//#include <iostream>

#include "Clock.hpp"


void Clock::callback(void* me) {
  //cout << "TICK\n";

  ((Clock *)me)->_s_hand.set_point(1, ((Clock *)me)->get_second());
  ((Clock *)me)->_m_hand.set_point(1, ((Clock *)me)->get_minute());
  ((Clock *)me)->_h_hand.set_point(1, ((Clock *)me)->get_hour());

  Fl::repeat_timeout(1.0, callback, ((Clock *)me));

  ((Clock *)me)->draw_lines();
  //Fl::run();
}




Clock::Clock(Point c, int rx, int ry)
  : Ellipse(c, rx, ry),
    _c(c), _rx(rx), _ry(ry),
    _hr(0.5), _mr(0.9), _sr(1) {



  _h_hand.add(_c, get_hour());
  _m_hand.add(_c, get_minute());
  _s_hand.add(_c, get_second());

  Fl::add_timeout(1.0, callback, this);

}



void Clock::draw_lines() const {
  Ellipse::draw_lines();	// draw clock
  _h_hand.draw_lines();		// draw hour
  _m_hand.draw_lines();		// draw minute
  _s_hand.draw_lines();		// draw second
}


Point Clock::get_hour() {
  int x, y, hour, minute;
  time_t rawtime;
  double t;

  time(&rawtime);
  hour = localtime(&rawtime)->tm_hour % 12;
  minute = localtime(&rawtime)->tm_min;

  t = double(hour) * PI / 6.0;
  t += double(minute) * PI / 360.0;

  x = _c.x + (_rx * _hr) * sin(t);
  y = _c.y - (_ry * _hr) * cos(t);


  // set hour hand's color and style
  _h_hand.set_color(color());
  _h_hand.set_style(style());

  return Point(x, y);
}

Point Clock::get_minute() {
  int x, y, minute;
  time_t rawtime;
  double t;

  time(&rawtime);
  minute = localtime(&rawtime)->tm_min;

  t = double(minute) * PI / 30.0;

  x = _c.x + (_rx * _mr) * sin(t);
  y = _c.y - (_ry * _mr) * cos(t);

  // set minute hand's color and style
  _m_hand.set_color(color());
  _m_hand.set_style(style());

  return Point(x, y);
}



Point Clock::get_second() {
  int x, y, second;
  time_t rawtime;
  double t;

  time(&rawtime);
  second = localtime(&rawtime)->tm_sec;

  t = double(second) * PI / 30.0;

  x = _c.x + (_rx * _sr) * sin(t);
  y = _c.y - (_ry * _sr) * cos(t);

  // set second hand's color and style
  _s_hand.set_color(color());
  _s_hand.set_style(style());

  return Point(x, y);
}


