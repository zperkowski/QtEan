#include "equation.h"
#include "matrix.h"
#include <math.h>

Equation::Equation(Matrix A, std::vector<long double> x) {
    this->A = A;
    this->x = x;
    this->B = Matrix(A.getHeight(), A.getWidth());
    this->B.generateZeros();
}

Matrix Equation::getA() {
    return A;
}

std::vector<long double> Equation::getX() {
    return x;
}

Matrix Equation::getB() {
    return B;
}

unsigned long Equation::argMax(unsigned long startRow, unsigned long column, Matrix matrix) {
    long double max = abs(matrix.getCell(startRow, column));
    unsigned long position = startRow;
    for(unsigned long i = startRow+1; i < matrix.getHeight(); i++)
        if(max < abs(matrix.getCell(i, column))) {
            max = abs(matrix.getCell(i, column));
            position = i;
        }
    return position;
}
