#include "Rational.hpp"


void Rational::reduce() {
  if (numerator == 0)
    return;

  Factors nf = get_factors(numerator);
  Factors df = get_factors(denominator);

  for (int ni = 0; ni < nf.factors.size(); ++ni) {
    for (int di = 0; di < df.factors.size(); ++di) {
      if (nf.factors[ni] == df.factors[di]) {
	// found same factor
	while(nf.powers[ni] > 0  &&  df.powers[di] > 0) {
	  // decrease power
	  --nf.powers[ni];
	  --df.powers[di];
	}
      }
    }
  }

  numerator = 1;
  for (int i = 0; i < nf.factors.size(); ++i) {
    while (nf.powers[i] > 0) {
      numerator *= nf.factors[i];
      --nf.powers[i];
    }
  }

  denominator = 1;
  for (int i = 0; i < df.factors.size(); ++i) {
    while (df.powers[i] > 0) {
      denominator *= df.factors[i];
      --df.powers[i];
    }
  }

}


void get_factors2(int n, int d, Factors& f) {
  if (n == 1)
    return;
  if (n % d == 0) {
    if (f.factors.size() > 0  &&  f.factors.back() == d)
      f.powers.back()++;
    else {
      f.factors.push_back(d);
      f.powers.push_back(1);
    }
    get_factors2((n / d), d, f);
  }
  else
    get_factors2(n, next_primary(d), f);
}
Factors get_factors(int n) {
  Factors f;
  if ( n == 0) return f;
  get_factors2(n, 2, f);
  return f;
}

bool is_primary(int n, const vector<int>& primes) {
  for (int i = 0; i < primes.size(); ++i) {
    if ((n % primes[i]) == 0)
      return false;
  }
  return true;
}
int next_primary(int n) {
  int pri = 2;
  vector<int> primes;
  // build primes up to and including n
  for (; pri <= n; ++pri) {
    if (is_primary(pri, primes))
      primes.push_back(pri);
  }
  // get to the next prime
  while (!is_primary(pri, primes))
    ++pri;

  return pri;
}


Rational operator+(const Rational& a, const Rational& b) {
  int na = a.get_numerator();
  int da = a.get_denominator();
  int nb = b.get_numerator();
  int db = b.get_denominator();
  int dc = da;

  // find smallest common denominator
  while (dc % db != 0)
    dc += da;

  Rational ret(((dc / da) * na) + ((dc / db) * nb), dc);
  ret.reduce();

  return ret;
}
Rational operator-(const Rational& a, const Rational& b) {
  int na = a.get_numerator();
  int da = a.get_denominator();
  int nb = b.get_numerator();
  int db = b.get_denominator();
  int dc = da;

  // find smallest common denominator
  while (dc % db != 0)
    dc += da;

  Rational ret(((dc / da) * na) - ((dc / db) * nb), dc);
  ret.reduce();

  return ret;
}
Rational operator*(const Rational& a, const Rational& b) {
  Rational ret((a.get_numerator() * b.get_numerator()),
	       (a.get_denominator() * b.get_denominator()));
  ret.reduce();

  return ret;
}
Rational operator/(const Rational& a, const Rational& b) {
  Rational ret((a.get_numerator() * b.get_denominator()),
	       (a.get_denominator() * b.get_numerator()));
  ret.reduce();

  return ret;
}
bool operator==(const Rational& a, const Rational& b) {
  Rational ra = a, rb = b;
  ra.reduce();
  rb.reduce();
  return ra.get_numerator() == rb.get_numerator()  &&
	  ra.get_denominator() == rb.get_denominator();
}
ostream& operator<<(ostream& os, const Rational& r) {
  return os << "("
	    << r.get_numerator()
	    << "/"
	    << r.get_denominator()
	    << ")";
}



int main() {

  Rational r1(12, 12), r2(5, 5);
  if (r1 == r2)
    cout << r1 << " == " << r2 << endl;

  cout << "\n\n\n";


  Rational a(2,4), b(3, 6);

  cout << "a=" << a << "\t\tb=" << b << endl;
  cout << a << " * " << b << "=" << a * b << endl;
  cout << a << " / " << b << "=" << a / b << endl;
  cout << a << " + " << b << "=" << a + b << endl;
  cout << a << " - " << b << "=" << a - b << endl;


  cout << "\n\n\n";


  // int n = 60;
  // cout << n << "'s factors are:\t";
  // Factors nf = get_factors(n);
  // for (int i = 0; i < nf.factors.size(); ++i) {
  //   cout << "(" << nf.factors[i] << " ^ " << nf.powers[i] << ")";
  //   if (i < nf.factors.size() - 1)
  //     cout << " * ";
  // }


  cout << endl;
  return 0;
}
