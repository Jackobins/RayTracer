//
// Created by Jack Wang on 1/31/2023.
//

#include <cmath>
#include "ring.h"

ring::ring(color a, color b) : color1(a), color2(b) {
}

color ring::patternAt(point point) {
    if ((int) (floor(sqrt(pow(point.x, 2) + pow(point.z, 2)))) % 2 == 0) {
        return color1;
    } else {
        return color2;
    }
}
