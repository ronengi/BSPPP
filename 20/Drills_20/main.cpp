/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main.cpp
 * Author: Ronen Gilead-Raz <ronengi@gmail.com>
 *
 * Created on May 2, 2018, 10:05 AM
 */

#include <iostream>
#include <iomanip>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;


ostream& operator<<(ostream& os, const int* ai) {
    cout << "int[]:" << "\t";
    for(int i = 0; i < 10; ++i)
        cout << setw(4) << ai[i] << " ";
    cout << "\n";
}


template<typename T>
ostream& operator<<(ostream& os, const vector<T>& vt) {
    cout << "vector:" << "\t";
    for(auto p : vt)
        cout << setw(4) << p << " ";
    cout << "\n";
}


template<typename T>
ostream& operator<<(ostream& os, const list<T>& lt) {
    cout << "list:" << "\t";
    for(auto p : lt)
        cout << setw(4) << p << " ";
    cout << "\n";
}


/*
 *
 */
int main(int argc, char** argv) {
    int ar1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> vec1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    list<int> ls1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    cout << ar1;
    cout << vec1;
    cout << ls1;
    cout << "\n";


    int ar2[10];
    for(int i = 0; i < 10; ++i)
        ar2[i] = ar1[i];
    vector<int> vec2(vec1);
    list<int> ls2(ls1);

    cout << ar2;
    cout << vec2;
    cout << ls2;
    cout << "\n";

    cout << "\n";
    auto p = find(vec1.begin(), vec1.end(), 3);
    if(p != vec1.end())
        cout << "found";
    else
        cout << "not found";
    cout << "\n";

    return 0;
}
