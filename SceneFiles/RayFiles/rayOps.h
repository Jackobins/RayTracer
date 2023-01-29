//
// Created by Jack Wang on 12/29/2022.
//

#ifndef RAYTRACER_RAYOPS_H
#define RAYTRACER_RAYOPS_H


#include "../Shapes/shape.h"
#include "ray.h"
#include "intersection.h"
#include "../Shapes/sphere.h"
#include "pointLight.h"
#include "../WorldFiles/world.h"
#include "computation.h"
#include <vector>

class rayOps {
public:
    static vector<intersection> intersect(shape* s, ray r);
    static vector<intersection> intersectWorld(world* w, ray r);
    static vector<intersection> hit(vector<intersection> intersections);
    static vec reflect(vec in, vec normal);
    static color lighting(material material, pointLight light,
                          point point, vec eyeVec, vec normalVec, bool inShadow);
};

#endif //RAYTRACER_RAYOPS_H
