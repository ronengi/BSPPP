#include "Test.hpp"

int main() {
  Test t1;
  t1.show();

  t1.on();
  t1.set_level(-5);
  t1.show();


  return 0;
}
