#include <iostream>
using namespace std;


class B1 {
public:
  virtual void vf() {    cout << "B1::vf()\n";    }
  void f() {    cout << "B1::f()\n";    }
};



class D1 : public B1 {
public:
  void vf() {    cout << "D1::vf()\n";    }
};



int main() {

  D1 d1;
  B1& b1r = d1;

  b1r.vf();
  b1r.f();

  return 0;
}
