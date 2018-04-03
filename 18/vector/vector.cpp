/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "vector.hpp"

namespace simplified {

    // constructor
    vector::vector(int s) :
        sz{s}, elem{new double[s]}
    {
            for (int i = 0; i < sz; ++i)    // initialize elements
                elem[i] = 0;
    }

    // initializer list constructor
    vector::vector(initializer_list<double> lst) :
        sz{static_cast<int>(lst.size())}, elem{new double[sz]}
    {
            copy(lst.begin(), lst.end(), elem);     // initialize using std::copy()
    }

    // copy constructor
    vector::vector(const vector& arg) :
        sz{arg.sz}, elem{new double[arg.sz]}
    {
            copy(arg.elem, arg.elem+arg.sz, elem);
    }

    // move constructor
    vector::vector(vector&& arg) :
        sz{arg.sz}, elem{arg.elem}
    {
            arg.elem = nullptr;
            arg.sz = 0;
    }

    // destructor
    vector::~vector() {
        delete[] elem;
    }

    // copy assignment
    vector& vector::operator=(const vector& arg) {
        double* p = new double[arg.sz];
        copy(arg.elem, arg.elem+arg.sz, p);
        delete[] elem;
        elem = p;
        sz = arg.sz;
        return *this;   // return reference to the assigned vector
    }

    // move assignment
    vector& vector::operator=(vector&& arg) {
        delete[] elem;
        elem = arg.elem;
        sz = arg.sz;
        arg.elem = nullptr;
        arg.sz = 0;
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

    // output stream representation
    ostream& operator<<(ostream& os, const vector& vv) {
        ostringstream ss("");
        ss << "simplified::vector(" << vv.size() << ")\n";
        for(int i = 0; i < vv.size(); ++i)
            ss << "    [" << i << "]== " << vv[i] << "\n";
        return os << ss.str();
    }

}
