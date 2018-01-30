#include <iostream>
using namespace std;


struct Person {
  string name;
  int age;
};



int main() {
  Person p1;
  p1.name = "Goofy";
  p1.age = 63;

  cout << "name==" << p1.name << "\tage==" << p1.age << endl;

  return 0;
}
