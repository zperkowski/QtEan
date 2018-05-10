#ifndef EQUATION_H
#define EQUATION_H
#include "matrix.h"


class Equation
{
private:
    Matrix A;
    long double x;
    Matrix B;
public:
    Equation(Matrix A, long double x);
    Matrix getA();
    long double getX();
    Matrix getB();
};

#endif // EQUATION_H
