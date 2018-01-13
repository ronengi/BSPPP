/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   B1.hpp
 * Author: Ronen Gilead-Raz <ronengi@gmail.com>
 *
 * Created on January 13, 2018, 10:57 PM
 */

#ifndef B1_HPP
#define B1_HPP

#include <iostream>
using namespace std;

class B1 {
public:
    virtual void vf();
    void f();
    virtual void pvf() =0;
};

#endif /* B1_HPP */
