#include <SafeArray.hpp>
#include <iostream>

int main(void) {
    SafeArray<int> array(10);
    for(size_t i = 0; i < 10; ++i) {
        array[i] = 2 * i;
    }
    for(int x: array) {
        std::cout << x << std::endl;
    }
    array.resize(5);
    for(int x: array) {
        std::cout << x << std::endl;
    }
    array.resize(100);
    for(int x: array) {
        std::cout << x << std::endl;
    }
    
    SafeArray<int> array2(array);
    SafeArray<int> array3;
    array3 = array2;

    return 0;
}
