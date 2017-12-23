#include "Money.hpp"


double c_table(Currency cc) {
  static Currency cur[] = { USD, YEN, ISL };
  static double usd[] = {1, 0.01, 0.241 };

  for (int i = 0; i < 3; ++i) {
    if (cur[i] == cc)
      return usd[i];
  }
  throw runtime_error("unknown currency");
  return 0;
}


Money::Money(double mm, Currency cc)
  :cents(0), cur(cc) {
  mm = mm * c_table(cc) * 100;
  if (mm > 2147483647)    throw runtime_error("overflow error");

  cents = mm;
}






Money operator+(const Money& a, const Money& b) {
  return Money(a.get_cents() + b.get_cents());
}
Money operator-(const Money& a, const Money& b) {
  return Money(a.get_cents() - b.get_cents());
}

Money operator*(const Money& a, double d) {
  long int m = (a.get_cents() * d) + 0.5;
  return Money(m);
}
Money operator/(const Money& a, double d) {
  if (d == 0)    throw runtime_error("divide by zero");
  long int m = (a.get_cents() / d) + 0.5;
  return Money(m);
}

bool operator==(const Money& a, const Money& b) {
  return a.get_cents() == b.get_cents();
}

ostream& operator<<(ostream& os, const Money& m) {
  double dd = m.get_cents() / 100.0;

  if (dd < 0)
    os << "(";

  switch (int(m.get_currency())) {
  case USD:
    os << "USD";
    break;
  case YEN:
    os << "YEN";
    break;
  case ISL:
    os << "ISL";
    break;
  }

  os << " " << abs(dd) / c_table(m.get_currency());

  if (dd < 0)
    os << ")";

  return os;
}
istream& operator>>(istream& is, Money& m) {
  double dd = 0;
  is >> dd;
  if (!is)
    return is;
  m = Money(dd * 100.0 + 0.51);
  return is;
}



int main() {

  // Money mm;
  // cin >> mm;
  // cout << mm << endl;

  Money a(1.55), b(1, ISL);
  double d = 3;

  cout << a << " + " << b << " = " << a + b << endl;
  cout << a << " - " << b << " = " << a - b << endl;
  cout << a << " * " << d << " = " << a * d << endl;
  cout << a << " / " << d << " = " << a / d << endl;



  return 0;
}
