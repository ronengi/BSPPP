#include <iostream>
using namespace std;

#include "Test.hpp"

Test::Test() : _state(false), _level(0) {}
void Test::on() {    _state = true;    }
void Test::off() {    _state = false;    }
void Test::set_level(int l) {    _level = l;    }
void Test::show() {
  cout << "State is ";
  if (_state)
    cout << "ON\n";
  else
    cout << "OFF\n";
  cout << "Level is set to " << _level << endl;
}
