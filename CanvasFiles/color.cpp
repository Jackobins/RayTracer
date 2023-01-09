//
// Created by Jack Wang on 12/22/2022.
//

#include "color.h"

color::color(double red, double green, double blue) {
    r = red;
    g = green;
    b = blue;
}

color color::scalarMultiply(double scalar) {
    return color(r * scalar, g * scalar, b * scalar);
}
