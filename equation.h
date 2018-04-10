#ifndef EQUATION_H
#define EQUATION_H


class Equation
{
private:
    double x;
    double y;
    double c;
public:
    Equation(long double x, long double y, long double c);
    long double getX();
    long double getY();
    long double getC();
};

#endif // EQUATION_H
