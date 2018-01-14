#ifndef GROUP_HPP
#define GROUP_HPP


#include "/home/blanca/bs_ppp/bs_fltk/Simple_window.h"
#include "/home/blanca/bs_ppp/bs_fltk/Graph.h"


class Group : public Shape {

public:
  void draw_lines() const;

  void set_colors(Color cc);
  void move(int dx, int dy);
  void add_shape(Shape& s1);

protected:
  Vector_ref<Shape> shapes;
};





#endif
