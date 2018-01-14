#include <iostream>
using namespace std;


class B2 {
public:
  virtual void pvf() = 0;
};


class D21 : public B2 {
public:
  void pvf() {    cout << "D21::pvf() [\"" << s1 << "\"]\n";    }
private:
  string s1;
};


class D22 : public B2 {
public:
  void pvf() {    cout << "D22::pvf() [" << i1 << "]\n";    }
private:
  int i1;
};

void f(B2& b2) {
  b2.pvf();
}


int main() {

  D21 d21;
  D22 d22;

  f(d21);
  f(d22);

  return 0;
}
