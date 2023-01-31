//
// Created by Jack Wang on 1/30/2023.
//

#ifndef RAYTRACER_STRIPES_H
#define RAYTRACER_STRIPES_H


#include "../../CanvasFiles/color.h"
#include "../../CoordFiles/point.h"
#include "../../CoordFiles/matrix.h"
#include "pattern.h"

class stripes : public pattern {
public:
    color color1;
    color color2;

    stripes(color a, color b);
    color patternAt(point point) override;
};


#endif //RAYTRACER_STRIPES_H
