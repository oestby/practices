#include "matrix.hpp"

#include <algorithm>

Matrix::Matrix(uint nRows, uint nColumns):
rows(nRows), cols(nColumns)
{
    elements = new double*[nRows];
    for (uint i = 0; i < nRows; i++)
    {
        elements[i] = new double[nColumns];
    }
}

Matrix::~Matrix()
{
    if (elements)
    {
        for (int i = 0; i < rows; i++)
        {
            delete[] elements[i];
            elements[i] = nullptr;
        }
        delete[] elements;
        elements = nullptr;
    }   
}

Matrix::Matrix(uint nRows):
Matrix(nRows, nRows)
{
    for (uint i = 0; i < nRows; i++)
    {
        elements[i][i] = 1;
    }

}

Matrix::Matrix(const Matrix &m):
rows(0), cols(0)
{
    if (m.isValid())
    {
        rows = m.getHeight();
        cols = m.getWidth();
        elements = m.elements;
    }
    else
    {
        elements = nullptr;
    }
}

Matrix
Matrix::operator=(Matrix m)
{
    std::swap(elements, m.elements);
    this->rows = m.rows;
    this->cols = m.cols;
    return *this;
}

// Matrix c
// c += a
Matrix
Matrix::operator+=(Matrix m)
{
    if (this->isValid() &&
    m.isValid() &&
    this->getHeight() == m.getHeight() &&
    this->getWidth() == m.getWidth())
    {
        for (uint i = 0; i < rows; i++)
        {
            for (uint j = 0; j < cols; j++)
            {
                this->elements[i][j] += m.elements[i][j];
            }
        }
    }
    else
    {
        Matrix s;
        std::swap(elements, s.elements);
        this->rows = s.rows;
        this->cols = s.cols;
    }
    return *this;

}

Matrix
Matrix::operator+(Matrix m)
{   
    if(this->isValid() &&
    m.isValid() &&
    this->getHeight() == m.getHeight() &&
    this->getWidth() == m.getWidth())
    {
        for (uint i = 0; i < m.getHeight(); i++)
        {
            for (uint j = 0; j < m.getWidth(); j++)
            {
                m.elements[i][j] += this->elements[i][j];
            }
        }
        return m;
    }
    else
    {
        Matrix s;
        return s;
    }
   
}


double
Matrix::get(int row, int col) const
{
    return elements[row][col];
}

void
Matrix::set(int row, int col, double value)
{
    elements[row][col] = value;
}

int 
Matrix::getHeight(void) const
{
    return rows;
}

int
Matrix::getWidth(void) const
{
    return cols;
}

void
Matrix::fill(double num)
{
    if (this->isValid())
    {
        for (uint i = 0; i < this->getWidth(); i++)
        {
            for (uint j = 0; j < this->getHeight(); i++)
            {
                elements[i][j] = num;
            }
        }
    }
}

std::ostream&
operator<<(std::ostream& os, Matrix &m)
{
    if (m.isValid())
    {
        for (int i = 0; i < m.getHeight(); i++)
        {
            os << "[";
            for (int j = 0; j < m.getWidth(); j++)
            {
                if (j != m.getWidth() - 1)
                {
                    os << m.get(i,j) << ", ";
                }else
                {
                    os << m.get(i,j);
                }
            }
            os << "]" << std::endl;
        }
    }
    else
    {
        os << "Non-valid matrix.";
    }
    return os;
}
