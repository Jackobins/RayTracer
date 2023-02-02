//
// Created by Jack Wang on 1/29/2023.
//

#include "plane.h"

plane::plane() = default;

plane::plane(matrix transform, material material) {
    inverseTransform = transform.inverse();
    surfaceMaterial = material;
}

vec plane::normalAt(point point) {
    return coordOps::coordToVec(matrixOps::multiply(inverseTransform, vec(0,1,0)));
}

vector<double> plane::intersect(ray r) {
    if ((double)abs((double)r.direction.y) < EPSILON) {
        return {};
    }
    return {(double)-r.origin.y / (double)r.direction.y};
}
