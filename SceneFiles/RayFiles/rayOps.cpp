//
// Created by Jack Wang on 12/29/2022.
//

#include "rayOps.h"
#include "../../CoordFiles/coordOps.h"
#include "../../CanvasFiles/colorOps.h"
#include "../patternFiles/patternOps.h"
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

vector<intersection> rayOps::intersect(shape* s, ray r) {
    ray r2 = r.transform(s->inverseTransform);

    vector<double> intersectionTValues = s->intersect(r2);
    vector<intersection> output;

    for (double tValue : intersectionTValues) {
        output.emplace_back(tValue, s);
    }

    return output;
}

vector<intersection> rayOps::hit(vector<intersection> intersections) {
    if (intersections.empty()) {
        return {};
    }
    sphere* dummy = new sphere();
    intersection min = intersection(INT_MAX, dummy);
    for (intersection i : intersections) {
        if (i.t >= 0 && i.t < min.t) {
            min = i;
        }
    }
    vector<intersection> output;
    if (min.t < INT_MAX) {
        output.push_back(min);
    }
    delete dummy;
    return output;
}

vec rayOps::reflect(vec in, vec normal) {
    double normalScalar = 2 * coordOps::dot(in, normal);
    vec newNormal = normal.scalarMultiply(normalScalar);
    return coordOps::coordToVec(coordOps::subtract(in, newNormal));
}

color rayOps::lighting(material material, shape* object, pointLight light,
                       point point, vec eyeVec, vec normalVec, bool inShadow) {
    color trueColor = material.surfaceColor;
    if (material.pattern != nullptr) {
        trueColor = patternOps::patternAtObject(object, material.pattern, point);
    }

    color effectiveColor = colorOps::multiply(trueColor, light.intensity);
    vec lightVec = vec(light.position.x - point.x,
                       light.position.y - point.y,
                       light.position.z - point.z).normalize();
    color ambientColor = effectiveColor.scalarMultiply(material.ambient);

    if (inShadow) {
        return ambientColor;
    }

    double lightDotNormal = coordOps::dot(lightVec, normalVec);

    color diffuseColor = color(0,0,0);
    color specularColor = color(0,0,0);

    if (lightDotNormal < 0) {
        diffuseColor = color(0,0,0);
        specularColor = color(0,0,0);
    } else {
        diffuseColor = effectiveColor.scalarMultiply(material.diffuse * lightDotNormal);
        vec reflectVec = reflect(lightVec.negate(), normalVec);
        double reflectDotEye = coordOps::dot(reflectVec, eyeVec);

        if (reflectDotEye <= 0) {
            specularColor = color(0,0,0);
        } else {
            double factor = pow(reflectDotEye, material.shininess);
            specularColor = (light.intensity).scalarMultiply(material.specular * factor);
        }
    }

    return colorOps::add(ambientColor, colorOps::add(diffuseColor, specularColor));
}

vector<intersection> rayOps::intersectWorld(world* w, ray r) {
    vector<intersection> output = {};

    for (int i = 0; i < w->shapes.size(); i++) {
        vector<intersection> xs = intersect(w->shapes[i], r);
        for (intersection intersection : xs) {
            output.push_back(intersection);
        }
    }
    sort(output.begin(), output.end(),
         [](const intersection& a, const intersection& b) {
        return a.t < b.t;
    });
    return output;
}
