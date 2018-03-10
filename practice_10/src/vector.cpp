#include "vector.hpp"

Vector::Vector(int nRows):
Matrix(nRows, 1)
{
    //Empty
}

Vector::Vector(const Matrix& other):
Matrix(other.getHeight(), 1)
{
    if (other.getWidth() == 1 && other.getHeight()) {
        for (int i = 0; i < other.getHeight(); i++) {
            this->set(i, other.get(i));
        }
    }
    else
    {
        this->invalidate();
    }
}
