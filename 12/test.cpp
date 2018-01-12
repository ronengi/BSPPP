#include <iostream>
#include <cmath>
using namespace std;

#define PI 3.14159265


int sgn(double d) {
  if (d > 0)    return 1;
  if (d < 0)    return -1;
  return 0;
}


int main() {
  int x0 = 500, y0 = 500;

  double x, y, th, s_th, c_th, m = 4, n = 4, a = 50, b = 50;

  for (th = 0; th < PI / 2; th += 0.1) {
    c_th = cos(th);
    s_th = sin(th);

    cout << "\t" << abs(c_th) << "\t" << s_th << "\n";

    x = x0 + 
      pow(abs(c_th), (2.0 / m))  * a * sgn(c_th);

    y = y0 +
      pow(abs(s_th), (2.0 / n))  * b * sgn(s_th);

    cout << "( " << x << " , " << y << " )\n";
  }

  return 0;
}
