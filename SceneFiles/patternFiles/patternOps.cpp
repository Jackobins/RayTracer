//
// Created by Jack Wang on 1/30/2023.
//

#include "patternOps.h"

color patternOps::patternAtObject(shape *object, pattern *pattern, point worldPoint) {
    point objectPoint = coordOps::coordToPoint(matrixOps::multiply(object->inverseTransform, worldPoint));
    point patternPoint = coordOps::coordToPoint(matrixOps::multiply(pattern->inverseTransform, objectPoint));
    return pattern->patternAt(patternPoint);
}
