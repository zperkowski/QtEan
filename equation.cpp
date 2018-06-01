#include "equation.h"
#include "matrix.h"
#include <math.h>

Equation::Equation(Matrix A, std::vector<long double> x) {
    this->A = A;
    this->x = x;
    this->B = Matrix(1, A.getHeight());
    this->B.generateZeros();
}

Matrix Equation::getA() {
    return A;
}

std::vector<long double> Equation::getX() {
    return x;
}

std::vector<long double> Equation::getX2() {
    return x2;
}

Matrix Equation::getB() {
    return B;
}

void Equation::mulAX() {
    long double sum = 0.0f;
    for (unsigned long yPos = 0; yPos < A.getHeight(); yPos++) {
        for (unsigned long xPos = 0; xPos < A.getWidth(); xPos++)
            sum += A.getCell(yPos, xPos) * x[xPos];
        B.setCell(yPos, 0, sum);
        sum = 0.0f;
    }
}

void Equation::mulAB() {
    // TODO: Generate and use here complements matrix
    Matrix tMatrixA = A.transpose();
    long double sum = 0.0f;
    for (unsigned long yPos = 0; yPos < tMatrixA.getHeight(); yPos++) {
        for (unsigned long xPos = 0; xPos < tMatrixA.getWidth(); xPos++)
            sum += tMatrixA.getCell(yPos, xPos) * B.getCell(xPos, 0);
        x2.push_back(sum);
        sum = 0.0f;
    }
}
