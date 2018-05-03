/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   pvector.hpp
 * Author: Ronen Gilead-Raz <ronengi@gmail.com>
 *
 * Created on May 2, 2018, 1:14 PM
 */

#ifndef PVECTOR_HPP
#define PVECTOR_HPP

#include <vector>
#include <type_traits>
#include <stdexcept>
using namespace std;


template<typename Pointer>
class pvector : public std::vector<Pointer> {
    public:
        pvector();
        virtual ~pvector();
};

template<typename Pointer>
ostream& operator<<(ostream& os, const pvector<Pointer>& pv);



/****************************************************************
 *                           definitions                        *
 ****************************************************************/

template<typename Pointer>
pvector<Pointer>::pvector() {
    if(!std::is_pointer<Pointer>::value)
        throw(invalid_argument("argument is not a pointer"));
}


template<typename Pointer>
pvector<Pointer>::~pvector() {
    // cerr << "\n~pvector()\n";
    for(auto p = vector<Pointer>::begin(); p != vector<Pointer>::end(); ++p)
        delete[] *p;
}



template<typename Pointer>
ostream& operator<<(ostream& os, const pvector<Pointer>& pv) {
    os << "(" << pv.size() << "): [";
    char comma[3] = {'\0', ' ', '\0'};
    for(auto p = pv.begin(); p != pv.end(); ++p) {
        os << comma << *p;
        comma[0] = ',';
    }
    os << ']';
    return os;
}


#endif /* PVECTOR_HPP */
