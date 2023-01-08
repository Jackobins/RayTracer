//
// Created by Jack Wang on 1/6/2023.
//

#include "camera.h"
#include "../../CoordFiles/matrixOps.h"
#include "../../CoordFiles/coordOps.h"
#include <cmath>
#include <iostream>

camera::camera(int h, int v, float fov) : transform(matrix(4,4,1)) {
    hSize = h;
    vSize = v;
    fieldOfView = fov;
    calculatePixelSize();
}


camera::camera(int h, int v, float fov, matrix transform) :
transform(transform){
    hSize = h;
    vSize = v;
    fieldOfView = fov;
    calculatePixelSize();
}

void camera::calculatePixelSize() {
    float halfView = tan(fieldOfView/2);
    float aspect = ((float)hSize/(float)vSize);
    if (aspect >= 1) {
        halfWidth = halfView;
        halfHeight = halfView / aspect;
    } else {
        halfWidth = halfView * aspect;
        halfHeight = halfView;
    }
    pixelSize = (2 * halfWidth) / hSize;
}

ray camera::rayForPixel(int px, int py, matrix inverseTransform) {
    float xOffset = (px + 0.5) * pixelSize;
    float yOffset = (py + 0.5) * pixelSize;
    float worldX = halfWidth - xOffset;
    float worldY = halfHeight - yOffset;

    point pixel = coordOps::coordToPoint(matrixOps::multiply(
            inverseTransform, point(worldX, worldY, -1)));
    point origin = coordOps::coordToPoint(matrixOps::multiply(
            inverseTransform, point(0,0,0)));
    vec direction = vec(pixel.x - origin.x,
                        pixel.y - origin.y,
                        pixel.z - origin.z).normalize();
    return ray(origin, direction);
}
