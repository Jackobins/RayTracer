//
// Created by Jack Wang on 1/6/2023.
//

#ifndef RAYTRACER_COMPUTATION_H
#define RAYTRACER_COMPUTATION_H


#include "../Shapes/shape.h"
#include "../../CoordFiles/vec.h"
#include "intersection.h"
#include "ray.h"
#include "../Shapes/sphere.h"

class computation {
public:
    constexpr static double_t EPSILON = 0.00001;
    double t;
    shape object;
    point regularPoint;
    point overPoint;
    vec eyeVec;
    vec normalVec;
    bool inside;

    computation(intersection intersection, ray ray, matrix inverseTransform);
};


#endif //RAYTRACER_COMPUTATION_H
