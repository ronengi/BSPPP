/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "vector.hpp"

namespace simplified {

    // default constructor
    vector::vector() :
        sz{0}, elem{nullptr}, space{0}
    { }

    // constructor
    vector::vector(int s) :
        sz{s}, elem{new double[s]}, space{sz}
    {
            for (int i = 0; i < sz; ++i)    // initialize elements
                elem[i] = 0;
    }

    // initializer list constructor
    vector::vector(initializer_list<double> lst) :
        sz{static_cast<int>(lst.size())}, elem{new double[sz]}, space{sz}
    {
            copy(lst.begin(), lst.end(), elem);     // initialize using std::copy()
    }

    // copy constructor
    vector::vector(const vector& arg) :
        sz{arg.sz}, elem{new double[arg.sz]}, space{sz}
    {
            copy(arg.elem, arg.elem+arg.sz, elem);
    }

    // move constructor
    vector::vector(vector&& arg) :
        sz{arg.sz}, elem{arg.elem}, space{sz}
    {
            arg.elem = nullptr;
            arg.sz = 0;
            arg.space = 0;
    }

    // destructor
    vector::~vector() {
        delete[] elem;
    }

    // copy assignment
    vector& vector::operator=(const vector& arg) {
        if(this == &arg)         // self assignment, no work needed
            return *this;
        if(arg.sz <= space) {   // enough space, no need for new allocation
            copy(arg.elem, arg.elem+arg.sz, elem);
            sz = arg.sz;
            return *this;
        }

        double* p = new double[arg.sz];     // allocate new space
        copy(arg.elem, arg.elem+arg.sz, p);
        delete[] elem;                      // deallocate old space
        elem = p;                           // set new elements
        space = sz = arg.sz;                // set new size
        return *this;                       // return self reference
    }

    // move assignment
    vector& vector::operator=(vector&& arg) {
        delete[] elem;
        elem = arg.elem;
        sz = arg.sz;
        space = sz;
        arg.elem = nullptr;
        arg.sz = 0;
        arg.space = 0;
        return *this;
    }


    // subscription set
    double& vector::operator[](int i) {
        return elem[i];
    }

    // subscription get
    const double& vector::operator[](int i) const {
        return elem[i];
    }

    // get size
    int vector::size() const {
        return sz;
    }

    // get amount of space available
    int vector::capacity() const {
        return space;
    }


    // add space for new elements
    void vector::reserve(int newalloc) {
        if(newalloc <= space)               // never decrease allocation
            return;

        double *p = new double[newalloc];   // allocate new space
        for(int i = 0; i < sz; ++i)         // copy old elements
            p[i] = elem[i];
        delete[] elem;                      // deallocate old space
        elem = p;
        space = newalloc;
    }

    // resize and initialize new elements with default value
    void vector::resize(int newsize) {
        reserve(newsize);
        for(int i = sz; i < newsize; ++i)   // initialize new elements
            elem[i] = 0.0;
        sz = newsize < sz ? sz : newsize;
    }

    // increase size by one; add a new element
    void vector::push_back(double d) {
        if(space == 0)              // start with space for 8 elements
            reserve(8);
        else if(sz == space)        // get more space
            reserve(2 * space);
        elem[sz] = d;               // add d at the end
        ++sz;                       // increase the size
    }


    // output stream representation
    ostream& operator<<(ostream& os, const vector& vv) {
        ostringstream ss("");
        ss << "simplified::vector(" << vv.size() << ")\n";
        for(int i = 0; i < vv.size(); ++i)
            ss << "    [" << i << "]== " << vv[i] << "\n";
        return os << ss.str();
    }

}
