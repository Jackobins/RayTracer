//
// Created by Jack Wang on 12/22/2022.
//

#include "coordOps.h"
#include "point.h"
#include "vec.h"
#include <iostream>

bool coordOps::areEqual(coord c1, coord c2) {
    return
            abs(c1.x - c2.x) <= EPSILON
            && abs(c1.y - c2.y) <= EPSILON
            && abs(c1.z - c2.z) <= EPSILON
            && abs((float)c1.w - (float)c2.w) <= EPSILON;
}

coord coordOps::add(coord c1, coord c2) {
    if (c1.w + c2.w == 1) {
        point p = point(c1.x + c2.x,c1.y + c2.y,c1.z + c2.z);
        return p;
    } else if (c1.w + c2.w == 0) {
        vec v = vec(c1.x + c2.x,c1.y + c2.y,c1.z + c2.z);
        return v;
    } else {
        cout << "!!! Can't compute !!!" << endl;
        return c1;
    }
}

coord coordOps::subtract(coord c1, coord c2) {
    if (c1.w == 1 && c2.w == 1) {
        return vec(c1.x - c2.x, c1.y - c2.y, c1.z - c2.z);
    } else if (c1.w == 0 && c2.w == 0) {
        return vec(c1.x - c2.x, c1.y - c2.y, c1.z - c2.z);
    } else if (c1.w == 1 && c2.w == 0) {
        return point(c1.x - c2.x, c1.y - c2.y, c1.z - c2.z);
    } else {
        cout << "!!! Can't compute !!!" << endl;
        return c1;
    }
}

float coordOps::dot(vec v1, vec v2) {
    return (float) (
            (v1.x * v2.x)
            + (v1.y * v2.y)
            + (v1.z * v2.z)
            );
}

vec coordOps::cross(vec v1, vec v2) {
    float newX = (v1.y * v2.z) - (v1.z * v2.y);
    float newY = (v1.z * v2.x) - (v1.x * v2.z);
    float newZ = (v1.x * v2.y) - (v1.y * v2.x);
    vec v = vec(newX, newY, newZ);
    return v;
}

vec coordOps::coordToVec(coord c) {
    return vec(c.x, c.y, c.z);
}

point coordOps::coordToPoint(coord c) {
    return point(c.x, c.y, c.z);
}
