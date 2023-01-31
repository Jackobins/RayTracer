//
// Created by Jack Wang on 1/30/2023.
//

#include <cmath>
#include "stripes.h"

stripes::stripes(color a, color b) : color1(a), color2(b) {
}

color stripes::patternAt(point point) {
    if ((int)floor(point.x) % 2 == 0) {
        return color1;
    } else {
        return color2;
    }
}
