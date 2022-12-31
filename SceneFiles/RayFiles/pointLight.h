//
// Created by Jack Wang on 12/31/2022.
//

#ifndef RAYTRACER_POINTLIGHT_H
#define RAYTRACER_POINTLIGHT_H


#include "../../CanvasFiles/color.h"
#include "../../CoordFiles/point.h"

class pointLight {
public:
    color intensity;
    point position;

    pointLight(point position, color intensity);
};


#endif //RAYTRACER_POINTLIGHT_H
