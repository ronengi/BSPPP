/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   D22.hpp
 * Author: Ronen Gilead-Raz <ronengi@gmail.com>
 *
 * Created on January 14, 2018, 12:02 AM
 */

#ifndef D22_HPP
#define D22_HPP

#include <iostream>
using namespace std;
#include "B2.hpp"

class D22 : public B2 {
public:
    void pvf() override;
private:
    int i1 = 123;
};


#endif /* D22_HPP */

