#include "Regular_polygon.hpp"

#include <stdexcept>
#include <cmath>

#define PI 3.141592654


Regular_polygon::Regular_polygon(Point center, int sides, int radius)
  : _center(center), _sides(sides), _radius(radius) {

  if (_sides < 3)
    throw runtime_error("polygon must have more than 2 sides");

  static const double angle = PI / 2; // configure the rotation of the polygon

  for (double a = angle; a < 2 * PI + angle; a += (2 * PI / _sides))
    add(Point(_center.x + sin(a) * _radius, _center.y + cos(a) * _radius));
}


void Regular_polygon::draw_lines() const {
  Polygon::draw_lines();
}
