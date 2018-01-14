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



int main() {

  cout << "1\n";
  B1 b1;
  b1.vf();
  b1.f();

  cout << "2\n";
  D1 d1;
  d1.vf();
  d1.f();

  cout << "3\n";
  B1& b1r = d1;
  b1r.vf();
  b1r.f();


  return 0;
}
