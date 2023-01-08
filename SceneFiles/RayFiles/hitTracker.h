//
// Created by Jack Wang on 1/8/2023.
//

#ifndef RAYTRACER_HITTRACKER_H
#define RAYTRACER_HITTRACKER_H


#include "intersection.h"
#include "../Shapes/sphere.h"

class hitTracker {
public:
    shape object;
    matrix objectInverseTransform;

    hitTracker() : object(sphere(-100)),
    objectInverseTransform(matrix(4,4,1)) {}
};


#endif //RAYTRACER_HITTRACKER_H
