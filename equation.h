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
    unsigned long argMax(unsigned long startRow, unsigned long column, Matrix matrix);
public:
    Equation(Matrix A, std::vector<long double> x);
    Matrix getA();
    std::vector<long double> getX();
    Matrix getB();
    long double det(Matrix matrix);
    void mulAX();
};

#endif // EQUATION_H
