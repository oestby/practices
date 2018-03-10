#include "matrix.hpp"

#include <algorithm>

Matrix::Matrix(uint nRows, uint nColumns):
rows(nRows), cols(nColumns)
{
    if (nRows && nColumns > 0)
    {
    	elements = new double*[nRows];
    	for (uint i = 0; i < nRows; i++)
    	{
        	elements[i] = new double[nColumns];
    	}
    }
    else
    {
        elements = nullptr;
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
    if (nRows > 0) {
        for (uint i = 0; i < nRows; i++)
        {
            elements[i][i] = 1;
        }
    }
}

Matrix::Matrix(const Matrix &m):
Matrix(m.getHeight(), m.getWidth())
{
    if (m.isValid())
    {
        for (int i = 0; i < m.getHeight(); i++)
        {
            for (int j = 0; j < m.getWidth(); j++)
            {
                elements[i][j] = m.get(i,j);
            }
        }
    }
}

Matrix&
Matrix::operator=(const Matrix& m)
{
    Matrix n_m(m);
    std::swap(elements, n_m.elements);
    this->rows = n_m.rows;
    this->cols = n_m.cols;
    return *this;
}


Matrix
Matrix::operator+=(Matrix m)
{
    if (this->isValid() &&
    m.isValid() &&
    this->getHeight() == m.getHeight() &&
    this->getWidth() == m.getWidth())
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
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
Matrix::operator-=(Matrix m)
{
    if (this->isValid() &&
    m.isValid() &&
    this->getHeight() == m.getHeight() &&
    this->getWidth() == m.getWidth())
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                this->elements[i][j] -= m.elements[i][j];
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
        for (int i = 0; i < m.getHeight(); i++)
        {
            for (int j = 0; j < m.getWidth(); j++)
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

Matrix
Matrix::operator-(Matrix m)
{   
    if(this->isValid() &&
    m.isValid() &&
    this->getHeight() == m.getHeight() &&
    this->getWidth() == m.getWidth())
    {
        for (int i = 0; i < m.getHeight(); i++)
        {
            for (int j = 0; j < m.getWidth(); j++)
            {
                m.elements[i][j] -= this->elements[i][j];
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
Matrix::get(int row, int col = 0) const
{
    return elements[row][col];
}

void
Matrix::set(double value, int row, int col = 0)
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
        for (int i = 0; i < this->getWidth(); i++)
        {
            for (int j = 0; j < this->getHeight(); j++)
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
            for (int j = 0; j < m.getWidth(); j++)
            {
                if (j != m.getWidth() - 1)
                {
                    os << m.get(i,j) << " ";
                }else
                {
                    os << m.get(i,j);
                }
            }
            os << std::endl;
        }
    }
    else
    {
        os << "Non-valid matrix.";
    }
    return os;
}
