/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Car.hpp
 * Author: Ronen Gilead-Raz <ronengi@gmail.com>
 *
 * Created on March 14, 2018, 12:57 AM
 */

#ifndef CAR_HPP
#define CAR_HPP

#include <iostream>
#include "Vehicle.hpp"
#include "Wheel.hpp"
#include "Passenger.hpp"


namespace vehicle {

    class Car : public Vehicle {

    public:
        Car();
        Car(int nPassengers);
        ~Car() override;

    private:
        Wheel* wheels;
        Passenger* passengers;
        int nPassengers;
    };


    std::ostream& operator<<(std::ostream& os, const Car& c);

}

#endif /* CAR_HPP */

