//
// Created by Jack Wang on 1/6/2023.
//

#include "computation.h"
#include "rayOps.h"

computation::computation(intersection intersection, ray ray) :
regularPoint(ray.position(intersection.t)),
eyeVec(ray.direction.negate()),
normalVec(vec(1,1,1)),
overPoint(point(1,1,1)),
reflectVec(vec(1,1,1)) {
    t = intersection.t;
    object = intersection.object;

    normalVec = intersection.object->normalAt(regularPoint);

    if (coordOps::dot(normalVec, eyeVec) < 0) {
        inside = true;
        normalVec = normalVec.negate();
    } else {
        inside = false;
    }
    reflectVec = rayOps::reflect(ray.direction, normalVec);
    overPoint = coordOps::coordToPoint(coordOps::add(regularPoint,
                                                     normalVec.scalarMultiply(EPSILON)));
}
