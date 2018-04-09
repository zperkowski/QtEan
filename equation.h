#ifndef EQUATION_H
#define EQUATION_H


class Equation
{
private:
    double x;
    double y;
    double c;
public:
    Equation(double x, double y, double c);
    double getX();
    double getY();
    double getC();
};

#endif // EQUATION_H
