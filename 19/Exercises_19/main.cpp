/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main.cpp
 * Author: Ronen Gilead-Raz <ronengi@gmail.com>
 *
 * Created on April 24, 2018, 12:02 PM
 */

#include <iostream>
#include <vector>
using namespace std;

#include "e01.cpp"
#include "e02.cpp"
#include "e03.cpp"
#include "e05.cpp"
#include "e06.cpp"
#include "e12.cpp"
#include "e13.cpp"

int Tracer::index = 0;      // here it's possible to initialize index

template<typename T>
ostream& operator<<(ostream& os, vector<T> vec) {
    os << "Vector:" << "\t";
    for(T elem : vec)
        os << "[" << elem << "]" << "\t";
    return os;
}


template<typename K, typename V>
ostream& operator<<(ostream& os, Pair<K, V> pp) {
    os << "[" << pp.key << " : " << pp.value << "]";
    return os;
}


template<typename K, typename V>
ostream& operator<<(ostream& os, Sym_table<K, V> st) {
    for(Pair<K, V> ip : st.pairs)
        os << "[" << ip.key << " : " << ip.value << "]" << "\n";
    return os;
}


void ex01() {
    vector<double> v1{1.1, 2.2, 3.3, 4.4};
    vector<double> v2{0.1, 0.1, 0.1};

    cout << "Before:\n";
    cout << v1 << "\n";
    cout << v2 << "\n";

    f01(v1, v2);
    // f01(v2, v1);

    cout << "After:\n";
    cout << v1 << "\n";
    cout << v2 << "\n";
}


void ex02() {
    vector<double> vt{1.1, 2.2, 3.3, 4.4};
    vector<int> vu{4, 3, 2, 1};

    cout << vt << "\n";
    cout << vu << "\n";
    try {
        cout << f02(vt, vu) << "\n";
    }
    catch(runtime_error e) {
        cerr << "runtime error: " << e.what();
    }
    catch(...) {
        cerr << "an unknown error occurred";
    }
}


void ex03() {
    Pair<int, string> p1{1, "aaa"};
    cout << p1 << "\n";

    cout << "\n";

    Sym_table<int, string> st;
    st.set(2, "bbb");
    cout << st << "\n";
    st.set(3, "ccc");
    cout << st << "\n";
    st.set(2, "ddd");
    cout << st << "\n";

    cout << "\n";

    Sym_table<string, double> st2;
    st2.set("pi", 3.141502654);
    st2.set("e", 2.718);
    cout << st2 << "\n";
}

void ex05() {
    Int i1;
    Int i2{12};
    Int i3{i2};

    cout << i1 << "\n";
    cout << i2 << "\n";
    cout << i3 << "\n";

    cout << "\n";


    i2 = i2 + i3;
    i1 = i2;

    cout << i1 << "\n";
    cout << i2 << "\n";
    cout << i3 << "\n";
}


void ex06() {
    Number<double> d1;
    Number<double> d2{1.2};
    Number<double> d3{d2};
    Number<double> d4{2.6};

    cout << d1 << "\n";
    cout << d2 << "\n";
    cout << d3 << "\n";
    cout << d4 << "\n";

    cout << "\n";

    d1 = d4 % d2;

    cout << d1 << "\n";
}


void ex12() {
    File_handle fh1{"e13.cpp"};
    fh1.print_all();
}


void ex13() {
    Tracer t1;
    Tracer t2;

}



/*
 *
 */
int main(int argc, char** argv) {
    // ex01();
    // ex02();
    // ex03();
    // ex05();
    // ex06();
    // ex12();
    ex13();


    return 0;
}

