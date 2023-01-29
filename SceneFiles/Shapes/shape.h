//
// Created by Jack Wang on 12/29/2022.
//

#ifndef RAYTRACER_SHAPE_H
#define RAYTRACER_SHAPE_H


#include "../../CoordFiles/point.h"
#include "../../CoordFiles/matrix.h"
#include "../../CoordFiles/vec.h"
#include "../../CoordFiles/coordOps.h"
#include "../../CoordFiles/matrixOps.h"
#include <iostream>
#include "material.h"

class shape {
public:
    int id;
    matrix inverseTransform = matrix(4,4,1);
    material surfaceMaterial = material(color(1,1,1),
                                        0.1, 0.9,0.9,200);

    virtual vec normalAt(point worldPoint) {
        cout << "super called" << endl;
        return vec(0,0,0);
    }

    void setTransform(matrix transform) {
        inverseTransform = transform.inverse();
    }
};

#endif //RAYTRACER_SHAPE_H
