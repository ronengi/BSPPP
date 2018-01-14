#include "Group.hpp"


void Group::draw_lines() const {
  for (int i = 0; i < shapes.size(); ++i)
    shapes[i].draw();
}

void Group::move(int dx, int dy) {
  for (int i = 0; i < shapes.size(); ++i) 
    shapes[i].move(dx, dy);
}


void Group::add_shape(Shape& s1) {
  shapes.push_back(s1);
}


void Group::set_colors(Color cc) {
  set_color(cc);
  for (int i = 0; i < shapes.size(); ++i) 
    shapes[i].set_color(cc);
}
