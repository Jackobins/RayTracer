//
// Created by Jack Wang on 1/31/2023.
//

#ifndef RAYTRACER_RING_H
#define RAYTRACER_RING_H


#include "pattern.h"

class ring : public pattern {
public:
    color color1;
    color color2;

    ring(color a, color b);
    color patternAt(point point) override;
};


#endif //RAYTRACER_RING_H
