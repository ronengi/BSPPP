/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   vector.hpp
 * Author: Ronen Gilead-Raz <ronengi@gmail.com>
 *
 * Created on March 14, 2018, 12:14 AM
 */

#ifndef VECTOR_HPP
#define VECTOR_HPP


#include <iostream>
#include <sstream>

using std::initializer_list;
using std::copy;
using std::ostream;
using std::ostringstream;


namespace simplified {

    /**
     * <nobr>
     * <b>An almost real vector of doubles</b><br><br>
     * <u>Invariant:</u><br>
     * &nbsp;&bull; if 0 &le; n &le; sz,<br>
     * &nbsp;&nbsp;&nbsp;&nbsp;elem[n] is element n<br>
     * &nbsp;&bull; sz &le; space<br>
     * &nbsp;&bull; if sz &lt; space,<br>
     * &nbsp;&nbsp;&nbsp;&nbsp;there is space for (space-sz) doubles after elem[sz-1]
     * </nobr>
     */
    class vector {

    public:
        vector();                               // default constructor
        explicit vector(int s);                 // constructor - avoid implicit int to vector conversion
        vector(initializer_list<double> lst);   // initializer list constructor
        vector(const vector& arg);              // copy constructor
        vector(vector&& arg);                   // move constructor

        ~vector();

        vector& operator=(const vector& arg);   // copy assignment
        vector& operator=(vector&& arg);        // move assignment

        double& operator[](int i);              // subscription set
        const double& operator[](int i) const;  // subscription get

        int size() const;
        int capacity() const;                   // amount of space available

        void reserve(int newalloc);             // add space for new elements
        void resize(int newsize);               // resize and initialize new elements
        void push_back(double d);               // increase size by one; add a new element


    private:
        int sz;             // number of elements
        double *elem;       // address of first element
        int space;          // number of elements + number of free slots
    };

    ostream& operator<<(ostream& os, const vector& vv);

}


#endif /* VECTOR_HPP */
