#ifndef MATRIX_H
#define MATRIX_H
#include <vector>

class Matrix
{
private:
    unsigned long width, hight;
    std::vector<std::vector<long double>> mVector;
    void generate(int choice);
    long double minExp;
    long double maxExp;
    unsigned long argMax(unsigned long startRow, unsigned long column);
    long double det(Matrix matrix);
    Matrix getSubMatrix(unsigned long x, unsigned long y);
public:
    Matrix();
    Matrix(unsigned long w, unsigned long h);
    long double getCell(long x, long y);
    void setCell(long x, long y, long double value);
    unsigned long getWidth();
    unsigned long getHeight();
    void generateZeros();
    void generateRandom();
    void generateRandom(long double minExp, long double maxExp);
    void generateHilbert();
    void swap(long a, long b);
    Matrix transpose();
    long double det();
    Matrix adjugate();
};

#endif // MATRIX_H
