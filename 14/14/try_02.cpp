#include <iostream>
using namespace std;

struct B {
  virtual void f() const {    cout << "B::f\n";    }
  void g() const {    cout << "B::g\n";    }
};

struct D : B {
  void f() const {    cout << "D::f\t";    B::f();    }
  void g() {    cout << "D::g\n";    }
};

void call(const B& b) {
  b.f();
  b.g();
}


int main() {
  B b;
  D d;

  call(b);
  call(d);

  cout << endl;

  b.f();
  b.g();

  cout << endl;

  d.f();
  d.g();

  cout << endl;
}
