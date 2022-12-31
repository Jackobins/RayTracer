//
// Created by Jack Wang on 12/31/2022.
//

#include "material.h"

material::material() : surfaceColor(color(1,1,1)) {
    ambient = 0.1;
    diffuse = 0.9;
    specular = 0.9;
    shininess = 200;
}

material::material(color color, float amb, float dif, float spec, float shin)
: surfaceColor(color) {
    surfaceColor = color;
    ambient = amb;
    diffuse = dif;
    specular = spec;
    shininess = shin;
}
