#ifndef EQUATION_H
#define EQUATION_H
#include "matrix.h"
#include <vector>
#include <math.h>

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
    unsigned long argMax(unsigned long startRow, unsigned long column, Matrix matrix);
};

#endif // EQUATION_H
