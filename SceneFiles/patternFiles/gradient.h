//
// Created by Jack Wang on 1/31/2023.
//

#ifndef RAYTRACER_GRADIENT_H
#define RAYTRACER_GRADIENT_H


#include "pattern.h"

class gradient : public pattern {
public:
    color color1;
    color color2;

    gradient(color a, color b);
    color patternAt(point point) override;
};


#endif //RAYTRACER_GRADIENT_H
