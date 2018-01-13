/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   D21.hpp
 * Author: Ronen Gilead-Raz <ronengi@gmail.com>
 *
 * Created on January 14, 2018, 12:02 AM
 */

#ifndef D21_HPP
#define D21_HPP

#include <iostream>
using namespace std;
#include "B2.hpp"

class D21 : public B2 {
public:
    void pvf() override;
private:
    string s1 = "Hello from D21";
};


#endif /* D21_HPP */

