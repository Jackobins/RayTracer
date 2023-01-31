//
// Created by Jack Wang on 1/31/2023.
//

#include <cmath>
#include "gradient.h"
#include "../../CoordFiles/coordOps.h"
#include "../../CanvasFiles/colorOps.h"

gradient::gradient(color a, color b) : color1(a), color2(b) {
}

color gradient::patternAt(point point) {
    double fraction = point.x - floor(point.x);
    color distance = colorOps::subtract(color2, color1);
    distance = distance.scalarMultiply(fraction);
    return colorOps::add(color1, distance);
}
