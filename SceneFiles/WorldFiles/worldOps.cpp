//
// Created by Jack Wang on 1/6/2023.
//

#include "worldOps.h"
#include "../RayFiles/rayOps.h"

color worldOps::shadeHit(world world, computation comps, vector<matrix> inverseMatrices) {
    bool inShadow = isShadowed(world, comps.overPoint, inverseMatrices);
    return rayOps::lighting(comps.object.surfaceMaterial,
                            world.light,
                            comps.overPoint,
                            comps.eyeVec,
                            comps.normalVec,
                            inShadow);

    //// Note: can support multiple light sources by iterating over all light sources,
    ////       calling lighting() for each one, and adding the colors together.
}

//color worldOps::colorAt(const world& world, ray ray) {
//    vector<intersection> xs = rayOps::intersectWorld(world, ray);
//    vector<intersection> hits = rayOps::hit(xs);
//    if (hits.empty()) {
//        return color(0,0,0);
//    }
//    matrix inverseTransform = hitTracker.objectInverseTransform;
//    if (hits[0].object.id != hitTracker.object.id) {
//        inverseTransform = hits[0].object.transform.inverse();
//        hitTracker.object = hits[0].object;
//        hitTracker.objectInverseTransform = inverseTransform;
//    }
//    computation comps = computation(hits[0],
//                                    ray,
//                                    inverseTransform);
//    return shadeHit(world, comps);
//}

matrix worldOps::viewTransform(point from, point to, vec up) {
    vec forward = vec(to.x - from.x, to.y - from.y, to.z - from.z).normalize();
    vec left = coordOps::cross(forward, up.normalize());
    vec trueUp = coordOps::cross(left, forward);

    matrix m = matrix(4,4,1);
    m.writeRow(0, {left.x, left.y, left.z,0});
    m.writeRow(1, {trueUp.x, trueUp.y, trueUp.z,0});
    m.writeRow(2, {-1 * forward.x, -1 * forward.y, -1 * forward.z,0});

    return matrixOps::multiply(m, matrixOps::translationMatrix(-from.x,-from.y,-from.z));
}

canvas worldOps::render(camera camera, const world& world, const matrix& inverseTransform) {
    canvas image = canvas(camera.vSize, camera.hSize);
    shape currentObject = sphere(-100);
    matrix currentInverseTransform = matrix(4,4,1);

    vector<matrix> inverseMatrices;
    for (shape s : world.shapes) {
        inverseMatrices.push_back(s.transform.inverse());
    }

    for (int i = 0; i < camera.vSize; i++) {
        for (int j = 0; j < camera.hSize; j++) {
            ray r = camera.rayForPixel(j, i, inverseTransform);

            color c = color(0,0,0);
            vector<intersection> xs = rayOps::intersectWorld(world, r, inverseMatrices);
            vector<intersection> hits = rayOps::hit(xs);

            if (!hits.empty()) {
                if (hits[0].object.id != currentObject.id) {
                    currentObject = hits[0].object;
                    currentInverseTransform = currentObject.transform.inverse();
                }
                computation comps = computation(hits[0],
                                                r,
                                                currentInverseTransform);
                c = shadeHit(world, comps, inverseMatrices);
            }

            image.writePixel(i, j, c);
        }
    }

    return image;
}

bool worldOps::isShadowed(world world, point point, vector<matrix> inverseMatrices) {
    vec v = vec(world.light.position.x - point.x,
                world.light.position.y - point.y,
                world.light.position.z - point.z);
    double distance = v.magnitude();
    vec direction = v.normalize();

    ray r = ray(point, direction);
    vector<intersection> intersections = rayOps::intersectWorld(world, r, inverseMatrices);
    vector<intersection> hits = rayOps::hit(intersections);

    if (!hits.empty()) {
        if (hits[0].t < distance) {
            return true;
        }
    } else {
        return false;
    }
}
