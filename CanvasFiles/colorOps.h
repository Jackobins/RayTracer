//
// Created by Jack Wang on 12/22/2022.
//

#ifndef RAYTRACER_COLOROPS_H
#define RAYTRACER_COLOROPS_H


#include "color.h"

class colorOps {
public:
    static color add(color c1, color c2);
    static color subtract (color c1, color c2);
    static color multiply (color c1, color c2);
    static color average(color c1, color c2);
};


#endif //RAYTRACER_COLOROPS_H
