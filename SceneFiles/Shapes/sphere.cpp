//
// Created by Jack Wang on 12/29/2022.
//

#include "sphere.h"
#include "../../CoordFiles/matrixOps.h"
#include "../../CoordFiles/coordOps.h"

sphere::sphere(int i) :
transform(matrix(4, 4, 1)) {
    id = i;
}

sphere::sphere(int i, matrix m) : transform(m) {
    id = i;
}

vec sphere::normalAt(point worldPoint) {
    matrix inverseTransform = transform.inverse();
    point objectPoint = coordOps::coordToPoint(
            matrixOps::multiply(inverseTransform, worldPoint));
    vec objectNormal = coordOps::coordToVec(objectPoint);
    matrix transposeInverse = inverseTransform.transpose();
    vec worldNormal = coordOps::coordToVec(
            matrixOps::multiply(transposeInverse, objectNormal));
    worldNormal.w = 0;
    return worldNormal.normalize();
}
