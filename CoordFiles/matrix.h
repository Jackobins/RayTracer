//
// Created by Jack Wang on 12/23/2022.
//

#ifndef RAYTRACER_MATRIX_H
#define RAYTRACER_MATRIX_H

#include <vector>
using namespace std;

class matrix {
public:
    vector<vector<double>> mat;

    matrix(size_t rows, size_t columns);
    matrix(size_t rows, size_t columns, double diagonalNum); // create an identity matrix
    size_t height();
    size_t width();
    void writeRow(int rowNum, vector<double> newRow);
    void writeColumn(int columnNum, vector<double> newColumn);
    matrix scalarMultiply(double scalar);
    matrix transpose();
    matrix subMatrix(int row, int column);
    double determinant();
    double minor(int row, int column);
    double cofactor(int row, int column);
    matrix inverse();
};

#endif //RAYTRACER_MATRIX_H
