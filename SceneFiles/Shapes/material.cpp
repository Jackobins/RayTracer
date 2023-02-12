//
// Created by Jack Wang on 12/31/2022.
//

#include "material.h"

material::material() : surfaceColor(color(1,1,1)) {
    ambient = 0.1;
    diffuse = 0.9;
    specular = 0.9;
    shininess = 200;
    pattern = nullptr;
    reflective = 0.0;
    transparency = 0.0;
    refractiveIndex = 1.0;
}
