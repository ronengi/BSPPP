#include "../bs_fltk/Simple_window.h"
#include "../bs_fltk/Graph.h"

int main() {
  using namespace Graph_lib;

  Point tl(100, 100);

  Simple_window win(tl, 600,400, "Hello");

  Polygon poly;
  poly.add(Point(300, 200));
  poly.add(Point(350, 100));
  poly.add(Point(400, 200));
  poly.set_color(Color::red);
  poly.set_style(Line_style(Line_style::dash, 4));


  Axis xa(Axis::x, Point(20,300), 280, 10, "x-axis");
  xa.label.set_font_size(12);


  Axis ya(Axis::y, Point(20,300), 280, 10, "y-axis");
  ya.set_color(Color::cyan);
  ya.label.set_color(Color::dark_red);
  ya.label.set_font_size(12);

  Function sine(sin, 0, 100, Point(20, 150), 1000, 50, 50);
  sine.set_color(Color::blue);


  Rectangle r(Point(200,200), 100, 50);
  r.set_fill_color(Color::yellow);



  Closed_polyline poly_rect;
  poly_rect.add(Point(100,50));
  poly_rect.add(Point(200,50));
  poly_rect.add(Point(200,100));
  poly_rect.add(Point(100,100));
  poly_rect.add(Point(50,75));
  poly_rect.set_style(Line_style(Line_style::dash, 2));
  poly_rect.set_fill_color(Color::green);


  Text t(Point(150, 150), "Hello, graphical world!");
  t.set_font(Graph_lib::Font::times_bold);
  t.set_font_size(20);


  Image ii(Point(100, 50), "img.jpg");
  ii.move(100, 200);


  Circle c(Point(100,200), 50);

  Ellipse e(Point(100,200), 75, 25);
  e.set_color(Color::dark_red);

  Mark m(Point(100,200), 'x');

  ostringstream oss;
  oss << "screen size: " << x_max() << " * " << y_max()
      << "; window size: " << win.x_max() << " * " << win.y_max();

  Text sizes(Point(100, 20), oss.str());
  sizes.set_font_size(15);


  win.attach(poly);
  win.attach(xa);
  win.attach(ya);
  win.attach(sine);
  win.attach(r);
  win.attach(poly_rect);
  win.attach(t);
  win.attach(ii);
  win.attach(c);
  win.attach(m);
  win.attach(e);
  win.attach(sizes);


  win.wait_for_button();
}
