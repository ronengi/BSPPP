/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main.cpp
 * Author: Ronen Gilead-Raz <ronengi@gmail.com>
 *
 * Created on April 3, 2018, 2:23 PM
 */

#include <iostream>
#include <vector>

using namespace std;


struct X {
    int val;

    void out(const string& s, int nv) {
        cerr << "\t" << this << " -> " << s << ": " << val << " (" << nv << ")\n";
    }

    // default constructor
    X() {
        out("X()", 0);
        val = 0;
    }

    X(int v) {
        val = v;
        out("X(int)", v);
    }

    // copy constructor
    X(const X& x) {
        val = x.val;
        out("X(X&)", x.val);
    }


    // assignment
    X& operator=(const X& a) {
        out("X::operator=()", a.val);
        val = a.val;
        return *this;
    }

    // destructor
    ~X() {
        out("~X()", 0);
    }

};



X copy(X a) {
    cout << " copy()\n";
    return a;
}

X copy2(X a) {
    cout << " copy2()\n";
    X aa = a;
    return aa;
}

X& ref_to(X& a) {
    cout << " ref_to()\n";
    return a;
}

X* make(int i) {
    cout << " make()\n";
    X a(i);
    return new X(a);
}

struct XX {
    X a;
    X b;
};


X glob(2);

/*
 *
 */
int main(int argc, char** argv) {

    cout << "\nX loc{4};\n";
    X loc{4};
    cout << "\n";


    cout << "\nX loc2{loc};\n";
    X loc2{loc};
    cout << "\n";


    cout << "\nloc = X{5};\n";
    loc = X{5};
    cout << "\n";


    cout << "\nloc2 = copy(loc);\n";
    loc2 = copy(loc);
    cout << "\n";


    cout << "\nloc2 = copy2(loc);\n";
    loc2 = copy2(loc);
    cout << "\n";

    cout << "\nX loc3{6};\n";
    X loc3{6};
    cout << "\n";


    cout << "\nX& r = ref_to(loc);\n";
    X& r = ref_to(loc);
    cout << "\n";


    cout << "\ndelete make(7);\n";
    delete make(7);
    cout << "\n";


    cout << "\ndelete make(8);\n";
    delete make(8);
    cout << "\n";


    cout << "\nvector<X> v(4);\n";
    vector<X> v(4);
    cout << "\n";


    cout << "\nXX loc4;\n";
    XX loc4;
    cout << "\n";


    cout << "\nX* p = new X{9};\n";
    X* p = new X{9};
    cout << "\n";

    cout << "\ndelete p;\n";
    delete p;
    cout << "\n";


    cout << "\nX* pp = new X[5];\n";
    X* pp = new X[5];
    cout << "\n";

    cout << "\ndelete[] pp;\n";
    delete[] pp;
    cout << "\n";


    cout << "\nexiting main()\n";


    return 0;
}

