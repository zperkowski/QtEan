#include <vector>
#include "matrix.h"

Matrix::Matrix(unsigned long h, unsigned long w)
{
    this->hight = h;
    this->width = w;
    for (unsigned long i = 0; i < getHeight(); i++) {
        std::vector<long double> row;
        mVector.push_back(row);
        std::vector<long double> last = mVector.back();
        for (unsigned long j = 0; j < getWidth(); j++) {
            last.push_back(0.0);
        }
    }
}

unsigned long Matrix::getWidth() {
    return this->width;
}

unsigned long Matrix::getHeight() {
    return this->hight;
}
