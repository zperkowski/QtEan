#include "equation.h"
#include "matrix.h"

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
