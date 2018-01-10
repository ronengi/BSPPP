/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Color_rgb.hpp"

namespace Graphics_gtk3 {

    bool operator==(Color_rgb aa, Color_rgb bb) {
        return aa.r == bb.r && aa.g == bb.g && aa.b == bb.b;
    }

    bool operator!=(Color_rgb aa, Color_rgb bb) {
        return !(aa == bb);
    }

} // namespace Graphics_gtk3
