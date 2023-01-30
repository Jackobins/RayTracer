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
    explicit sphere();
    sphere(matrix transform, material material);
    vec normalAt(point point) override;
    vector<double> intersect(ray r) override;
};


#endif //RAYTRACER_SPHERE_H
