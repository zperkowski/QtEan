#include <vector>
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
}

unsigned long Matrix::getWidth() {
    return this->width;
}

unsigned long Matrix::getHeight() {
    return this->hight;
}

void Matrix::generate(int choice) {
    for (unsigned long i = 0; i < getHeight(); i++) {
        std::vector<long double> row;
        mVector.push_back(row);
        std::vector<long double> last = mVector.back();
        for (unsigned long j = 0; j < getWidth(); j++) {
            switch (choice) {
            case 0:
                last.push_back(0.0);
                break;
            }
        }
    }
}

void Matrix::generateZeros() {
    generate(0);
}
