//
// Created by Jack Wang on 12/29/2022.
//

#include "rayOps.h"
#include "../../CoordFiles/coordOps.h"
#include "../../CanvasFiles/colorOps.h"
#include <cmath>
#include <iostream>

vector<intersection> rayOps::intersect(sphere s, ray r, matrix inverseTransform) {
    ray r2 = r.transform(inverseTransform);

    vec sphereToRay = vec(r2.origin.x - 0, r2.origin.y - 0, r2.origin.z - 0);
    float a = coordOps::dot(r2.direction, r2.direction);
    float b = 2 * coordOps::dot(r2.direction, sphereToRay);
    float c = coordOps::dot(sphereToRay, sphereToRay) - 1;
    float discriminant = pow(b, 2) - (4 * a * c);

    if (discriminant < 0) {
        return {};
    }

    float t1 = (b*-1 - sqrt(discriminant)) / (2*a);
    float t2 = (b*-1 + sqrt(discriminant)) / (2*a);

    return {intersection(t1, s), intersection(t2, s)};
}

vector<intersection> rayOps::hit(vector<intersection> intersections) {
    if (intersections.empty()) {
        return {};
    }
    intersection min = intersection(INT_MAX, sphere(-1));
    for (intersection i : intersections) {
        if (i.t >= 0 && i.t < min.t) {
            min = i;
        }
    }
    vector<intersection> output;
    if (min.t < INT_MAX) {
        output.push_back(min);
    }
    return output;
}

vec rayOps::reflect(vec in, vec normal) {
    float normalScalar = 2 * coordOps::dot(in, normal);
    vec newNormal = normal.scalarMultiply(normalScalar);
    return coordOps::coordToVec(coordOps::subtract(in, newNormal));
}

color rayOps::lighting(material material, pointLight light, point point, vec eyeVec, vec normalVec) {
    color effectiveColor = colorOps::multiply(material.surfaceColor, light.intensity);
    vec lightVec = vec(light.position.x - point.x,
                       light.position.y - point.y,
                       light.position.z - point.z).normalize();
    color ambientColor = effectiveColor.scalarMultiply(material.ambient);
    float lightDotNormal = coordOps::dot(lightVec, normalVec);

    color diffuseColor = color(0,0,0);
    color specularColor = color(0,0,0);

    if (lightDotNormal < 0) {
        diffuseColor = color(0,0,0);
        specularColor = color(0,0,0);
    } else {
        diffuseColor = effectiveColor.scalarMultiply(material.diffuse * lightDotNormal);
        vec reflectVec = reflect(lightVec.negate(), normalVec);
        float reflectDotEye = coordOps::dot(reflectVec, eyeVec);

        if (reflectDotEye <= 0) {
            specularColor = color(0,0,0);
        } else {
            float factor = pow(reflectDotEye, material.shininess);
            specularColor = (light.intensity).scalarMultiply(material.specular * factor);
        }
    }

    return colorOps::add(ambientColor, colorOps::add(diffuseColor, specularColor));
}
