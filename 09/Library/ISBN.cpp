#include "ISBN.hpp"

ISBN::ISBN(int _n1, int _n2, int _n3, char _x) {
  if (_n1 >= 0  &&  _n2 >= 0  &&  _n3 >= 0  &&  isalnum(_x)) {
    n1 = _n1;
    n2 = _n2;
    n3 = _n3;
    x = _x;
  }
  else
    throw std::runtime_error("illegal ISBN");
}


ostream& operator<<(ostream& os, const ISBN& i) {
  return os << i.get_n1()
	    << i.get_separator()
	    << i.get_n2()
	    << i.get_separator()
	    << i.get_n3()
	    << i.get_separator()
	    << i.get_x();
}

bool operator==(const ISBN& a, const ISBN& b) {
  return a.get_x() == b.get_x() &&
    a.get_n1() == b.get_n1()  &&
    a.get_n2() == b.get_n2()  &&
    a.get_n3() == b.get_n3();
}

bool operator!=(const ISBN& a, const ISBN& b) {
  return !(a == b);
}
