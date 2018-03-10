#include "vector.hpp"

Vector::Vector(int nRows):
Matrix(nRows, 1)
{
    //Empty
}

Vector::Vector(const Matrix& other):
Matrix(other)
{
    if (!(other.getWidth() == 1 && other.getHeight())) {
        this->invalidate();
    }
}

double Vector::dot(const Vector& rhs) const {
    double sum = 0;
    if (rhs.getHeight() == getHeight()) {
        for (int i = 0; i < getHeight(); i++) {
            sum += get(i) * rhs.get(i);
        }
        return sum;
    }
    else {
        return nan("");
    }
}