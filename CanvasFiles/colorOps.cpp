//
// Created by Jack Wang on 12/22/2022.
//

#include "colorOps.h"

color colorOps::add(color c1, color c2) {
    color c = color(c1.r + c2.r, c1.g + c2.g, c1.b + c2.b);
    return c;
}

color colorOps::subtract(color c1, color c2) {
    color c = color(c1.r - c2.r, c1.g - c2.g, c1.b - c2.b);
    return c;
}

color colorOps::multiply(color c1, color c2) {
    color c = color(c1.r * c2.r, c1.g * c2.g, c1.b * c2.b);
    return c;
}
