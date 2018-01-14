#include "Checkers.hpp"


Checkers::Checkers(Point pp, int size) {
  for (int i = 0; i < 8; ++i) {
    for (int j = 0; j < 8; ++j) {
      add_shape(*(new Rectangle(Point(i * size, j * size), size, size)));
      pieces[i][j] = false;
    }
  }
  move(pp.x, pp.y);
  pieces[7][1] = true;
}


Checkers::~Checkers() {
  for (int i = 0; i < shapes.size(); ++i)
    delete(&shapes[i]);
}


void Checkers::paint_pieces() {
  for (int i = 0; i < 8; ++i) {
    for (int j = 0; j < 8; ++j) {
      if (pieces[i][j])
	shapes[i + j * 8].set_color(Color::blue);
      else
	shapes[i + j * 8].set_color(this->color());
    }
  }
}
