#include "/home/blanca/bs_ppp/bs_fltk/Simple_window.h"
#include "/home/blanca/bs_ppp/bs_fltk/Graph.h"


using namespace Graph_lib;

Button *pbt1;
Image *pim1;



int rint(int low, int high) {
  return low + rand() % (high - low);
}


void bt1_pushed() {
  int newx = rint(0, 800) - pim1->point(0).x;
  int newy = rint(0, 600) - pim1->point(0).y;

  pbt1->move(newx, newy);
  pim1->move(newx, newy);
}



static void cb_bt1_pushed(Address, Address pw) {
  bt1_pushed();
}




int main() {

  Simple_window win(Point(100, 100), 1000, 800, "ex-03");

  Button bt1(Point(200, 100), 200, 132, "Button 1", cb_bt1_pushed);
  pbt1 = &bt1;  

  Image im1(Point(200, 100), "image1.jpg");
  pim1 = &im1;


  win.attach(*pbt1);
  win.attach(*pim1);
 
  win.wait_for_button();
}	
