#include "Button_board.hpp"




Button_board::Button_board(int rows, int cols, int bw, int bh)
  : ob(Point(0, 0), 100, 30, ""),
    _rows(rows), _cols(cols), _bw(bw), _bh(bh),
    prev_b(NULL) {

  stringstream ss;

  for (int i = 0; i < (_rows * _cols); ++i) {
    ss.str("");
    ss << "Button " << i;
    _buttons.push_back(new Button(Point(0, 0), _bw, _bh, ss.str().c_str(), cb_push));
  }
}


Button_board::~Button_board() {
  for (int i = 0; i < _buttons.size(); ++i)
    delete(_buttons[i]);
}



void Button_board::cb_push(Address pb, Address pw) {
  ((Button_board *)pw)->push(pb);
}

void Button_board::push(void *pb) {

  if (prev_b) {
    prev_b->copy_label(prev_l.c_str());
    prev_b->color(prev_c);
  }

  prev_c = ((Fl_Button *)pb)->color();
  prev_l = ((Fl_Button *)pb)->label();
  prev_b = ((Fl_Button *)pb);

  ((Fl_Button *)pb)->color(FL_RED);
  ((Fl_Button *)pb)->copy_label("hello");
  ob.put(prev_l.c_str());
}


// attach all the buttons directly to the window
void Button_board::attach(Graph_lib::Window& win) {
  if ((_rows * _cols) != (_buttons.size()))
    throw runtime_error("no such button");


  int xshift = (win.x_max() - (_cols * _bw)) / 2;
  int yshift = (win.y_max() - (_rows * _bh)) / 2;

  win.begin();

  for (int row = 0; row < _rows; ++row) {
    for (int col = 0; col < _cols; ++col) {
      _buttons[col + row * _cols]->attach(*(Graph_lib::Window *)this);
      _buttons[col + row * _cols]->move(xshift + col * _bw, yshift + row * _bh);
    }
  }
  ob.attach(win);
  ob.move((win.x_max() - 100) / 2, yshift - 35);
  ob.put("hello");
  own = &win;

  win.end();
}
