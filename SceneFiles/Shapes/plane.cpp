//
// Created by Jack Wang on 1/29/2023.
//

#include "plane.h"

plane::plane() = default;

plane::plane(matrix transform, material material) {
    inverseTransform = transform.inverse();
    surfaceMaterial = material;
}

vec plane::normalAt(point localPoint) {
    vec objectNormal = vec(0,1,0);
    matrix transposeInverse = inverseTransform.transpose();
    vec worldNormal = coordOps::coordToVec(
            matrixOps::multiply(transposeInverse, objectNormal));
    worldNormal.w = 0;
    return worldNormal.normalize();
}

vector<double> plane::intersect(ray r) {
    if ((double)abs((double)r.direction.y) < EPSILON) {
        return {};
    }
    return {(double)-r.origin.y / (double)r.direction.y};
}
