#include "../bs_fltk/Simple_window.h"
#include "../bs_fltk/Graph.h"


int main() {
  using namespace Graph_lib;

  Simple_window win(Point(100, 50), 800, 1000, "Drill");


  int XMAX = 800;//win.x_max();
  int YMAX = 800;//win.y_max();
  Lines grid;
  for (int x = 0; x <= XMAX; x += 100)
    grid.add(Point(x, 0), Point(x, YMAX));
  for (int y = 0; y <= YMAX; y += 100)
    grid.add(Point(0, y), Point(XMAX, y));
  grid.set_style(Line_style(Line_style::solid, 1));
  win.attach(grid);


  Vector_ref<Rectangle> diagonal;
  int x = 0, y = 0;
  for (int i = 0; i < 8; ++i) {
    diagonal.push_back(new Rectangle(Point(x, y), 100, 100));
    diagonal[diagonal.size() - 1].set_fill_color(Color::red);
    win.attach(diagonal[diagonal.size() - 1]);
    x += 100;
    y += 100;
  }


  Image samurai1(Point(200,0), "samurai.jpg");
  win.attach(samurai1);

  Image samurai2(Point(0,500), "samurai.jpg");
  win.attach(samurai2);

  Image samurai3(Point(600,300), "samurai.jpg");
  win.attach(samurai3);


  Image replicator(Point(0,0), "replicator.jpg");
  win.attach(replicator);

  for (int i = 0; i < 8; ++i) {
    win.wait_for_button();
    replicator.move(100, 0);
  }


}
