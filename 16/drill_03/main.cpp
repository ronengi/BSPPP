#include "/home/blanca/bs_ppp/bs_fltk/GUI.h"
#include "Lines_window.hpp"


//  using namespace Graph_lib;

int main() {

  try {
    Lines_window win(Point(100, 100), 600, 400, "lines");
    return Graph_lib::gui_main();
  }

  catch(exception& e) {
    cerr << "exception: " << e.what() << endl;
    return 1;
  }

  catch(...) {
    cerr << "Some exception\n";
    return 2;
  }

}	
