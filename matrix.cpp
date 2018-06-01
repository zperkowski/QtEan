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

void Matrix::setCell(long x, long y, long double value) {
    mVector[y][x] = value;
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
                case 0: {
                    row.push_back(0.0);
                    break;
                }
                case 1:
                case 2: {
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
                case 3: {
                    unsigned long fraction = (i+1) + (j+1) - 1;
                    row.push_back((long double) 1 / fraction);
                    break;
                }
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

void Matrix::generateHilbert() {
    generate(3);
}

void Matrix::swap(long a, long b) {
    this->mVector[a].swap(mVector[b]);
}

unsigned long Matrix::argMax(unsigned long startRow, unsigned long column) {
    long double max = abs(this->getCell(column, startRow));
    unsigned long position = startRow;
    for(unsigned long i = startRow+1; i < this->getHeight(); i++)
        if(max < abs(this->getCell(column, i))) {
            max = abs(this->getCell(column, i));
            position = i;
        }
    return position;
}

Matrix Matrix::transpose() {
    Matrix t(this->getHeight(), this->getWidth());
    t.generateZeros();
    for (unsigned long y = 0; y < this->getHeight(); y++)
        for (unsigned long x = 0; x < this->getWidth(); x++)
            t.setCell(y, x, this->getCell(x, y));
    return t;
}

long double Matrix::det() {
    return this->det(*this);
}

long double Matrix::det(Matrix matrix) {
    unsigned long x = 0, y = 0, maxX;
    long double factor;
    while((x < matrix.getWidth()) && (y < matrix.getHeight())) {
        maxX = this->argMax(y, x);
        if(matrix.getCell(maxX, y) == 0.0f)
            y++;
        else {
            matrix.swap(y, maxX);
            for(unsigned long i = y+1; i < matrix.getHeight(); i++) {
                factor = matrix.getCell(x, i) / matrix.getCell(x, y);
                matrix.setCell(x, i, 0.0f);
                for(unsigned long j = x+1; j < matrix.getWidth(); j++)
                    matrix.setCell(j, i, matrix.getCell(j, i) - (matrix.getCell(j, y) * factor));
            }
            x++;
            y++;
        }
    }
    long double det = 1.0f;
    for(unsigned long i = 0; i < matrix.getHeight() || i < matrix.getWidth(); i++)
        det *= matrix.getCell(i, i);
    return det;
}

Matrix Matrix::adjugate() {
    Matrix adjugateMatrix(this->width, this->hight);
    adjugateMatrix.generateZeros();
    for(unsigned long y = 0; y < this->hight; y++)
        for(unsigned long x = 0; x < this->width; x++) {
            long detSub = this->getSubMatrix(x, y).det();
            if (y + x % 2 != 0)
                detSub *= -1;
            adjugateMatrix.setCell(x, y, detSub);
        }
    return adjugateMatrix;
}

// x and y are used to remove given row and column from this matrix
Matrix Matrix::getSubMatrix(unsigned long x_ignore, unsigned long y_ignore) {
    Matrix subMatrix(this->width-1, this->hight-1);
    subMatrix.generateZeros();
    unsigned long row_passed = 0;
    unsigned long column_passed = 0;

    for(unsigned long y = 0; y < this->hight; y++) {
        if (y == y_ignore) {
            row_passed = 1;
            continue;
        }
        for(unsigned long x = 0; x < this->width; x++) {
            if (x == x_ignore) {
                column_passed = 1;
                continue;
            }
            subMatrix.setCell(x - column_passed,
                              y - row_passed,
                              this->getCell(x, y));
        }
        column_passed = 0;
    }
    return subMatrix;
}
