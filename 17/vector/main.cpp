/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main.cpp
 * Author: Ronen Gilead-Raz <ronengi@gmail.com>
 *
 * Created on March 14, 2018, 12:06 AM
 */

#include <iostream>
#include "vector.hpp"

using namespace std;

/*
 *
 */
int main(int argc, char** argv) {
    int n = 10;
    simplified::vector v1(n);
    v1[3] = 12.34;
    for(int i = 0; i < n; ++i)
        cout << " " << v1[i];
    cout << "\n";

    return 0;
}

