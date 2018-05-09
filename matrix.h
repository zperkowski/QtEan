#ifndef MATRIX_H
#define MATRIX_H


class Matrix
{
private:
    unsigned long width, hight;
    std::vector<std::vector<long double>> mVector;
public:
    Matrix(unsigned long w, unsigned long h);
    unsigned long getWidth();
    unsigned long getHeight();
};

#endif // MATRIX_H
