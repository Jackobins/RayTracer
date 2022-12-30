//
// Created by Jack Wang on 12/22/2022.
//

#include "color.h"

color::color(float red, float green, float blue) {
    r = red;
    g = green;
    b = blue;
}

color color::scalarMultiply(float scalar) {
    r *= scalar;
    g *= scalar;
    b *= scalar;
    return *this;
}
