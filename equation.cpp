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
    long double max = abs(matrix.getCell(column, startRow));
    unsigned long position = startRow;
    for(unsigned long i = startRow+1; i < matrix.getHeight(); i++)
        if(max < abs(matrix.getCell(column, i))) {
            max = abs(matrix.getCell(column, i));
            position = i;
        }
    return position;
}

long double Equation::det(Matrix matrix) {
    //TODO: Find why calculations give nan values
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
                    matrix.setCell(j, i, matrix.getCell(i, j) - (matrix.getCell(x, j) * factor));
            }
            x++;
            y++;
        }
    }
    long double det = 1.0f;
    for(unsigned long i = 0; i < matrix.getHeight() || i < matrix.getWidth(); i++)
        det *= matrix.getCell(i, i);
    return det;
}
