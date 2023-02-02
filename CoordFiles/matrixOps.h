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
    constexpr static double_t EPSILON = 0.0001;
    static bool areEqual(matrix m1, matrix m2);
    static matrix multiply(matrix m1, matrix m2);
    static coord multiply(matrix m, coord c);
    static matrix translationMatrix(double x, double y, double z);
    static matrix scalingMatrix(double x, double y, double z);
    static matrix rotationMatrix(int axis, double radians);
    static matrix shearMatrix(double xWithY, double xWithZ,
                              double yWithX, double yWithZ,
                              double zWithX, double zWithY);
};


#endif //RAYTRACER_MATRIXOPS_H
