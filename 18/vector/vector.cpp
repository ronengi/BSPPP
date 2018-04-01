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

    /*
    // subscription set
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

    // get size
    int vector::size() const {
        return sz;
    }

    // output stream representation
    ostream& operator<<(ostream& os, const vector& vv) {
        ostringstream ss("");
        ss << "simplified::vector(" << vv.size() << ")\n";
        for(int i = 0; i < vv.size(); ++i)
            ss << "    [" << i << "]== " << vv.get(i) << "\n";
        return os << ss.str();
    }

}
