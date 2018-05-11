/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include <iostream>
#include <iomanip>
#include <map>
#include <utility>
#include <iterator>
#include <numeric>
using namespace std;

template<typename K, typename V>
ostream& operator<<(ostream& os, const map<K, V>& mp) {
    constexpr int seplength = 100;
    os << "\n";
    for(int i = 0; i < seplength; ++i) os << "-";
    os << "\n";
    for(auto& p : mp)
        os << "\t" << left << setw(10) << p.first << ":\t" << p.second << "\n";
    for(int i = 0; i < seplength; ++i) os << "-";
    return os << "\n";
}


template<typename K, typename V>
istream& operator>>(istream& is, map<K, V>& mp) {
    K kk;
    V vv;
    is >> kk >> vv;
    if(!is)
        return is;
    pair<map<string, int>::iterator, bool> p = mp.insert({kk, vv});
    if(!p.second)
        is.clear(ios_base::failbit);
    return is;
}

template<typename K, typename V>
struct add_pairs {
    int operator()(int a, const pair<K, V>& b) {
        return a + b.second;
    }
};

int d_map_01() {
    map<string, int> msi;

    msi["hello"]    = 11;
    msi["And "]     = 12;
    msi["my"]       = 13;
    msi["poor"]     = 14;
    msi["fool"]     = 15;
    msi["is"]       = 16;
    msi["hang'd"]   = 17;
    msi["No"]       = 18;
    msi["no"]       = 19;
    msi["no"]       = 20;
    msi["life"]     = 21;
    cout << msi << "\n";

//    msi.clear();
//    cout << msi << "\n";

//    while(cin >> msi)
//        cout << msi << "\n";
//    cout << "\n";

//    cout << msi << "\n";

//    int sum = 0;
//    sum = accumulate(msi.begin(), msi.end(), sum, add_pairs<string, int>());
//    cout << sum << "\n";


    map<int, string> mis;
    for(auto& p : msi) {
        mis.insert(pair<int, string>{p.second, p.first});
    }
    cout << mis << "\n";


    return 0;
}
