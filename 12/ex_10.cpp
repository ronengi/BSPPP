#include "../bs_fltk/Simple_window.h"
#include "../bs_fltk/Graph.h"

int main() {
  using namespace Graph_lib;

  Simple_window win(Point(0, 0), 810, 740, "Graphics Code Organizations");

  // Point.h
  Rectangle ph(Point(90,60), 200, 50);
  ph.set_fill_color(Color::yellow);
  win.attach(ph);

  Text pht1(Point(90, 50), "Point.h:");
  pht1.set_font(Graph_lib::Font::times_bold);
  pht1.set_font_size(15);
  win.attach(pht1);

  Text pht2(Point(110, 85), "struct Point {...};");
  pht2.set_font(Graph_lib::Font::times_bold);
  pht2.set_font_size(15);
  win.attach(pht2);



  // Graph.h -> Point.h
  Open_polyline ar_gh_ph;
  ar_gh_ph.add(Point(200, 240));
  ar_gh_ph.add(Point(200, 115));
  ar_gh_ph.add(Point(197, 125));
  ar_gh_ph.add(Point(203, 125));
  ar_gh_ph.add(Point(200, 115));
  ar_gh_ph.set_style(Line_style(Line_style::solid, 2));
  win.attach(ar_gh_ph);


  // Graph.h
  Rectangle gh(Point(90,240), 220, 90);
  gh.set_fill_color(Color::yellow);
  win.attach(gh);

  Text ght1(Point(90, 215), "Graph.h:");
  ght1.set_font(Graph_lib::Font::times_bold);
  ght1.set_font_size(15);
  win.attach(ght1);

  Text ght2(Point(110, 85), "struct Shape {...};");
  ght2.set_font(Graph_lib::Font::times_bold);
  ght2.set_font_size(15);
  win.attach(ght2);





  win.wait_for_button();
}
