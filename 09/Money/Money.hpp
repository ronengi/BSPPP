#include <iostream>
#include <stdexcept>
#include <cmath>
using namespace std;

enum Currency { USD, YEN, ISL };

// struct Conv_tbl {
//   vector<Currency> cur;
//   vector<double> usd;
// };


class Money {
public:
  Money(double _cents, Currency _cur);
  Money(long int _cents)
    :cents(_cents), cur(USD) {}
  Money()
    :cents(0), cur(USD) {}

  long int get_cents() const { return cents; }
  Currency get_currency() const { return cur; }

private:
  long int cents;
  Currency cur;
};


Money operator+(const Money& a, const Money& b);
Money operator-(const Money& a, const Money& b);

Money operator*(const Money& a, double d);
Money operator/(const Money& a, double d);

bool operator==(const Money& a, const Money& b);

ostream& operator<<(ostream& os, const Money& m);
istream& operator>>(istream& is, Money& m);
