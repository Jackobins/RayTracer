//
// Created by Jack Wang on 12/22/2022.
//

#include "vec.h"
#include<cmath>

vec::vec(double xcoord, double ycoord, double zcoord) : coord() {
    x = xcoord;
    y = ycoord;
    z = zcoord;
    w = 0;
}

vec::vec(double xcoord, double ycoord, double zcoord, double wcoord) : coord() {
    x = xcoord;
    y = ycoord;
    z = zcoord;
    w = wcoord;
}

vec vec::negate() {
    vec vec2 = vec(x * -1, y * -1, z* -1);
    if (w != 0) {
        vec2.w = -1 * w;
    }
    return vec2;
}

double vec::magnitude() {
    return (double) sqrt(pow(x, 2) +
    pow(y, 2) +
    pow(z, 2));
}

vec vec::scalarMultiply(double scalar) {
    vec vec2 = vec(x * scalar, y * scalar, z* scalar);
    if (w != 0) {
        vec2.w *= scalar;
    }
    return vec2;
}

vec vec::normalize() {
    vec vec2 = scalarMultiply(1/magnitude());
    return vec2;
}
