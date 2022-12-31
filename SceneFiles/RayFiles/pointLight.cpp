//
// Created by Jack Wang on 12/31/2022.
//

#include "pointLight.h"

pointLight::pointLight(point p, color c) : intensity(c), position(p) {
    intensity = c;
    position = p;
}
