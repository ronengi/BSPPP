#include "Octagon.hpp"

#include <cmath>

#define PI 3.141592654


Octagon::Octagon(Point center, int radius)
  : _center(center), _radius(radius) {

  static const double angle = PI / 2; // configure the rotation of the hexagon

  for (double a = angle; a < 2 * PI + angle; a += PI / 4)
    add(Point(_center.x + sin(a) * _radius, _center.y + cos(a) * _radius));
}


void Octagon::draw_lines() const {
  Polygon::draw_lines();
}
