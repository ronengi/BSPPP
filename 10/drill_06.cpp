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

  Point pp;

  // input from user loop
  vector<Point> original_points;
  for (int i = 0; i < 7; ++i) {
    cout << "\nEnter (x, y) values for a point: ";
    while (!(cin >> pp)) {
      cin.clear();
      cout << "Please try again: ";
    }
    original_points.push_back(pp);
  }
  cout << endl;


  string name = "point.out";

  // output to file loop
  ofstream ofs(name.c_str());
  for (int i = 0; i < original_points.size(); ++i)
    ofs << original_points[i] << endl;
  ofs.close();

  // input from file loop
  vector<Point> processed_points;
  ifstream ifs(name.c_str());
  while(ifs >> pp)
    processed_points.push_back(pp);


  // output vectors to screen
  cout << "\n\nOriginal:\n";
  for (int i = 0; i < original_points.size(); ++i)
    cout << original_points[i] << endl;
  cout << "\n\nProcessed:\n";
  for (int i = 0; i < processed_points.size(); ++i)
    cout << processed_points[i] << endl;




  return 0;
}
