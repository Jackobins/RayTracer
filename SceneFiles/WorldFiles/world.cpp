//
// Created by Jack Wang on 1/5/2023.
//

#include "world.h"
#include "../Shapes/sphere.h"
#include "../../CoordFiles/matrixOps.h"

world::world() : light(pointLight(point(-10,-10,-10),
                                  color(1,1,1))) {
    sphere s1 = sphere(-1);
    s1.surfaceMaterial.surfaceColor = color(0.8, 1, 0.6);
    s1.surfaceMaterial.diffuse = 0.7;
    s1.surfaceMaterial.specular = 0.2;
    sphere s2 = sphere(-2);
    s2.transform = matrixOps::scalingMatrix(0.5,0.5,0.5);

    shapes = {s1, s2};
}

world::world(pointLight pointLight, vector<shape> listOfShapes) : light(pointLight) {
    shapes = listOfShapes;
}
