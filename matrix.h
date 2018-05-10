#ifndef MATRIX_H
#define MATRIX_H
#include <vector>

class Matrix
{
private:
    unsigned long width, hight;
    std::vector<std::vector<long double>> mVector;
    void generate(int choice);
public:
    Matrix();
    Matrix(unsigned long w, unsigned long h);
    unsigned long getWidth();
    unsigned long getHeight();
    void generateZeros();
};

#endif // MATRIX_H
