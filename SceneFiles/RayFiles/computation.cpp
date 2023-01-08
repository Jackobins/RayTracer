//
// Created by Jack Wang on 1/6/2023.
//

#include "computation.h"

computation::computation(intersection intersection, ray ray, matrix inverseTransform) :
point(ray.position(intersection.t)),
eyeVec(ray.direction.negate()),
normalVec(vec(1,1,1)) {
    t = intersection.t;
    object = intersection.object;
    normalVec = intersection.object.normalAt(point, inverseTransform);
    if (coordOps::dot(normalVec, eyeVec) < 0) {
        inside = true;
        normalVec = normalVec.negate();
    } else {
        inside = false;
    }
}
