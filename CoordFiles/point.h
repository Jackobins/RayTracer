//
// Created by Jack Wang on 12/22/2022.
//

#ifndef RAYTRACER_POINT_H
#define RAYTRACER_POINT_H

#include "coord.h"

class point : public coord {
public:
    point(double xCoord, double yCoord, double zCoord);
    point& operator=(const coord& coord) {
        x = coord.x;
        y = coord.y;
        z = coord.z;
        return *this;
    }
};


#endif //RAYTRACER_POINT_H
