#include <iostream>
using namespace std;


class C {
public:
  C() {    cout << "C::C()\n";    }

  virtual void vf() = 0;
};


int main() {

  C c1;

  return 0;
}
