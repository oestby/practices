#include <iostream>

#include "fib.hpp"
#include "matrix.hpp"

int main(void)
{
    //createFibonacci();
    std::cout << "Creating A" << std::endl;
    Matrix a(10, 10);
    std::cout << a;

    std::cout << "Creating B" << std::endl;
    Matrix b(15);
    std::cout << b;

    std::cout << "Creating C - no initialization" << std::endl;
    Matrix c;
    std::cout << c << std::endl;

    std::cout << "Copying A into E" << std::endl;
    Matrix e(a);
    std::cout << e;
    
    std::cout << "Assigning A to C" << std::endl;
    //Assignment operator doesn't even work!
    c = a;
    std::cout << c << std::endl;

    a.~Matrix();
    std::cout << "A is destroyed" << std::endl;
    b.~Matrix();
    std::cout << "B is destroyed" << std::endl;
    c.~Matrix();
    std::cout << "C is destroyed" << std::endl;
    e.~Matrix();
    std::cout << "E is destroyed" << std::endl;

    std::cin.get();
    return 0;
}
