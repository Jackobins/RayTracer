//
// Created by Jack Wang on 1/5/2023.
//

#ifndef RAYTRACER_WORLD_H
#define RAYTRACER_WORLD_H


#include "../RayFiles/pointLight.h"
#include "../Shapes/shape.h"
#include <vector>

using namespace std;

class world {
public:
    pointLight light;
    vector<shape*> shapes;

    world();
    world(pointLight pointLight, vector<shape*> listOfShapes);
    void addShape(shape* s);
};


#endif //RAYTRACER_WORLD_H
