/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Line.hpp"

namespace Graphics_gtk3 {

    Line::Line(Point p1, Point p2) {
        add(p1);
        add(p2);
        default_color();
    }

    void Line::draw() const {
    }

} // namespace Graphics_gtk3