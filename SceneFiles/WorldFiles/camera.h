//
// Created by Jack Wang on 1/6/2023.
//

#ifndef RAYTRACER_CAMERA_H
#define RAYTRACER_CAMERA_H


#include "../../CoordFiles/matrix.h"
#include "../RayFiles/ray.h"

class camera {
public:
    int hSize;
    int vSize;
    double fieldOfView;
    matrix inverseTransform;
    double halfWidth;
    double halfHeight;
    double pixelSize;

    camera(int hSize, int vSize, double fieldOfView);
    camera(int hSize, int vSize, double fieldOfView, matrix transform);
    void calculatePixelSize();
    ray rayForPixel(int px, int py);
    void setTransform(matrix transform);
};


#endif //RAYTRACER_CAMERA_H
