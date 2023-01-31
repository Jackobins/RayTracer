//
// Created by Jack Wang on 1/30/2023.
//

#ifndef RAYTRACER_PATTERNOPS_H
#define RAYTRACER_PATTERNOPS_H


#include "../../CanvasFiles/color.h"
#include "../Shapes/shape.h"
#include "stripes.h"

class patternOps {
public:
    static color patternAtObject(shape* object, pattern* pattern, point point);
};


#endif //RAYTRACER_PATTERNOPS_H
