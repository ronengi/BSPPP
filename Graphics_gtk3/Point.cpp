/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Point.hpp"

namespace Graphics_gtk3 {

    bool operator==(Point a, Point b) {
        return a.x == b.x && a.y == b.y;
    }

    bool operator!=(Point a, Point b) {
        return !(a == b);
    }

} // namespace Graphics_gtk3
