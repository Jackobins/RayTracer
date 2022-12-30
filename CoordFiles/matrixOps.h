//
// Created by Jack Wang on 12/23/2022.
//

#ifndef RAYTRACER_MATRIXOPS_H
#define RAYTRACER_MATRIXOPS_H

#include "matrix.h"
#include "coord.h"
#include <cmath>

class matrixOps {
public:
    constexpr static float EPSILON = 0.00001;
    static bool areEqual(matrix m1, matrix m2);
    static matrix multiply(matrix m1, matrix m2);
    static coord multiply(matrix m, coord c);
    static matrix translationMatrix(float x, float y, float z);
    static matrix scalingMatrix(float x, float y, float z);
    static matrix rotationMatrix(int axis, float radians);
    static matrix shearMatrix(float xWithY, float xWithZ,
                              float yWithX, float yWithZ,
                              float zWithX, float zWithY);
};


#endif //RAYTRACER_MATRIXOPS_H
