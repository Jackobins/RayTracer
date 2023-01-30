//
// Created by Jack Wang on 12/29/2022.
//

#include "sphere.h"
#include "../../CoordFiles/matrixOps.h"
#include "../../CoordFiles/coordOps.h"

sphere::sphere() = default;

sphere::sphere(matrix m, material mat) {
    inverseTransform = m.inverse();
    surfaceMaterial = mat;
}

vec sphere::normalAt(point localPoint) {
    point objectPoint = coordOps::coordToPoint(
            matrixOps::multiply(inverseTransform, localPoint));
    vec objectNormal = coordOps::coordToVec(coordOps::subtract(objectPoint,
                                                               point(0,0,0)));
    matrix transposeInverse = inverseTransform.transpose();
    vec worldNormal = coordOps::coordToVec(
            matrixOps::multiply(transposeInverse, objectNormal));
    worldNormal.w = 0;
    return worldNormal.normalize();
}

vector<double> sphere::intersect(ray r) {
    vec shapeToRay = vec(r.origin.x - 0, r.origin.y - 0, r.origin.z - 0); // only for spheres !!!
    double a = coordOps::dot(r.direction, r.direction);
    double b = 2 * coordOps::dot(r.direction, shapeToRay);
    double c = coordOps::dot(shapeToRay, shapeToRay) - 1;
    double discriminant = pow(b, 2) - (4 * a * c);

    if (discriminant < 0) {
        return {};
    }

    double t1 = (b*-1 - sqrt(discriminant)) / (2*a);
    double t2 = (b*-1 + sqrt(discriminant)) / (2*a);
    return {t1, t2};
}
