#include "matrix.hpp"

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
