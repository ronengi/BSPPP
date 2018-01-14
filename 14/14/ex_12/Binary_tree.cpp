#include <stdexcept>

#include "Binary_tree.hpp"



Binary_tree::Binary_tree(int levels)
  : _levels(levels) {

  if (_levels < 0)
    throw runtime_error("negative number of levels in tree");
}


void Binary_tree::draw_lines() const {
  int width = 1000, height = 800;
  if (_levels == 0)
    return;

  double y_step = double(height) / _levels;
  double x_step = double(width) / 2;
  int radius = y_step / (_levels * 2);
  double x, y;

  for (y = y_step / 2; y < height; y += y_step) {
    bool draw = true;

    for (x = x_step; x < width; x += x_step) {
      if (draw) {

	Circle c1(Point(x, y), radius);
	c1.set_color(color());
	c1.set_style(style());
	c1.set_fill_color(fill_color());
	c1. draw();

	if (height > y + y_step) {
	  Lines l1;
	  l1.add(Point(x, y), Point(x - x_step / 2, y + y_step));
	  l1.add(Point(x, y), Point(x + x_step / 2, y + y_step));
	  l1.set_color(color());
	  l1.set_style(style());
	  l1.set_fill_color(fill_color());
	  l1.draw();
	}

      }
      draw = !draw;
    }
    x_step /= 2;
  }


}
