//
// Created by Jack Wang on 12/29/2022.
//

#ifndef RAYTRACER_SHAPE_H
#define RAYTRACER_SHAPE_H


#include "../../CoordFiles/point.h"
#include "../../CoordFiles/matrix.h"
#include "../../CoordFiles/vec.h"
#include "../../CoordFiles/coordOps.h"
#include "../../CoordFiles/matrixOps.h"
#include "material.h"

class shape {
public:
    int id;
    matrix transform = matrix(4,4,1);
    material surfaceMaterial;

    vec normalAt(point worldPoint, matrix inverseTransform) {
        point objectPoint = coordOps::coordToPoint(
                matrixOps::multiply(inverseTransform, worldPoint));
        vec objectNormal = coordOps::coordToVec(
                coordOps::subtract(objectPoint, point(0,0,0)));
        matrix transposeInverse = inverseTransform.transpose();
        vec worldNormal = coordOps::coordToVec(
                matrixOps::multiply(transposeInverse, objectNormal));
        worldNormal.w = 0;
        return worldNormal.normalize();
    };
};


#endif //RAYTRACER_SHAPE_H
