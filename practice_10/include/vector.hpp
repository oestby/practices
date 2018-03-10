#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "matrix.hpp"
#include <cmath>

class Vector: public Matrix {
    public:
        explicit Vector(int nRows);
        Vector(const Matrix& other);
        
        void set(int row, double value);
        double get(int row);
        
        double dot(const Vector& rhs) const;
        double lengtSquared() const;
        double length() const;

    private:


};

#endif

