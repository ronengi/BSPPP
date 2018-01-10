/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Point.hpp
 * Author: Ronen Gilead-Raz <ronengi@gmail.com>
 *
 * Created on January 9, 2018, 12:14 AM
 */

#ifndef POINT_HPP
#define POINT_HPP

namespace Graphics_gtk3 {

    struct Point {
        double x, y;
    };

    bool operator==(Point a, Point b);
    bool operator!=(Point a, Point b);

} // namespace Graphics_gtk3


#endif /* POINT_HPP */
