//
// Created by Jack Wang on 12/22/2022.
//

#ifndef RAYTRACER_COLOR_H
#define RAYTRACER_COLOR_H


class color {
public:
    float r;
    float g;
    float b;

    color(float red, float green, float blue);
    color scalarMultiply(float scalar);
};


#endif //RAYTRACER_COLOR_H
