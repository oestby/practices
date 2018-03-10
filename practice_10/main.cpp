#include <iostream>
#include "matrix.hpp"
#include "vector.hpp"

int main() {
    Matrix A(10, 10);
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            A.set( i+j, i, j);
        }
    }

    std::cout << "A: " << std::endl;
    std::cout << A << std::endl;

    Matrix B(10, 1);
    Vector b(B);
    Vector a(15);
    b.set(20, 3);
    std::cout << "B: " << std::endl;
    std::cout << B << std::endl;

    std::cout << "b: " << std::endl;
    std::cout << b << std::endl;

    Vector c(10);
    double dot_product = c.dot(b);
    std::cout << dot_product << std::endl;
    dot_product = c.dot(a);
    std::cout << dot_product << std::endl;

    return 0;
}
