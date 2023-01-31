//
// Created by Jack Wang on 1/31/2023.
//

#ifndef RAYTRACER_BLENDEDPATTERN_H
#define RAYTRACER_BLENDEDPATTERN_H


#include "pattern.h"

class blendedPattern : public pattern {
public:
    pattern* pattern1;
    pattern* pattern2;

    blendedPattern(pattern* a, pattern* b);
    color patternAt(point point) override;
};


#endif //RAYTRACER_BLENDEDPATTERN_H
