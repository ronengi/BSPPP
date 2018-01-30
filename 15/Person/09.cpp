#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;


struct Person {

  Person(string first_name, string second_name, int age) : _first_name(first_name), _second_name(second_name), _age(age) {
    if (age < 0  ||  150 <= age)
      throw runtime_error("invalid age");

    if (first_name.find_first_of(";:\"'[]*&^%$#@!.") + 1 > 0)
      throw runtime_error("invalid first name");
    if (second_name.find_first_of(";:\"'[]*&^%$#@!.") + 1 > 0)
      throw runtime_error("invalid second name");
  }


  Person() : _first_name(""), _second_name(""), _age(0) {}

  string first_name() const {    return _first_name;    }
  string second_name() const {    return _second_name;    }
  int age() const {    return _age;    }


private:
  string _first_name;
  string _second_name;
  int _age;
};



istream& operator>>(istream& is, Person& pp) {
  string first_name;
  string second_name;
  int age;

  if (is >> first_name >> second_name >> age)
    pp = Person(first_name, second_name, age);

  return is;
}



ostream& operator<<(ostream& os, const Person& pp) {
  return os << "first-name==" << pp.first_name() << "  second-name==" << pp.second_name() << "    age==" << pp.age();
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
