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
