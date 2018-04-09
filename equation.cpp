#include "equation.h"

Equation::Equation(double x, double y, double c) {
    this->x = x;
    this->y = y;
    this->c = c;
}

double Equation::getX() {
    return x;
}

double Equation::getY() {
    return y;
}

double Equation::getC() {
    return c;
}
