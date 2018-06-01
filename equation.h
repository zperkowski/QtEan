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
    std::vector<long double> x2;
    Matrix B;
public:
    Equation(Matrix A, std::vector<long double> x);
    Matrix getA();
    std::vector<long double> getX();
    std::vector<long double> getX2();
    Matrix getB();
    void mulAX();
    void mulAB();
};

#endif // EQUATION_H
