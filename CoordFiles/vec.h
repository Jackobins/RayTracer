//
// Created by Jack Wang on 12/22/2022.
//

#ifndef RAYTRACER_VEC_H
#define RAYTRACER_VEC_H
#include "coord.h"

class vec : public coord {
public:
    vec(double xcoord, double ycoord, double zcoord);
    vec(double xcoord, double ycoord, double zcoord, double wcoord);

    vec negate();
    double magnitude();
    vec scalarMultiply(double scalar);
    vec normalize();

    vec& operator=(const coord& coord) {
        x = coord.x;
        y = coord.y;
        z = coord.z;
        return *this;
    }
};


#endif //RAYTRACER_VEC_H
