//
// Created by Jack Wang on 12/23/2022.
//

#ifndef RAYTRACER_CANVAS_H
#define RAYTRACER_CANVAS_H


#include "color.h"
#include <vector>
#include <string>

using namespace std;

class canvas {
public:
    vector<vector<color>> frame;

    canvas(int height, int width);
    size_t height();
    size_t width();
    void writePixel(int row, int column, color color);
    string toPPM();
};


#endif //RAYTRACER_CANVAS_H
