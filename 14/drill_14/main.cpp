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


#include "B1.hpp"
#include "D1.hpp"


/*
 * 04
 */
int main(int argc, char** argv) {
    cout << "\n" << "01" << "\n";
    B1 b1;
    b1.vf();
    b1.f();

    cout << "\n" << "02" << "\n";
    D1 d1;
    d1.vf();
    d1.f();

    cout << "\n" << "03" << "\n";
    B1& rb1 = d1;
    rb1.vf();
    rb1.f();

    return 0;
}
