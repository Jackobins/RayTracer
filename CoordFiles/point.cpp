//
// Created by Jack Wang on 12/22/2022.
//
#include <tuple>
#include "point.h"

point::point(float xcoord, float ycoord, float zcoord) {
    x = xcoord;
    y = ycoord;
    z = zcoord;
    w = 1;
}
