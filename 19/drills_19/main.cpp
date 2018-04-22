/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main.cpp
 * Author: Ronen Gilead-Raz <ronengi@gmail.com>
 *
 * Created on April 15, 2018, 10:08 PM
 */

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;


using namespace std;

template<typename T> struct S {
    S(T other) :
        val{other}
    { }


    T& get();
    const T& get() const;
    S<T>& operator=(const T& other);

    private:
    T val;
};

template<typename T>
T& S<T>::get() {
    return val;
}

template<typename T>
const T& S<T>::get() const {
    return val;
}

template<typename T>
S<T>& S<T>::operator=(const T& other) {
    val = other;
    return *this;
}

ostream& operator<<(ostream& os, const vector<int>& vi) {
    ostringstream ss("");
    ss << "vector<int>(" << vi.size() << "):  [";
    for(int i = 0; i < vi.size(); ++i) {
        ss << vi[i];
        if(i < vi.size() -1)
            ss << ", ";
    }
    ss << "]";
    return os << ss.str();
}


template<typename T>
istream& read_val(T& v) {
    cin >> v;
    return cin;
}


/*
 *
 */
int main(int argc, char** argv) {

    vector<int> vi{1, 2, 3};
    vector<int> vi2{4, 5, 6, 7};

    S<int> si{12};
    S<char> sc{'h'};
    S<double> sd{12.34};
    S<string> ss{"hello"};
    S<vector<int>> svi{vi};


    // cout << si.val << "\n";
    // cout << sc.val << "\n";
    // cout << sd.val << "\n";
    // cout << ss.val << "\n";
    // cout << svi.val << "\n";

    // cout << "\n\n";

    cout << si.get() << "\n";
    cout << sc.get() << "\n";
    cout << sd.get() << "\n";
    cout << ss.get() << "\n";
    cout << svi.get() << "\n";

    cout << "\n";

    si = 45;
    sc = 'a';
    sd = 56.78;
    ss = "bye";
    svi = vi2;

    cout << si.get() << "\n";
    cout << sc.get() << "\n";
    cout << sd.get() << "\n";
    cout << ss.get() << "\n";
    cout << svi.get() << "\n";

    cout << "\n";

    read_val(si.get());
    read_val(sc.get());
    read_val(sd.get());
    read_val(ss.get());

    cout << "\n";

    cout << si.get() << "\n";
    cout << sc.get() << "\n";
    cout << sd.get() << "\n";
    cout << ss.get() << "\n";


    return 0;
}

