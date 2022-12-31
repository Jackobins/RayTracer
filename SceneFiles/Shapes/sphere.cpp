//
// Created by Jack Wang on 12/29/2022.
//

#include "sphere.h"
#include "../../CoordFiles/matrixOps.h"
#include "../../CoordFiles/coordOps.h"

sphere::sphere(int i) :
transform(matrix(4, 4, 1)),
surfaceMaterial(material(color(1,1,1),
                         0.1,0.9,0.9,200)) {
    id = i;
}

sphere::sphere(int i, matrix m, material mat) : transform(m), surfaceMaterial(mat) {
    id = i;
    transform = m;
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
