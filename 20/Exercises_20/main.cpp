/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main.cpp
 * Author: Ronen Gilead-Raz <ronengi@gmail.com>
 *
 * Created on May 2, 2018, 1:13 PM
 */

#include <iostream>
#include <vector>
#include "pvector.hpp"
#include "ovector.hpp"
#include "ownership_vector.hpp"
using namespace std;


int Ex_15() {
    pvector<int*> pv1;
    pv1.push_back(new int[2]);
    pv1.push_back(new int[2]);
    pv1.push_back(new int[2]);
    pv1[0][0] = 12;
    *(pv1[0]+1) = 34;
    cout << pv1 << "\n";
    cout << pv1[0] << "\n";
    cout << pv1[0][0] << "\n";
    cout << pv1[0][1] << "\n";

    cout << "\n";

    return 0;
}


int Ex_16() {
    ovector<int*> ov1;
    ov1.push_back(new int[2]);
    ov1.push_back(new int[2]);
    ov1[0] = 56;
    ov1[1] = 78;
    cout << ov1 << "\n";
    cout << ov1[0] << "\n";
    cout << ov1[1] << "\n";

    cout << "\n";

    return 0;
}


int Ex_17() {
    ownership_vector<int*> ov1;

    ov1.push_back(new int[2]);  // owned
    ov1[0] = 123;

    ov1.push_back(new int[2]);  // owned
    ov1[1] = 456;

    int* pi1 = new int[2];
    pi1[0] = 777;
    ov1.push_back(*pi1);        // not-owned

    int pi2[] = { 888, 999};
    ov1.push_back(*pi2);        // not-owned

    cout << ov1 << "\n";
    cout << ov1[0] << "\n";
    cout << ov1[1] << "\n";
    cout << ov1[2] << "\n";
    cout << ov1[3] << "\n";

    cout << "\n";

    delete[] pi1;

    return 0;
}

/*
 *
 */
int main(int argc, char** argv) {

    // Ex_15();
    // Ex_16();
    Ex_17();

    return 0;
}

