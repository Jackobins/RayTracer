//
// Created by Jack Wang on 12/29/2022.
//

#include "sphere.h"
#include "../../CoordFiles/matrixOps.h"
#include "../../CoordFiles/coordOps.h"

sphere::sphere(int i) {
    id = i;
}

sphere::sphere(int i, matrix m, material mat) {
    id = i;
    inverseTransform = m.inverse();
    surfaceMaterial = mat;
}

vec sphere::normalAt(point localPoint) {
    point objectPoint = coordOps::coordToPoint(
            matrixOps::multiply(inverseTransform, localPoint));
    vec objectNormal = coordOps::coordToVec(coordOps::subtract(objectPoint,
                                                               point(0,0,0)));
    matrix transposeInverse = inverseTransform.transpose();
    vec worldNormal = coordOps::coordToVec(
            matrixOps::multiply(transposeInverse, objectNormal));
    worldNormal.w = 0;
    return worldNormal.normalize();
}
