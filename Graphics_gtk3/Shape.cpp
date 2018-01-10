/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Shape.hpp"


namespace Graphics_gtk3 {

    Shape::Shape(std::initializer_list<Point> lst) {
        for(Point p : lst)
            add(p);
    }

    void Shape::add(Point p) {
        points.push_back(p);
    }

    void Shape::set_point(int i, Point p) {
        if(i < 0 || (int)points.size() < i + 1)
            throw std::out_of_range("Point index is out of range");
        points[i] = p;
    }

    Point Shape::point(int i) const {
        if(i < 0 || (int)points.size() < i + 1)
            throw std::out_of_range("Point index is out of range");
        return points[i];
    }

    int Shape::number_of_points() const {
        return points.size();
    }

    void Shape::set_color(double rr, double gg, double bb) {
        the_color.r = rr;
        the_color.g = gg;
        the_color.b = bb;
    }

    void Shape::set_color(const Color_rgb& new_color) {
        the_color.r = new_color.r;
        the_color.g = new_color.g;
        the_color.b = new_color.b;
    }

    void Shape::default_color() {
        the_color.r = 1.0;
        the_color.g = 1.0;
        the_color.b = 1.0;
    }

    Color_rgb Shape::color() const {
        return the_color;
    }

} // namespace Graphics_gtk3
