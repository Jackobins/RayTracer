//
// Created by Jack Wang on 12/31/2022.
//

#ifndef RAYTRACER_MATERIAL_H
#define RAYTRACER_MATERIAL_H


#include "../../CanvasFiles/color.h"

class material {
public:
    color surfaceColor;
    float ambient;
    float diffuse;
    float specular;
    float shininess;

    material();
    material(color surfaceColor, float ambient, float diffuse, float specular, float shininess);
};


#endif //RAYTRACER_MATERIAL_H
