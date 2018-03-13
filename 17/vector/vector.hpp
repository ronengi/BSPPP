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
        int sz;
        double *elem;

    public:
        vector(int s);
        ~vector();

        double& operator[](int i);
    };

}


#endif /* VECTOR_HPP */

