/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <sstream>
#include "Passenger.hpp"

namespace vehicle {

    Passenger::Passenger()
        : values{new double(0.0)}, nValues{1}
    {
        std::cout << "Passenger::Passenger()" << "\n";
        values[0] = 0.0;
    }

    Passenger::Passenger(int nVals, double val)
        : values{new double[nVals]}, nValues{nVals}
    {
        std::cout << "Passenger::Passenger(double)" << "\n";
        for(int i = 0; i < nValues; ++i)
            values[i] = val;
    }

    Passenger::~Passenger() {
        std::cout << "Passenger::~Passenger()" << "\n";
        if(nValues == 1)
            delete values;
        else
            delete[] values;
    }

    int Passenger::getNValues() const {
        return nValues;
    }

    double* Passenger::getValues() const {
        return values;
    }


    std::ostream& operator<<(std::ostream& os, const Passenger& w) {
        std::stringstream ss;
        for (int i = 0; i < w.getNValues(); ++i) {
            ss << w.getValues()[i];
            if (i < w.getNValues() - 1)
                ss << ", ";
        }
        return os << ss.str() << "\n";
    }


}