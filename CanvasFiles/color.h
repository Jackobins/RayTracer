//
// Created by Jack Wang on 12/22/2022.
//

#ifndef RAYTRACER_COLOR_H
#define RAYTRACER_COLOR_H


class color {
public:
    double r;
    double g;
    double b;

    color(double red, double green, double blue);
    color scalarMultiply(double scalar);
};


#endif //RAYTRACER_COLOR_H
