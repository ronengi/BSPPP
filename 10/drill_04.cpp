#include <iostream>
#include <fstream>
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
ostream& operator<<(ostream& os, const Point& pp) {
  return os << "( " << pp.x << ", " << pp.y << " )";
}

int main() {
  string o_name = "point.out";
  ofstream ofs(o_name.c_str());

  vector<Point> original_points;
  Point pp;

  for (int i = 0; i < 7; ++i) {
    cout << "Enter (x, y) values for a point: ";
    while (!(cin >> pp)) {
      cin.clear();
      cout << "Please try again: ";
    }
    original_points.push_back(pp);
  }


  for (int i = 0; i < original_points.size(); ++i)
    ofs << original_points[i] << endl;


  return 0;
}
