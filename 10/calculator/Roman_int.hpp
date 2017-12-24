#ifndef ROMAN_INT_HPP
#define ROMAN_INT_HPP


#include <iostream>
#include <stdexcept>
using namespace std;


#define MAX_ROMAN 3999
#define MIN_ROMAN 1

// holds a roman numeral (as int)
class Roman_int {
public:
  Roman_int();
  Roman_int(int nn);
  int as_int() const { return int_val; }
private:
  int int_val;
};


istream& operator>>(istream& is, Roman_int& ri);
ostream& operator<<(ostream& os, const Roman_int& ri);


Roman_int operator+(const Roman_int& a, const Roman_int& b);
Roman_int operator-(const Roman_int& a, const Roman_int& b);
Roman_int operator*(const Roman_int& a, const Roman_int& b);
Roman_int operator/(const Roman_int& a, const Roman_int& b);

Roman_int operator*=(Roman_int& a, int b);
Roman_int operator/=(Roman_int& a, int b);
Roman_int operator+=(Roman_int& a, int b);
Roman_int operator-=(Roman_int& a, int b);

bool operator==(const Roman_int& a, const Roman_int& b);




string int_to_roman(int n);
int roman_to_int(string r);



#endif
