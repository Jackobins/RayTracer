//
// Created by Jack Wang on 12/31/2022.
//

#ifndef RAYTRACER_MATERIAL_H
#define RAYTRACER_MATERIAL_H


#include "../../CanvasFiles/color.h"
#include "../patternFiles/pattern.h"

class material {
public:
    color surfaceColor;
    pattern* pattern;
    double ambient;
    double diffuse;
    double specular;
    double shininess;
    double reflective;

    material();
    material(color surfaceColor, double ambient, double diffuse, double specular,
             double shininess, class pattern* p, double reflective);
};


#endif //RAYTRACER_MATERIAL_H
