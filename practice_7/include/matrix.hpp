#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>

class Matrix
{
public:
    Matrix():  rows(0), cols(0), elements(nullptr) {};
    Matrix(uint nRows, uint nColumns);
    explicit Matrix(uint nRows);
    Matrix(const Matrix &m);
    ~Matrix();

    Matrix& operator=(const Matrix& m);
    Matrix operator+=(Matrix m);
    Matrix operator+(Matrix m);

    double get(int row, int col) const;
    void set(int row, int col, double value);

    int getHeight(void) const;
    int getWidth(void) const;

    void fill(double num = 0);

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

