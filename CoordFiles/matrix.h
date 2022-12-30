//
// Created by Jack Wang on 12/23/2022.
//

#ifndef RAYTRACER_MATRIX_H
#define RAYTRACER_MATRIX_H

#include <vector>
using namespace std;

class matrix {
public:
    vector<vector<float>> mat;

    matrix(size_t rows, size_t columns);
    matrix(size_t rows, size_t columns, float diagonalNum); // create an identity matrix
    size_t height();
    size_t width();
    void writeRow(int rowNum, vector<float> newRow);
    void writeColumn(int columnNum, vector<float> newColumn);
    matrix scalarMultiply(float scalar);
    matrix transpose();
    matrix subMatrix(int row, int column);
    float determinant();
    float minor(int row, int column);
    float cofactor(int row, int column);
    matrix inverse();
};

#endif //RAYTRACER_MATRIX_H
