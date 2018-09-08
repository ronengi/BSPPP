/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main.cpp
 * Author: Ronen Gilead-Raz <ronengi@gmail.com>
 *
 * Created on April 27, 2018, 3:42 PM
 */

#include <iostream>
using namespace std;


ostream& operator<<(ostream& os, const int* arr) {
    for(int i = 0; i < 5; ++i)
        os << *(arr+i) << " ";
    return os;
}


void copy(int* f1, int* e1, int* f2) {
    while(f1 < e1)
        *f2++ = *f1++;
}


/*
 *
 */
int main(int argc, char** argv) {

    int ai1[5] = {1, 2, 3, 4, 5};
    int ai2[5];

    copy(ai1, ai1+5, ai2);

    // cout << ai1 << "\n";
    cout << ai2 << "\n";


    return 0;
}

