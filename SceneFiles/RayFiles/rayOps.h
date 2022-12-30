//
// Created by Jack Wang on 12/29/2022.
//

#ifndef RAYTRACER_RAYOPS_H
#define RAYTRACER_RAYOPS_H


#include "../Shapes/shape.h"
#include "ray.h"
#include "intersection.h"
#include "../Shapes/sphere.h"
#include <vector>

class rayOps {
public:
    static vector<intersection> intersect(sphere s, ray r);
    static vector<intersection> hit(vector<intersection> intersections);
};

#endif //RAYTRACER_RAYOPS_H
