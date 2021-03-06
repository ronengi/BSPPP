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

namespace simplified {

    class vector {

    public:
        vector(int s);
        ~vector();

        // double& operator[](int i);

        double get(int i) const;
       void set(int i, double v);

    private:
        int sz;
        double *elem;

    };

}


#endif /* VECTOR_HPP */

