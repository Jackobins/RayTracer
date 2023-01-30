//
// Created by Jack Wang on 1/29/2023.
//

#ifndef RAYTRACER_PLANE_H
#define RAYTRACER_PLANE_H


#include "../../CoordFiles/matrix.h"
#include "material.h"
#include "shape.h"

class plane : public shape {
public:
    constexpr static double EPSILON = 0.00001;

    explicit plane();
    plane(matrix transform, material material);
    vec normalAt(point point) override;
    vector<double> intersect(ray r) override;
};


#endif //RAYTRACER_PLANE_H
