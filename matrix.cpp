#include <vector>
#include <random>
#include <math.h>
#include "matrix.h"

Matrix::Matrix()
{
    this->hight = 0;
    this->width = 0;
}

Matrix::Matrix(unsigned long h, unsigned long w)
{
    this->hight = h;
    this->width = w;
    this->mVector.clear();
}

long double Matrix::getCell(long x, long y) {
    return mVector[y][x];
}

unsigned long Matrix::getWidth() {
    return this->width;
}

unsigned long Matrix::getHeight() {
    return this->hight;
}

void Matrix::generate(int choice) {
    mVector.clear();
    for (unsigned long i = 0; i < getHeight(); i++) {
        std::vector<long double> row;
        for (unsigned long j = 0; j < getWidth(); j++) {
            switch (choice) {
            case 0:
                row.push_back(0.0);
                break;
            case 1:
            case 2:
                std::default_random_engine generator(std::random_device{}());
                std::uniform_int_distribution<long double> distribution(1,1000);
                long double cell = distribution(generator);
                if (choice == 2) {
                    std::default_random_engine generatorExp(std::random_device{}());
                    std::uniform_int_distribution<long double> distributionExp(this->minExp, this->maxExp);
                    cell = pow(cell, distributionExp(generatorExp));
                }
                row.push_back(cell);
                break;
            }
        }
        mVector.push_back(row);
    }
}

void Matrix::generateZeros() {
    generate(0);
}

void Matrix::generateRandom() {
    generate(1);
}

void Matrix::generateRandom(long double minExp, long double maxExp) {
    this->minExp = minExp;
    this->maxExp = maxExp;
    generate(2);
}
