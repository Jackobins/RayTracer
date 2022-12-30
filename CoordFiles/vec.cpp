//
// Created by Jack Wang on 12/22/2022.
//

#include "vec.h"
#include<cmath>

vec::vec(float xcoord, float ycoord, float zcoord) : coord() {
    x = xcoord;
    y = ycoord;
    z = zcoord;
    w = 0;
}

vec::vec(float xcoord, float ycoord, float zcoord, float wcoord) : coord() {
    x = xcoord;
    y = ycoord;
    z = zcoord;
    w = wcoord;
}

vec vec::negate() {
    vec vec2 = vec(x * -1, y * -1, z* -1);
    if (w != 0) {
        vec2.w *= -1;
    }
    return vec2;
}

float vec::magnitude() {
    return (float) sqrt(pow(x, 2) +
    pow(y, 2) +
    pow(z, 2));
}

vec vec::scalarMultiply(float scalar) {
    vec vec2 = vec(x * scalar, y * scalar, z* scalar);
    if (w != 0) {
        vec2.w *= scalar;
    }
    return vec2;
}

vec vec::normalize() {
    scalarMultiply(1/magnitude());
    return *this;
}
