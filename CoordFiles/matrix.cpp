//
// Created by Jack Wang on 12/23/2022.
//

#include "matrix.h"
#include <utility>
#include <iostream>
using namespace std;

matrix::matrix(size_t rows, size_t columns) {
    for (int i = 0; i < rows; i++) {
        vector<double> row;
        for (int j = 0; j < columns; j++) {
            row.push_back(0);
        }
        mat.push_back(row);
    }
}

matrix::matrix(size_t rows, size_t columns, double diagonalNum) {
    for (int i = 0; i < rows; i++) {
        vector<double> row;
        for (int j = 0; j < rows; j++) {
            row.push_back(0);
        }
        mat.push_back(row);
    }
    for (int i = 0; i < rows; i++) {
        mat[i][i] = diagonalNum;
    }
}

size_t matrix::height() {
    return mat.size();
}

size_t matrix::width() {
    return mat[0].size();
}


void matrix::writeRow(int rowNum, vector<double> newRow) {
    if (newRow.size() != mat[0].size()) {
        cout << "Row was not a compatible size" << endl;
        return;
    }
    mat[rowNum] = std::move(newRow);
}

void matrix::writeColumn(int columnNum, vector<double> newColumn) {
    if (newColumn.size() != mat.size()) {
        cout << "Column was not a compatible size" << endl;
        return;
    }
    for (int i = 0; i < newColumn.size(); i++) {
        mat[i][columnNum] = newColumn[i];
    }
}

matrix matrix::scalarMultiply(double scalar) {
    matrix m2 = matrix(mat[0].size(), mat.size());
    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat[0].size(); j++) {
            m2.mat[i][j] = mat[i][j] * scalar;
        }
    }
    return m2;
}

matrix matrix::transpose() {
    matrix m2 = matrix(mat[0].size(), mat.size());
    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat[0].size(); j++) {
            m2.mat[j][i] = mat[i][j];
        }
    }
    return m2;
}

matrix matrix::subMatrix(int row, int column) {
    matrix m2 = matrix(mat[0].size(), mat.size());
    m2.mat = mat;
    for (int i = 0; i < mat.size(); i++) {
        m2.mat[i].erase(m2.mat[i].begin() + column);
    }
    m2.mat.erase(m2.mat.begin() + row);
    return m2;
}

double matrix::determinant() {
    if (mat.size() == 2) {
        return mat[0][0]*mat[1][1] - mat[0][1]*mat[1][0];
    }
    double det = 0;
    for (int i = 0; i < mat.size(); i++) {
        det += mat[0][i] * cofactor(0, i);
    }
    return det;
}

double matrix::minor(int row, int column) {
    return subMatrix(row, column).determinant();
}

double matrix::cofactor(int row, int column) {
    if ((row + column)%2 == 0) {
        return minor(row, column);
    } else {
        return minor(row, column) * -1;
    }
}

matrix matrix::inverse() {
    double det = determinant();
    if (det == 0) {
        cout << "Determinant = 0, cannot compute inverse" << endl;
        return *this;
    }
    matrix m2 = matrix(mat[0].size(), mat.size());
    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat[0].size(); j++) {
            m2.mat[j][i] = (cofactor(i, j) / det);
        }
    }
    return m2;
}
