/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main.cpp
 * Author: Ronen Gilead-Raz <ronengi@gmail.com>
 *
 * Created on February 18, 2018, 11:47 AM
 */

#include <iostream>
#include <vector>
using namespace std;

/*
 *
 */
int main(int argc, char** argv) {
    vector<double> age(4);
    age[0] = 1.2;
    age[1] = 3.4;
    age[2] = 5.6;
    age[3] = 7.8;

    int i = 17;
    int* pi = &i;

    double* pd = nullptr;

    cout << "\n" << i << "\n";
    cout << "\n" << pi << "\n";
    cout << "\n" << *pi << "\n";

    cout << "\n" << sizeof(int) << "\n";

    cout << "\n" << pd << "\n";

    cout << "\n" << "success!" << "\n\n";
    return 0;
}

