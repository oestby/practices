#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>

class Matrix
{
public:
    Matrix(): elements(nullptr) {};
    Matrix(uint nRows, uint nColumns);
    explicit Matrix(uint nRows);
    ~Matrix();

    double get(int row, int col) const;
    void set(int row, int col, double value);

    int getHeight(void) const;
    int getWidth(void) const;

    bool isValid(void) const
    {
        if (elements) return true;
        else return false;
    }
    
private:
    int rows, cols;
    double** elements;

};

std::ostream& operator<<(std::ostream &os, Matrix &m);

#endif

