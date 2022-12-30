//
// Created by Jack Wang on 12/29/2022.
//

#ifndef RAYTRACER_INTERSECTION_H
#define RAYTRACER_INTERSECTION_H


#include "../Shapes/shape.h"

class intersection {
public:
    float t;
    shape object;

    intersection(float t, shape object);
};


#endif //RAYTRACER_INTERSECTION_H
