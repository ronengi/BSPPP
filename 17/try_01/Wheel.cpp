/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <sstream>
#include "Wheel.hpp"

namespace vehicle {

    Wheel::Wheel()
        : values{new double(0.0)}, nValues{1}
    {
        std::cout << "Wheel::Wheel()" << "\n";
        values[0] = 0.0;
    }

    Wheel::Wheel(int nVals, double val)
        : values{new double[nVals]}, nValues{nVals}
    {
        std::cout << "Wheel::Wheel(double)" << "\n";
        for(int i = 0; i < nValues; ++i)
            values[i] = val;
    }

    Wheel::~Wheel() {
        std::cout << "Wheel::~Wheel()" << "\n";
        if(nValues == 1)
            delete values;
        else
            delete[] values;
    }

    int Wheel::getNValues() const {
        return nValues;
    }

    double* Wheel::getValues() const {
        return values;
    }


    std::ostream& operator<<(std::ostream& os, const Wheel& w) {
        std::stringstream ss;
        for (int i = 0; i < w.getNValues(); ++i) {
            ss << w.getValues()[i];
            if (i < w.getNValues() - 1)
                ss << ", ";
        }
        return os << ss.str() << "\n";
    }


}