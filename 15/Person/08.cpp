#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;


struct Person {

  Person(string name, int age) : _name(name), _age(age) {
    if (age < 0  ||  150 <= age)
      throw runtime_error("invalid age");

    if (name.find_first_of(";:\"'[]*&^%$#@!.") + 1 > 0)
      throw runtime_error("invalid name");
  }


  Person() : _name(""), _age(0) {}

  string name() const {    return _name;    }
  int age() const {    return _age;    }


private:
  string _name;
  int _age;
};



istream& operator>>(istream& is, Person& pp) {
  string name;
  int age;

  //is.clear(ios_base::failbit);

  if (is >> name >> age)
    pp = Person(name, age);

  return is;
}



ostream& operator<<(ostream& os, const Person& pp) {
  return os << "name==" << pp.name() << "\tage==" << pp.age();
}


int main() {
  vector<Person> vp;
  Person p1;

  while (cin >> p1)
    vp.push_back(p1);

  for (int i = 0; i < vp.size(); ++i)
    cout << vp[i] << endl;


  return 0;
}
