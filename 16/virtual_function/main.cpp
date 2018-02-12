#include <iostream>
using namespace std;
#include <cstdlib>


class A {
public:
  void f() {  cout << "A::f()\n";  }
  //virtual void f() {  cout << "A::f()\n";  }
};


class B : public A {
public:
  void f() {  cout << "B::f()\n";  }
};



int main() {
  A *a = new A();
  B *b = new B();

  A *c = new B();

  a->f();
  b->f();

  cout << endl;

  c->f();

  ((A *)c)->f();
  ((B *)c)->f();

  exit(0);

  return 0;
}


