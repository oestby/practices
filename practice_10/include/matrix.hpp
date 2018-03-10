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
    Matrix operator-=(Matrix m);
    Matrix operator+(Matrix m);
    Matrix operator-(Matrix m);

    double get(int row, int col = 0) const;
    void set(double value, int row, int col = 0);

    // Height is rows and width is columns.
    int getHeight(void) const;
    int getWidth(void) const;

    void fill(double num = 0);

    bool isValid(void) const { return static_cast<bool>(elements); }
    
private:
    int rows, cols;
    double** elements;

};

std::ostream& operator<<(std::ostream &os, Matrix &m);

#endif

