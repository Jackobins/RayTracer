//
// Created by Jack Wang on 1/6/2023.
//

#ifndef RAYTRACER_WORLDOPS_H
#define RAYTRACER_WORLDOPS_H


#include "../../CanvasFiles/color.h"
#include "world.h"
#include "../RayFiles/computation.h"
#include "../../CanvasFiles/canvas.h"
#include "camera.h"
#include "../RayFiles/hitTracker.h"

class worldOps {
public:
    static color shadeHit(world world, computation comps);
    static color colorAt(const world& world, ray ray);
    static matrix viewTransform(point from, point to, vec up);
    static canvas render(camera camera, const world &world, const matrix& inverseTransform);
};


#endif //RAYTRACER_WORLDOPS_H
