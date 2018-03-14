/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main.cpp
 * Author: Ronen Gilead-Raz <ronengi@gmail.com>
 *
 * Created on March 14, 2018, 12:50 AM
 */

#include <iostream>
#include "Vehicle.hpp"
#include "Car.hpp"

// #include "Wheel.hpp"
// #include "Passenger.hpp"


using namespace vehicle;

/*
 *
 */
int main(int argc, char** argv) {

    /*
    Wheel myWheel1{};
    std::cout << myWheel1 << "\n";

    Wheel myWheel2{12, 1.3};
    std::cout << myWheel2 << "\n";


    Passenger myPassenger1{};
    std::cout << myPassenger1 << "\n";

    Passenger myPassenger2{12, 1.3};
    std::cout << myPassenger2 << "\n";
    */

    Car myCar1{};
    std::cout << myCar1;

    return 0;
}


