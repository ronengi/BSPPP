#ifndef ISBN_HPP
#define ISBN_HPP


#include <iostream>
#include <stdexcept>
using namespace std;

class ISBN {
  static const char separator = '-';
public:
  ISBN(int _n1, int _n2, int _n3, char _x);

  int get_n1() const { return n1; }
  int get_n2() const { return n2; }
  int get_n3() const { return n3; }
  char get_x() const { return x; }
  char get_separator() const { return separator; }


private:
  int n1;
  int n2;
  int n3;
  char x;
};


ostream& operator<<(ostream& os, const ISBN& I);
bool operator==(const ISBN& a, const ISBN& b);
bool operator!=(const ISBN& a, const ISBN& b);




#endif
