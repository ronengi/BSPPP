#include <stdexcept>

#include "Binary_tree.hpp"
#include "Arrow.hpp"


Binary_tree::Binary_tree(int levels)
  : _levels(levels), _connector(0) {

  if (_levels < 0)    throw runtime_error("negative number of levels in tree");
}


Binary_tree::Binary_tree(int levels, int connector)
  : _levels(levels), _connector(connector) {

  if (_levels < 0)    throw runtime_error("negative number of levels in tree");
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
	  Point root(x, y);
	  Point left(x - x_step / 2, y + y_step);
	  Point right(x + x_step / 2, y + y_step);

	  Point HL, TL, HR, TR;
	  int ww, ll;

	  switch(_connector) {
	  case 1:
	    TL = TR = root;
	    HL = left;
	    HR = right;
	    ww = 30;
	    ll = 40;
	    break;
	  case 2:
	    HL = HR = root;
	    TL = left;
	    TR = right;
	    ww = 30;
	    ll = 40;
	    break;
	  default:
	    TL = TR = root;
	    HL = left;
	    HR = right;
	    ww = 0;
	    ll = 0;
	    break;
	  }


	  Arrow a_left(HL, TL, ww, ll, "arrow");
	  a_left.set_color(color());
	  a_left.set_style(style());
	  a_left.set_fill_color(fill_color());
	  a_left.draw();

	  Arrow a_right(HR, TR, ww, ll, "arrow");
	  a_right.set_color(color());
	  a_right.set_style(style());
	  a_right.set_fill_color(fill_color());
	  a_right.draw();
	}

      }
      draw = !draw;
    }
    x_step /= 2;
  }


}
