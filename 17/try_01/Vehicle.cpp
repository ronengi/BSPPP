/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include <iostream>
#include "Vehicle.hpp"


namespace vehicle {

    Vehicle::Vehicle() {
        std::cout << "Vehicle::Vehicle()" << "\n";
    }

    Vehicle::~Vehicle() {
        std::cout << "Vehicle::~Vehicle()" << "\n";
    }

}