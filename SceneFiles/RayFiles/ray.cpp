//
// Created by Jack Wang on 12/29/2022.
//

#include "ray.h"
#include "../../CoordFiles/coordOps.h"
#include "../../CoordFiles/matrixOps.h"

ray::ray(point point, vec vec) : origin(point), direction(vec) {
    origin = point;
    direction = vec;
}

point ray::position(float t) {
    return coordOps::coordToPoint(coordOps::add(origin, direction.scalarMultiply(t)));
}

ray ray::transform(matrix m) {
    point newOrigin = coordOps::coordToPoint(matrixOps::multiply(m, origin));
    vec newDirection = coordOps::coordToVec(matrixOps::multiply(m, direction));
    return ray(newOrigin, newDirection);
}
