#include <iostream>

#include "fib.hpp"
#include "matrix.hpp"

int main(void)
{
    //createFibonacci();
    Matrix a(10, 10);
    std::cout << a;
    Matrix b(15);
    std::cout << b;
    Matrix c;
    std::cout << c << std::endl;
    Matrix e(a);
    std::cout << e;
    //c = a;
    //std::cout << c;

    a.~Matrix();

    std::cin.get();
    return 0;
}
