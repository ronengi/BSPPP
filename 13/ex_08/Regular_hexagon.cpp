#include "Regular_hexagon.hpp"

#include <cmath>

#define PI 3.141592654


Regular_hexagon::Regular_hexagon(Point center, int radius)
  : _center(center), _radius(radius) {

  static const double angle = PI / 2; // configure the rotation of the hexagon

  for (double a = angle; a < 2 * PI + angle; a += PI / 3)
    add(Point(_center.x + sin(a) * _radius, _center.y + cos(a) * _radius));
}


void Regular_hexagon::draw_lines() const {
  Polygon::draw_lines();
}
