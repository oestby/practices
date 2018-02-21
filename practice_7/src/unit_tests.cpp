#include "matrix.hpp"

bool
matrixClassTest(uint loops)
{
    //Constructors
    Matrix a;
    Matrix b(10, 10);
    Matrix c(10);
    Matrix d(a);
    Matrix e(b);

    std::cout << "CONSTRUCTOR TESTS - Completed" << std::endl;

    //Destructor
    d.~Matrix();
    e.~Matrix();

    std::cout << "DESTRUCTOR TESTS - Completed" << std::endl;

    //Mutators and accessors

    //Operators


    //Memory leak
    for (uint i = 0; i < loops; i++)
    {
        Matrix loop_test(1000, 1000);
        loop_test.~Matrix();
    }
    std::cout << "MEMORY TEST - Completed" << std::endl;
}