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
    constexpr static double_t EPSILON = 0.0001;
    double t;
    shape* object;
    point regularPoint;
    point overPoint;
    point underPoint;
    vec eyeVec;
    vec normalVec;
    vec reflectVec;
    bool inside;
    double n1;
    double n2;

    computation(intersection intersect, ray ray, vector<intersection> xs);
    double schlick();
};


#endif //RAYTRACER_COMPUTATION_H
