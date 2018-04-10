#include "equation.h"

Equation::Equation(long double x, long double y, long double c) {
    this->x = x;
    this->y = y;
    this->c = c;
}

long double Equation::getX() {
    return x;
}

long double Equation::getY() {
    return y;
}

long double Equation::getC() {
    return c;
}
