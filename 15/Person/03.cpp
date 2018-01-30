#include <iostream>
//#include <stdexcept>
using namespace std;


struct Person {
  string name;
  int age;
};


istream& operator>>(istream& is, Person& pp) {
  string name;
  int age;

  if (is >> name >> age) {
    if (name == ""  ||  age <= 0)
      is.clear(ios_base::failbit);
    else {
      pp.name = name;
      pp.age = age;
    }
  }
  return is;
}



ostream& operator<<(ostream& os, const Person& pp) {
  return os << "name==" << pp.name << "\tage==" << pp.age;
}


int main() {
  Person p1;

  // p1.name = "Goofy";
  // p1.age = 63;

  if (cin >> p1)
    cout << p1 << endl;


  return 0;
}
