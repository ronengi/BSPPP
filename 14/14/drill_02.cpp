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

  d1.vf();
  d1.f();

  return 0;
}
