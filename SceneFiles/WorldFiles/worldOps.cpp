//
// Created by Jack Wang on 1/6/2023.
//

#include "worldOps.h"
#include "../RayFiles/rayOps.h"
#include "../../CanvasFiles/colorOps.h"

color worldOps::shadeHit(world* world, computation comps, int remaining) {
    bool inShadow = isShadowed(world, comps.overPoint);
    color surface = rayOps::lighting(comps.object->surfaceMaterial,
                                     comps.object,
                                     world->light,
                                     comps.overPoint,
                                     comps.eyeVec,
                                     comps.normalVec,
                                     inShadow);
    color reflected = reflectedColor(world, comps, remaining);
    color refracted = refractedColor(world, comps, remaining);
    color c = colorOps::add(surface, reflected);
    return colorOps::add(c, refracted);

    //// Note: can support multiple light sources by iterating over all light sources,
    ////       calling rayOps::lighting() for each one, and adding the colors together.
}

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

canvas worldOps::render(camera* camera, world* world) {
    canvas image = canvas(camera->vSize, camera->hSize);

    for (int i = 0; i < camera->vSize; i++) {
        for (int j = 0; j < camera->hSize; j++) {
            ray r = camera->rayForPixel(j, i);
            color c = colorAt(world, r, 4);
            image.writePixel(i, j, c);
        }
    }

    return image;
}

bool worldOps::isShadowed(world* world, point point) {
    vec v = vec(world->light.position.x - point.x,
                world->light.position.y - point.y,
                world->light.position.z - point.z);
    double distance = v.magnitude();
    vec direction = v.normalize();

    ray r = ray(point, direction);
    vector<intersection> intersections = rayOps::intersectWorld(world, r);
    vector<intersection> hits = rayOps::hit(intersections);

    if (!hits.empty()) {
        if (hits[0].t < distance) {
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

color worldOps::reflectedColor(world *world, computation comps, int remaining) {
    if (comps.object->surfaceMaterial.reflective == 0 || remaining < 1) {
        return color(0,0,0);
    }

    ray reflectRay = ray(comps.overPoint, comps.reflectVec);
    color c = colorAt(world, reflectRay, remaining-1);
    c = c.scalarMultiply(comps.object->surfaceMaterial.reflective);
    return c;
}

color worldOps::colorAt(world *world, ray r, int remaining) {
    vector<intersection> intersections = rayOps::intersectWorld(world, r);
    vector<intersection> hit = rayOps::hit(intersections);
    if (hit.empty()) {
        return color(0,0,0);
    }
    computation comps = computation(hit[0], r, intersections);
    return shadeHit(world, comps, remaining);
}

color worldOps::refractedColor(world *world, computation comps, int remaining) {
    if (comps.object->surfaceMaterial.transparency == 0 || remaining == 0) {
        return color(0,0,0);
    }

    double nRatio = (double) comps.n1 / (double) comps.n2;
    double cosTheta1 = coordOps::dot(comps.eyeVec, comps.normalVec);
    double sin2Theta2 = pow(nRatio, 2) * (1-pow(cosTheta1,2));
    if (sin2Theta2 > 1) {
        return color(0,0,0);
    }

    double cosTheta2 = sqrt(1.0 - sin2Theta2);
    vec direction = coordOps::coordToVec(
            coordOps::subtract(comps.normalVec.scalarMultiply(nRatio*cosTheta1 - cosTheta2),
                               comps.eyeVec.scalarMultiply(nRatio))
            );
    ray refractRay = ray(comps.underPoint, direction);
    color c = colorAt(world, refractRay, remaining - 1)
            .scalarMultiply(comps.object->surfaceMaterial.transparency);

    return c;
}
