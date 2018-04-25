/*
 * class Int
 *
 * No header file, because this file will be used in
 * the next exercise to create a template class.
 *
 */

#ifndef E05_CPP
#define E05_CPP


#include <iostream>
using namespace std;


class Int {
public:
    Int() : val{0} { }
    Int(int vv) : val{vv} { }
    Int(const Int& other) { val = other.val; }
    ~Int() { }

    Int& operator=(const Int& other) { val = other.val; return *this; }

    Int& operator+(const Int& other) { val += other.val; return *this; }
    Int& operator-(const Int& other) { val -= other.val; return *this; }
    Int& operator*(const Int& other) { val *= other.val; return *this; }
    Int& operator/(const Int& other) { val /= other.val; return *this; }    // may throw

// private:
    int val;
};


inline ostream& operator<<(ostream& os, const Int& ii) { return os << ii.val; }
inline istream& operator>>(istream& is, Int& ii) { return is >> ii.val; }


#endif
