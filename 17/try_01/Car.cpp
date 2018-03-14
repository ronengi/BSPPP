/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include <iostream>
#include <sstream>
#include "Car.hpp"


namespace vehicle {

    Car::Car()
        : wheels{new Wheel[4]}, passengers{new Passenger[4]}, nPassengers{4}
    {
        std::cout << "Car::Car()" << "\n";
    }

    Car::Car(int numPassengers)
        : wheels{new Wheel[4]}, passengers{new Passenger[numPassengers]}, nPassengers{numPassengers}
    {
        std::cout << "Car::Car(int)" << "\n";
    }

    Car::~Car() {
        std::cout << "Car::~Car()" << "\n";
        delete[] wheels;
        delete[] passengers;
    }


    std::ostream& operator<<(std::ostream& os, const Car& c) {
        std::stringstream ss;
        ss << "Car: ";
        //c.g
        return os << ss.str() << "\n";
    }

}