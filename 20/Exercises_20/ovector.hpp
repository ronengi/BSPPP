/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   ovector.hpp
 * Author: Ronen Gilead-Raz <ronengi@gmail.com>
 *
 * Created on May 2, 2018, 11:48 PM
 */

#ifndef OVECTOR_HPP
#define OVECTOR_HPP

#include <type_traits>
#include "pvector.hpp"
using namespace std;


template<typename Pointer>
class ovector : public pvector<Pointer> {
    public:
        using PointedTo = remove_pointer_t<Pointer>;
        using PointedToRef = PointedTo&;

        virtual ~ovector();
        PointedToRef operator[](int i);
};


/****************************************************************
 *                           definitions                        *
 ****************************************************************/

template<typename Pointer>
typename ovector<Pointer>::PointedToRef ovector<Pointer>::operator[](int i) {
    return *(this->at(i));
}


template<typename Pointer>
ovector<Pointer>::~ovector() {
    // cerr << "\n~ovector()\n";
}


#endif /* OVECTOR_HPP */

