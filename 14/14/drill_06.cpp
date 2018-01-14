#include <iostream>
using namespace std;


class B1 {
public:
  virtual void vf() {    cout << "B1::vf()\n";    }
  void f() {    cout << "B1::f()\n";    }
  virtual void pvf() = 0;
};



class D1 : public B1 {
public:
  void vf() {    cout << "D1::vf()\n";    }
  void f() {    cout << "D1::f()\n";    }
};


class D2 : public D1 {
public:
  void pvf() {    cout << "D2::pvf()\n";    }
};


int main() {

  D2 d2;
  d2.pvf();
  d2.vf();
  d2.f();

  return 0;
}
