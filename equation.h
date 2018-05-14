#ifndef EQUATION_H
#define EQUATION_H
#include "matrix.h"
#include <vector>

class Equation
{
private:
    Matrix A;
    std::vector<long double> x;
    Matrix B;
public:
    Equation(Matrix A, std::vector<long double> x);
    Matrix getA();
    std::vector<long double> getX();
    Matrix getB();
};

#endif // EQUATION_H
