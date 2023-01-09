//
// Created by Jack Wang on 12/31/2022.
//

#ifndef RAYTRACER_MATERIAL_H
#define RAYTRACER_MATERIAL_H


#include "../../CanvasFiles/color.h"

class material {
public:
    color surfaceColor;
    double ambient;
    double diffuse;
    double specular;
    double shininess;

    material();
    material(color surfaceColor, double ambient, double diffuse, double specular, double shininess);
};


#endif //RAYTRACER_MATERIAL_H
