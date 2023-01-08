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
    float fieldOfView;
    matrix transform;
    float halfWidth;
    float halfHeight;
    float pixelSize;

    camera(int hSize, int vSize, float fieldOfView);
    camera(int hSize, int vSize, float fieldOfView, matrix transform);
    void calculatePixelSize();
    ray rayForPixel(int px, int py, matrix inverseTransform);
};


#endif //RAYTRACER_CAMERA_H
