//
// Created by Jack Wang on 12/29/2022.
//

#include "sphere.h"
#include "../../CoordFiles/matrixOps.h"
#include "../../CoordFiles/coordOps.h"

sphere::sphere(int i) {
    id = i;
    surfaceMaterial = material(color(1,1,1),
                               0.1, 0.9,0.9,200);
}

sphere::sphere(int i, matrix m, material mat) {
    id = i;
    transform = m;
    surfaceMaterial = mat;
}

vec sphere::normalAt(point worldPoint, matrix inverseTransform) {
    point objectPoint = coordOps::coordToPoint(
            matrixOps::multiply(inverseTransform, worldPoint));
    vec objectNormal = coordOps::coordToVec(
            coordOps::subtract(objectPoint, point(0,0,0)));
    matrix transposeInverse = inverseTransform.transpose();
    vec worldNormal = coordOps::coordToVec(
            matrixOps::multiply(transposeInverse, objectNormal));
    worldNormal.w = 0;
    return worldNormal.normalize();
}
