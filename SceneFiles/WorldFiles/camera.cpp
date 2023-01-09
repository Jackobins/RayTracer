//
// Created by Jack Wang on 1/6/2023.
//

#include "camera.h"
#include "../../CoordFiles/matrixOps.h"
#include "../../CoordFiles/coordOps.h"
#include <cmath>
#include <iostream>

camera::camera(int h, int v, double fov) : transform(matrix(4,4,1)) {
    hSize = h;
    vSize = v;
    fieldOfView = fov;
    calculatePixelSize();
}


camera::camera(int h, int v, double fov, matrix transform) :
transform(transform){
    hSize = h;
    vSize = v;
    fieldOfView = fov;
    calculatePixelSize();
}

void camera::calculatePixelSize() {
    double halfView = tan(fieldOfView/2);
    double aspect = ((double)hSize/(double)vSize);
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
    double xOffset = (px + 0.5) * pixelSize;
    double yOffset = (py + 0.5) * pixelSize;
    double worldX = halfWidth - xOffset;
    double worldY = halfHeight - yOffset;

    point pixel = coordOps::coordToPoint(matrixOps::multiply(
            inverseTransform, point(worldX, worldY, -1)));
    point origin = coordOps::coordToPoint(matrixOps::multiply(
            inverseTransform, point(0,0,0)));
    vec direction = vec(pixel.x - origin.x,
                        pixel.y - origin.y,
                        pixel.z - origin.z).normalize();
    return ray(origin, direction);
}
