#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iostream>

#include "Striped_closed_polyline.hpp"


void Striped_closed_polyline::draw_lines() const {

  if (fill_color().visibility()) {
    fl_color(fill_color().as_int());
    fl_line_style(FL_SOLID, 1); // set style

    // find highest and lowest points, leftest and rightest points
    int y_min = point(0).y, y_max = point(0).y, x_min = point(0).x, x_max = point(0).x;
    for (int i = 1; i < number_of_points(); ++i) {
      y_min = (point(i).y < y_min) ? point(i).y : y_min;
      y_max = (point(i).y > y_max) ? point(i).y : y_max;
      x_min = (point(i).x < x_min) ? point(i).x : x_min;
      x_max = (point(i).x > x_max) ? point(i).x : x_max;
    }

    for (int y = y_min; y < y_max; y += 3) {
      vector<int> xn;
      Point p1, p2;
      int x;
      double a, b;

      xn.clear();

      // for every line in the polyline
      for(int i = 0; i < number_of_points(); ++i) {
      	p1 = point(i);
      	p2 = (i < number_of_points() - 1) ? point(i + 1) : point(0);

      	// if line is not vertical && intersects y
      	if ( (p1.y != p2.y)  &&  ((p1.y < y  &&  y <= p2.y)  ||  (p2.y < y  &&  y <= p1.y)) ) {

      	  // calc intersection's x and store :
      	  if (p1.x == p2.x)	// line is horizontal
      	    x = p1.x;
      	  else {		// line is diagonal
      	    a = double(p2.y - p1.y) / double(p2.x - p1.x);
      	    b = p1.y - a * p1.x;
      	    x = (y - b) / a;
      	  }
      	  xn.push_back(x);
      	}
      }

      if (!xn.empty()) {
	sort(xn.begin(), xn.end()); // sort all x's from left to right
	for (int ix = 0; ix < xn.size() - 1; ++ix) { // draw the lines : draw every second section
	  if (ix %2 == 0)	    fl_line(xn[ix], y, xn[ix + 1], y);
	}
      }

    }




    fl_line_style(0);		// reset line style to default
    fl_color(color().as_int());	// reset color
  }
    
  if (color().visibility()) {
    Shape::draw_lines();
    fl_line(point(number_of_points()-1).x, point(number_of_points()-1).y, point(0).x, point(0).y); // draw closing line
  }

}
