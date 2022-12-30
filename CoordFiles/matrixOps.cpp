//
// Created by Jack Wang on 12/23/2022.
//

#include "matrixOps.h"
#include "point.h"
#include "vec.h"
#include "coordOps.h"
#include <iostream>

bool matrixOps::areEqual(matrix m1, matrix m2) {
    if (m1.height() != m2.height() || m1.width() != m2.width()) {
        return false;
    }
    for (int i = 0; i < m1.height(); i++) {
        for (int j = 0; j < m1.width(); j++) {
            if (abs(m1.mat[i][j]-m2.mat[i][j]) > EPSILON) {
                return false;
            }
        }
    }
    return true;
}

matrix matrixOps::multiply(matrix m1, matrix m2) {
    matrix m = matrix(m1.height(), m2.width());
    for (int i = 0; i < m.height(); i++) {
        for (int j = 0; j < m.width(); j++) {
            float entry = 0;
            for (int x = 0; x < m1.width(); x++) {
                entry += (m1.mat[i][x] * m2.mat[x][j]);
            }
            m.mat[i][j] = entry;
        }
    }
    return m;
}

coord matrixOps::multiply(matrix m, coord c) {
    vec vec1 = vec(m.mat[0][0], m.mat[1][0], m.mat[2][0], m.mat[3][0]);
    vec vec2 = vec(m.mat[0][1], m.mat[1][1], m.mat[2][1], m.mat[3][1]);
    vec vec3 = vec(m.mat[0][2], m.mat[1][2], m.mat[2][2], m.mat[3][2]);
    vec vec4 = vec(m.mat[0][3], m.mat[1][3], m.mat[2][3], m.mat[3][3]);

    coord output = coordOps::add(vec3.scalarMultiply(c.z), vec4.scalarMultiply(c.w));
    output = coordOps::add(output, vec2.scalarMultiply(c.y));
    output = coordOps::add(output, vec1.scalarMultiply(c.x));
    return output;
}

matrix matrixOps::translationMatrix(float x, float y, float z) {
    matrix m = matrix(4, 4, 1);
    m.writeColumn(3, {x, y, z, 1});
    return m;
}

matrix matrixOps::scalingMatrix(float x, float y, float z) {
    matrix m = matrix(4, 4, 1);
    m.mat[0][0] = x;
    m.mat[1][1] = y;
    m.mat[2][2] = z;
    return m;
}

matrix matrixOps::rotationMatrix(int axis, float radians) {
    matrix m = matrix(4, 4, 1);
    if (axis == 0) { // rotate around x-axis
        m.writeColumn(1, {0, cos(radians), sin(radians), 0});
        m.writeColumn(2, {0, sin(radians) * -1, cos(radians), 0});
    } else if (axis == 1) { // rotate around y-axis
        m.writeColumn(0, {cos(radians), 0, sin(radians) * -1, 0});
        m.writeColumn(2, {sin(radians), 0, cos(radians), 0});
    } else if (axis == 2) { // rotate around z-axis
        m.writeColumn(0, {cos(radians), sin(radians), 0, 0});
        m.writeColumn(1, {sin(radians) * -1, cos(radians), 0, 0});
    } else { // error
        cout << "Did not choose a valid axis to rotate" << endl;
    }
    return m;
}

matrix matrixOps::shearMatrix(float xWithY, float xWithZ,
                              float yWithX, float yWithZ,
                              float zWithX, float zWithY) {
    matrix m = matrix(4, 4, 1);
    m.writeRow(0, {1, xWithY, xWithZ, 0});
    m.writeRow(1, {yWithX, 1, yWithZ, 0});
    m.writeRow(2, {zWithX, zWithY, 1, 0});
    return m;
}
