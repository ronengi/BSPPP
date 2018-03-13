#include "Lines_window.hpp"


Lines_window::Lines_window(Point xy, int w, int h, const string& title)
  : Window(xy, w, h, title),
    next_button(Point(x_max()-170, 0), 80, 20, "Next point", cb_next),
    quit_button(Point(x_max()-70, 0), 70, 20, "Quit", cb_quit),
    next_x(Point(x_max()-330, 0), 50, 20, "next x:"),
    next_y(Point(x_max()-230, 0), 50, 20, "next y:"),
    xy_out(Point(100, 0), 100, 20, "current (x,y):"),
    color_menu(Point(x_max()-70, 40), 70, 20, Graph_lib::Menu::vertical, "color"),
    menu_button(Point(x_max()-80, 30), 80, 20, "color menu", cb_menu)
 {

  attach(next_button);
  attach(quit_button);
  attach(next_x);
  attach(next_y);
  attach(xy_out);    xy_out.put("no point");

  color_menu.attach(new Graph_lib::Button(Point(0, 0), 0, 0, "red", cb_red));
  color_menu.attach(new Graph_lib::Button(Point(0, 0), 0, 0, "blue", cb_blue));
  color_menu.attach(new Graph_lib::Button(Point(0, 0), 0, 0, "black", cb_black));
  attach(color_menu);
  color_menu.hide();
  attach(menu_button);

  attach(lines);
}

void Lines_window::cb_quit(Graph_lib::Address, Graph_lib::Address pw) {
  Graph_lib::reference_to<Lines_window>(pw).quit();
}
void Lines_window::quit() {
  hide();
}

void Lines_window::cb_next(Graph_lib::Address, Graph_lib::Address pw) {
  Graph_lib::reference_to<Lines_window>(pw).next();
}
void Lines_window::next() {
  int x = next_x.get_int();
  int y = next_y.get_int();
  lines.add(Point(x, y));

  ostringstream ss;
  ss << '(' << x << ',' << y << ')';
  xy_out.put(ss.str());

  redraw();
}



void Lines_window::cb_menu(Graph_lib::Address, Graph_lib::Address pw) {
  Graph_lib::reference_to<Lines_window>(pw).menu_pressed();
}
void Lines_window::menu_pressed() {
  menu_button.hide();
  color_menu.show();
}


void Lines_window::cb_red(Graph_lib::Address, Graph_lib::Address pw) {
  Graph_lib::reference_to<Lines_window>(pw).red_pressed();
}
void Lines_window::red_pressed() {
  lines.set_color(Graph_lib::Color::red);
  color_menu.hide();
  menu_button.show();
  redraw();
}

void Lines_window::cb_blue(Graph_lib::Address, Graph_lib::Address pw) {
  Graph_lib::reference_to<Lines_window>(pw).blue_pressed();
}
void Lines_window::blue_pressed() {
  lines.set_color(Graph_lib::Color::blue);
  color_menu.hide();
  menu_button.show();
  redraw();
}

void Lines_window::cb_black(Graph_lib::Address, Graph_lib::Address pw) {
  Graph_lib::reference_to<Lines_window>(pw).black_pressed();
}
void Lines_window::black_pressed() {
  lines.set_color(Graph_lib::Color::black);
  color_menu.hide();
  menu_button.show();
  redraw();
}