#include <iostream>
//#include <stdexcept>
using namespace std;


struct Person {
  Person(string name, int age) : _name(name), _age(age) {}
  Person() : _name(""), _age(0) {}


  string _name;
  int _age;
};


istream& operator>>(istream& is, Person& pp) {
  string name;
  int age;

  if (is >> name >> age) {
    if (name == ""  ||  age <= 0)
      is.clear(ios_base::failbit);
    else {
      pp._name = name;
      pp._age = age;
    }
  }
  return is;
}



ostream& operator<<(ostream& os, const Person& pp) {
  return os << "name==" << pp._name << "\tage==" << pp._age;
}


int main() {
  Person p1;

  // p1.name = "Goofy";
  // p1.age = 63;

  if (cin >> p1)
    cout << p1 << endl;


  return 0;
}
