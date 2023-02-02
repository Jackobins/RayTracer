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
}

material::material(color color, double amb, double dif, double spec, double shin, class pattern* p, double r)
: surfaceColor(color) {
    surfaceColor = color;
    ambient = amb;
    diffuse = dif;
    specular = spec;
    shininess = shin;
    pattern = p;

    reflective = r;
    if (r > 1) reflective = 1.0;
    if (r < 0) reflective = 0.0;
}
