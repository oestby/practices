#include <SafeArray.hpp>
#include <iostream>
#include <string>

int main(void) {
    SafeArray<int> array(10);
    for(size_t i = 0; i < 10; ++i) {
        array[i] = i * i;
    }

    std::cout << "Array 1:" << std::endl;
    for(int x: array) {
        std::cout << x << std::endl;
    }

    SafeArray<int> array2(array);
    array2.resize(5);
    
    std::cout << array2[7];
    std::cout << "Array 2:" << std::endl; 
    for(int x: array2) {
        std::cout << x << std::endl;
    }
    
    SafeArray<int> array3 = array2;
    array3.resize(10);
    std::cout << "Array 3:" << std::endl;
    for(int x: array3) {
        std::cout << x << std::endl;
    }
    
    SafeArray<std::string> string_array(10);
    for(size_t i = 0; i < 10; ++i) {
        string_array[i] = "The number: " + std::to_string(i);
    }
    
    std::cout << "String array:" << std::endl;
    for(std::string s: string_array) {
        std::cout << s << std::endl;
    }

    SafeArray<std::string> new_string_array(string_array);
    return 0;
}
