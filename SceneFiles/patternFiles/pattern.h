//
// Created by Jack Wang on 1/30/2023.
//

#ifndef RAYTRACER_PATTERN_H
#define RAYTRACER_PATTERN_H

#include <iostream>
#include "../../CoordFiles/matrix.h"
#include "../../CanvasFiles/color.h"
#include "../../CoordFiles/point.h"

class pattern {
public:
    matrix inverseTransform = matrix(4,4,1);

    virtual color patternAt(point worldPoint) {
        cout << "super patternAt called" << endl;
        return color(0,0,0);
    }

    void setTransform(matrix transform) {
        inverseTransform = transform.inverse();
    }
};

#endif //RAYTRACER_PATTERN_H
