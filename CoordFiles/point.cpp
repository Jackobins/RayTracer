//
// Created by Jack Wang on 12/22/2022.
//
#include <tuple>
#include "point.h"

point::point(double xCoord, double yCoord, double zCoord) {
    x = xCoord;
    y = yCoord;
    z = zCoord;
    w = 1;
}
