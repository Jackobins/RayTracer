//
// Created by Jack Wang on 12/29/2022.
//

#include "sphere.h"

sphere::sphere(int i) : transform(matrix(4, 4, 1)) {
    id = i;
    transform = matrix(4, 4, 1);
}

sphere::sphere(int i, matrix m) : transform(m) {
    id = i;
    transform = m;
}
