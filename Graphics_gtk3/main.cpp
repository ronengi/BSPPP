/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


/*
 * File:   main.cpp
 * Author: Ronen Gilead-Raz <ronengi@gmail.com>
 *
 * Created on January 9, 2018, 1:54 AM
 */


#include "Line.hpp"
#include "Shape.hpp"

using namespace Graphics_gtk3;

/*
 *
 */
int main(int argc, char** argv) {

    Line l1{Point{10.0, 20.0}, Point{100.0, 200.0}};
    //l1.draw();
    return 0;
}

