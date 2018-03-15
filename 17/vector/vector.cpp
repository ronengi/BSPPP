/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "vector.hpp";

namespace simplified {

    vector::vector(int s) :
        sz{s}, elem{new double[s]}
    {
            for (int i = 0; i < sz; ++i)    // initialize elements
                elem[i] = 0;
    }

    vector::~vector() {
        delete[] elem;
    }

    /*
    double& vector::operator[](int i) {
        return elem[i];
    }
    */

    double vector::get(int i) const {
        return elem[i];
    }

    void vector::set(int i, double v) {
        elem[i] = v;
    }

}
