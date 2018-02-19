#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>

class Matrix
{
public:
    Matrix(): elements(nullptr) {};
    Matrix(int nRows, int nColumns);
    explicit Matrix(int nRows);
    ~Matrix();

    double get(int row, int col) const;
    void set(int row, int col, double value);

    int getHeight(void) const;
    int getWidht(void) const;

    bool isValid(void) const
    {
        if (elements) return true;
        else return false;
    }
    
    std::ostream operator<<(std::ostream os);

private:
    int cols, rows;
    double** elements;

};

#endif

