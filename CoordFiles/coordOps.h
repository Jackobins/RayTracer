//
// Created by Jack Wang on 12/22/2022.
//

#ifndef RAYTRACER_COORDOPS_H
#define RAYTRACER_COORDOPS_H

#include <cmath>
#include "coord.h"
#include "vec.h"
#include "point.h"

using namespace std;

class coordOps {
public:
    constexpr static double_t EPSILON = 0.0001;
    static bool areEqual(coord c1, coord c2);
    static coord add(coord c1, coord c2);
    static coord subtract (coord c1, coord c2);
    static double dot(vec v1, vec v2);
    static vec cross(vec v1, vec v2);
    static vec coordToVec(coord c);
    static point coordToPoint(coord c);
};

#endif //RAYTRACER_COORDOPS_H
