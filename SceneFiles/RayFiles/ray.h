//
// Created by Jack Wang on 12/29/2022.
//

#ifndef RAYTRACER_RAY_H
#define RAYTRACER_RAY_H


#include "../../CoordFiles/point.h"
#include "../../CoordFiles/vec.h"
#include "../../CoordFiles/matrix.h"

class ray {
public:
    point origin;
    vec direction;

    ray(point origin, vec direction);
    point position(float t);
    ray transform(matrix m);
};

#endif //RAYTRACER_RAY_H
