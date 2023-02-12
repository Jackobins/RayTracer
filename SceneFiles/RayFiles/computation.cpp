//
// Created by Jack Wang on 1/6/2023.
//

#include "computation.h"
#include "rayOps.h"
#include <algorithm>

computation::computation(intersection intersect, ray ray, vector<intersection> xs) :
regularPoint(ray.position(intersect.t)),
eyeVec(ray.direction.negate()),
normalVec(vec(1,1,1)),
overPoint(point(1,1,1)),
underPoint(point(1,1,1)),
reflectVec(vec(1,1,1)) {
    t = intersect.t;
    object = intersect.object;

    normalVec = intersect.object->normalAt(regularPoint);

    if (coordOps::dot(normalVec, eyeVec) < 0) {
        inside = true;
        normalVec = normalVec.negate();
    } else {
        inside = false;
    }
    reflectVec = rayOps::reflect(ray.direction, normalVec);
    overPoint = coordOps::coordToPoint(coordOps::add(regularPoint,
                                                     normalVec.scalarMultiply(EPSILON)));
    underPoint = coordOps::coordToPoint(coordOps::subtract(regularPoint,
                                                           normalVec.scalarMultiply(EPSILON)));

    vector<shape*> containers;
    for (intersection i : xs) {
        if (i.object == intersect.object && i.t == intersect.t) {
            if (containers.empty()) {
                n1 = 1.0;
            } else {
                n1 = containers.back()->surfaceMaterial.refractiveIndex;
            }
        }

        if (std::find(containers.begin(), containers.end(), i.object) != containers.end()) {
            containers.erase(std::remove(containers.begin(), containers.end(), i.object),
                             containers.end());
        } else {
            containers.push_back(i.object);
        }

        if (i.object == intersect.object && i.t == intersect.t) {
            if (containers.empty()) {
                n2 = 1.0;
            } else {
                n2 = containers.back()->surfaceMaterial.refractiveIndex;
            }
            break;
        }
    }
}
