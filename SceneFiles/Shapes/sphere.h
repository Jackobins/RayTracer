//
// Created by Jack Wang on 12/29/2022.
//

#ifndef RAYTRACER_SPHERE_H
#define RAYTRACER_SPHERE_H


#include "../../CoordFiles/point.h"
#include "shape.h"
#include "../../CoordFiles/matrix.h"

class sphere : public shape {
public:
    int id;
    matrix transform;

    explicit sphere(int id);
    sphere(int id, matrix transform);
};


#endif //RAYTRACER_SPHERE_H
