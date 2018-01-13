/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main.cpp
 * Author: Ronen Gilead-Raz <ronengi@gmail.com>
 *
 * Created on January 13, 2018, 10:56 PM
 */


#include "B2.hpp"
#include "D21.hpp"
#include "D22.hpp"


/*
 * 07
 */


void f(B2& rb2) {
    rb2.pvf();
}

int main(int argc, char** argv) {
    cout << "\n" << "07" << "\n";
    D21 d21;
    f(d21);

    D22 d22;
    f(d22);

    return 0;
}
