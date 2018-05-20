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

long double Equation::det(Matrix matrix) {
    // TODO: Fix and calculate the determinant
    unsigned long x = 0, y = 0, maxX;
    long double factor;
    while((x < matrix.getWidth()) && (y < matrix.getHeight())) {
        maxX = argMax(y, x, matrix);
        if(matrix.getCell(maxX, y) == 0.0f)
            y++;
        else {
            matrix.swap(y, maxX);
            for(unsigned long i = y+1; i < matrix.getHeight(); i++) {
                factor = matrix.getCell(i, y) / matrix.getCell(x, y);
                matrix.setCell(i, y, 0.0f);
                for(unsigned long j = y+1; j < matrix.getWidth(); j++)
                    matrix.setCell(i, j, matrix.getCell(i, j) - matrix.getCell(x, j) * factor);
            }
            x++;
            y++;
        }
    }
}
