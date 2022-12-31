//
// Created by Jack Wang on 12/29/2022.
//

#ifndef RAYTRACER_SPHERE_H
#define RAYTRACER_SPHERE_H


#include "../../CoordFiles/point.h"
#include "shape.h"
#include "../../CoordFiles/matrix.h"
#include "../../CoordFiles/vec.h"
#include "material.h"

class sphere : public shape {
public:
    int id;
    matrix transform;
    material surfaceMaterial;

    explicit sphere(int id);
    sphere(int id, matrix transform, material material);
    vec normalAt(point point, matrix inverseTransform);
};


#endif //RAYTRACER_SPHERE_H
