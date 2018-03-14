/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Wheel.hpp
 * Author: Ronen Gilead-Raz <ronengi@gmail.com>
 *
 * Created on March 14, 2018, 12:57 AM
 */

#ifndef WHEEL_HPP
#define WHEEL_HPP

#include <iostream>

namespace vehicle {

    class Wheel {
    public:
        Wheel();
        Wheel(int nVals, double val);
        ~Wheel();
        int getNValues() const;
        double* getValues() const;
    private:
        double* values;
        int nValues;
    };


    std::ostream& operator<<(std::ostream& os, const Wheel& w);

}

#endif /* WHEEL_HPP */

