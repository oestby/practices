#include "vector.hpp"

Vector::Vector(int nRows):
Matrix(nRows)
{
    //Empty
}

Vector::Vector(const Matrix& other):
Matrix(other.getWidth())
{
    if (other.getHeight() == 1 && other.getWidth()) {
        for (int i = 0; i < other.getHeight(); i++) {
            for (int j = 0; i < other.getWidth(); j++) {

            }
        }
    }
    else {
        
    }
}
