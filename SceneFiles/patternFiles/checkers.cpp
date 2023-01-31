//
// Created by Jack Wang on 1/31/2023.
//

#include <cmath>
#include "checkers.h"

checkers::checkers(color a, color b) : color1(a), color2(b) {
}

color checkers::patternAt(point point) {
    int dimensionSum = floor(point.x) + floor(point.y) + floor(point.z);
    if (dimensionSum % 2 == 0) {
        return color1;
    } else {
        return color2;
    }
}
