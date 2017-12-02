#include "std_lib_facilities.h"

class Point {
public:
    double x;
    double y;
};


constexpr double xscale = 10.0;
constexpr double yscale = 0.8;


constexpr Point scale(Point p) {
    return {xscale * p.x, yscale * p.y};
};

int main() {
    Point p2{10, 10};
    Point p3 = scale(p2);
}
