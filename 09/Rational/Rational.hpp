#ifndef RATIONAL_HPP
#define RATIONAL_HPP


#include <iostream>
#include <stdexcept>
#include <vector>
#include <cmath>
using namespace std;


struct Factors {
  vector<int> factors;
  vector<int> powers;
};

class Rational {
public:
  Rational(int nn, int dd)
    :numerator(nn), denominator(dd) {
    if (denominator == 0)
      throw std::runtime_error("zero denominator");
  }
  Rational()
    :numerator(1), denominator(1) {}

  int get_numerator() const { return numerator; }
  int get_denominator() const { return denominator; }

  double get_double() const { return double(numerator) / denominator; }

  void reduce();

private:
  int numerator;
  int denominator;
};


Factors get_factors(int n);
int next_primary(int n);

Rational operator+(const Rational& a, const Rational& b);
Rational operator-(const Rational& a, const Rational& b);
Rational operator*(const Rational& a, const Rational& b);
Rational operator/(const Rational& a, const Rational& b);
bool operator==(const Rational& a, const Rational& b);
ostream& operator<<(ostream& os, const Rational& r);


#endif
