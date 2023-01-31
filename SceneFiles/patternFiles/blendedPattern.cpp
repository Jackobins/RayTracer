//
// Created by Jack Wang on 1/31/2023.
//

#include "blendedPattern.h"
#include "../../CanvasFiles/colorOps.h"

blendedPattern::blendedPattern(pattern *a, pattern *b) {
    pattern1 = a;
    pattern2 = b;
}

color blendedPattern::patternAt(point point) {
    color c1 = pattern1->patternAt(point);
    color c2 = pattern2->patternAt(point);
    return colorOps::average(c1, c2);
}
