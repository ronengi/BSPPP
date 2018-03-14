/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Passenger.hpp
 * Author: Ronen Gilead-Raz <ronengi@gmail.com>
 *
 * Created on March 14, 2018, 12:24 PM
 */

#ifndef PASSENGER_HPP
#define PASSENGER_HPP

namespace vehicle {

    class Passenger {

    public:
        Passenger();
        Passenger(int nVals, double val);
        ~Passenger();
        int getNValues() const;
        double* getValues() const;
    private:
        double* values;
        int nValues;
    };


    std::ostream& operator<<(std::ostream& os, const Passenger& w);

}


#endif /* PASSENGER_HPP */

