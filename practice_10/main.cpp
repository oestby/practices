#include <iostream>
#include "matrix.hpp"
#include "vector.hpp"

void testVectors(){
        //Creates matrix A and fills it.
    Matrix A(10, 3);
    A.fill(10);
    std::cout << A << std::endl;
    /*
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            A.set( i+j, i, j);
        }
    }
    */

    std::cout << "A: " << std::endl;
    std::cout << A << std::endl;

    //Testing printing of matrix and vectors
    Matrix B(10, 1);
    Vector a(15);
    std::cout << "B: " << std::endl;
    std::cout << B << std::endl;

    std::cout << "a: " << std::endl;
    std::cout << a << std::endl;
    
    //Copy ctor
    Vector b(B);
    b.set(20, 3);
    std::cout << "b: " << std::endl;
    std::cout << b << std::endl;

    //Creates vector d;
    Vector d(3);
    std::cout << "d: " << std::endl;
    std::cout << d << std::endl;

    double dot_product = d.dot(b);
    std::cout << "d * b = " << dot_product << std::endl;
    dot_product = d.dot(a);
    std::cout << "d * a = " << dot_product << std::endl;

    d.fill(5);
    std::cout << "d: " << std::endl;
    std::cout << d << std::endl;
    Matrix product = A * d;

    std::cout << "A.d = " << std::endl;
    std::cout << product << std::endl;
}

int main() {



    return 0;
}
