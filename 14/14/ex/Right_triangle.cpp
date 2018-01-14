#include "Right_triangle.hpp"

#include <cmath>


Right_triangle::Right_triangle(Point p1, Point p2, Point p3) {
  double a, b, c, tmp;
  a = sqrt(pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2));
  b = sqrt(pow((p2.x - p3.x), 2) + pow((p2.y - p3.y), 2));
  c = sqrt(pow((p3.x - p1.x), 2) + pow((p3.y - p1.y), 2));

  if (c < a) {    tmp = a;    a = c;    c = tmp;  }
  if (c < b) {    tmp = b;    b = c;    c = tmp;  }

  if (pow(c, 2) != (pow(a, 2) + pow(b, 2)))
    throw runtime_error("not a right triangle");

  add(p1);
  add(p2);
  add(p3);
}


void Right_triangle::draw_lines() const {
  Polygon::draw_lines();
}
