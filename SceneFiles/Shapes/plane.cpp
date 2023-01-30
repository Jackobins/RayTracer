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
    return vec(0,1,0);
}

vector<double> plane::intersect(ray r) {
    if (abs(r.direction.y) < EPSILON) {
        return {};
    }
    return {-r.origin.y / r.direction.y};
}
