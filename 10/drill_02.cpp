#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;


struct Point {
  double x;
  double y;
};

istream& operator>>(istream& is, Point& pp) {
  double x, y;
  char ch1, ch2, ch3;

  is.exceptions(is.exceptions() | ios_base::badbit);

  is >> ch1 >> x >> ch2 >> y >> ch3;

  if (!is)
    return is;
  if (!(ch1 == '('  &&  ch2 == ','  &&  ch3 == ')')) {
    is.clear(ios::failbit);
    return is;
  }

  pp.x = x;
  pp.y = y;

  return is;
}

//ostream& operator<<(ostream& os, const Point& pp) {}

int main() {
  vector<Point> original_points;
  Point pp;

  for (int i = 0; i < 7; ++i) {
    cout << "Enter (x, y) values for a point: ";
    while (!(cin >> pp)) {
      cin.clear();
      cout << "Please try again: ";
    }
  }

  return 0;
}
