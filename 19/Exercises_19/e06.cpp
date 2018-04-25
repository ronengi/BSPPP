/*
 * class Number
 *
 */

#ifndef E06_CPP
#define E06_CPP


#include <iostream>
#include <cmath>
using namespace std;


template<typename T>
class Number {
public:
    Number() : val{} { }
    Number(T vv) : val{vv} { }
    Number(const Number& other) { val = other.val; }
    ~Number() { }

    Number& operator=(const Number& other) { val = other.val; return *this; }

    Number& operator+(const Number& other) { val += other.val; return *this; }
    Number& operator-(const Number& other) { val -= other.val; return *this; }
    Number& operator*(const Number& other) { val *= other.val; return *this; }
    Number& operator/(const Number& other) { val /= other.val; return *this; }    // may throw
    Number& operator%(const Number& other) { val = fmod(val, other.val); return *this; }

// private:
    T val;
};

template<typename T> inline ostream& operator<<(ostream& os, const Number<T>& nn) { return os << nn.val; }
template<typename T> inline istream& operator>>(istream& is, Number<T>& nn) { return is >> nn.val; }


#endif
