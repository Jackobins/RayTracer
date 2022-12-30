//
// Created by Jack Wang on 12/22/2022.
//

#ifndef RAYTRACER_VEC_H
#define RAYTRACER_VEC_H
#include "coord.h"

class vec : public coord {
public:
    vec(float xcoord, float ycoord, float zcoord);
    vec(float xcoord, float ycoord, float zcoord, float wcoord);

    vec negate();
    float magnitude();
    vec scalarMultiply(float scalar);
    vec normalize();

    vec& operator=(const coord& coord) {
        x = coord.x;
        y = coord.y;
        z = coord.z;
        return *this;
    }
};


#endif //RAYTRACER_VEC_H
