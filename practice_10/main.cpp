#include <iostream>
#include "matrix.hpp"
#include "vector.hpp"

int main() {
    Matrix A(10, 10);
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            A.set(i,j, i+j);
        }
    }

    std::cout << "A: " << std::endl;
    std::cout << A << std::endl;

    return 0;
}
