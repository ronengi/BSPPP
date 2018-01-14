#include "Shape_controller.hpp"

Shape_controller::Shape_controller(Shape& sp)
  : _sp(sp) {}

void Shape_controller::on() {
  Color c1(_sp.color()), fc1(_sp.fill_color());
  c1.set_visibility(Color::visible);
  fc1.set_visibility(Color::visible);
  _sp.set_color(c1);
  _sp.set_fill_color(fc1);
}

void Shape_controller::off() {
  Color c1(_sp.color()), fc1(_sp.fill_color());
  c1.set_visibility(Color::invisible);
  fc1.set_visibility(Color::invisible);
  _sp.set_color(c1);
  _sp.set_fill_color(fc1);
}

void Shape_controller::set_level(int l) {
  _sp.set_style(Line_style(Line_style::solid, l));
}

void Shape_controller::show() {
}
