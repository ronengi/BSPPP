/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   ownership_vector.hpp
 * Author: Ronen Gilead-Raz <ronengi@gmail.com>
 *
 * Created on May 3, 2018, 2:54 PM
 */

#ifndef OWNERSHIP_VECTOR_HPP
#define OWNERSHIP_VECTOR_HPP


#include "ovector.hpp"
using namespace std;


template<typename Pointer>
class ownership_vector : public ovector<Pointer> {
    public:
        ~ownership_vector();

        void push_back(typename ovector<Pointer>::PointedToRef e);      // not-owned objects
        void push_back(Pointer e);                                      // owned objects

    private:
        vector<Pointer> owned;
};

// not-owned objects
template<typename Pointer>
void ownership_vector<Pointer>::push_back(typename ovector<Pointer>::PointedToRef e) {
    // cerr << "\npush_back not-owned\n";
    vector<Pointer>::push_back(&e);
}


// owned objects
template<typename Pointer>
void ownership_vector<Pointer>::push_back(Pointer e) {
    // cerr << "\npush_back owned\n";
    vector<Pointer>::push_back(e);
    owned.push_back(e);
}


template<typename Pointer>
ownership_vector<Pointer>::~ownership_vector() {
    // cerr << "\n~ownership_vector()\n";
    for(auto p = owned.begin(); p != owned.end(); ++p)      // free only owned
        delete[] *p;
    vector<Pointer>::clear();           // prevent ~pvector() from freeing all
}



#endif /* OWNERSHIP_VECTOR_HPP */

