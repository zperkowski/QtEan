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
public:
    Matrix();
    Matrix(unsigned long w, unsigned long h);
    long double getCell(long x, long y);
    unsigned long getWidth();
    unsigned long getHeight();
    void generateZeros();
    void generateRandom();
    void generateRandom(long double minExp, long double maxExp);
    void generateHilbert();
};

#endif // MATRIX_H
