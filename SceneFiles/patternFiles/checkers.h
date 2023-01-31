//
// Created by Jack Wang on 1/31/2023.
//

#ifndef RAYTRACER_CHECKERS_H
#define RAYTRACER_CHECKERS_H


#include "pattern.h"

class checkers : public pattern {
public:
    color color1;
    color color2;

    checkers(color a, color b);
    color patternAt(point point) override;
};


#endif //RAYTRACER_CHECKERS_H
