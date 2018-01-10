/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Color_rgb.hpp
 * Author: Ronen Gilead-Raz <ronengi@gmail.com>
 *
 * Created on January 9, 2018, 12:14 AM
 */

#ifndef COLOR_RGB_HPP
#define COLOR_RGB_HPP

namespace Graphics_gtk3 {

    struct Color_rgb {
        double r, g, b;
    };

    bool operator==(Color_rgb aa, Color_rgb bb);
    bool operator!=(Color_rgb aa, Color_rgb bb);

} // namespace Graphics_gtk3


#endif /* COLOR_RGB_HPP */
