//
// Created by Jack Wang on 12/29/2022.
//

#include "rayOps.h"
#include "../../CoordFiles/coordOps.h"
#include <cmath>
#include <iostream>

vector<intersection> rayOps::intersect(sphere s, ray r) {
    ray r2 = r.transform(s.transform.inverse());

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
