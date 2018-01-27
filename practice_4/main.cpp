#include <iostream>
#include <ctime>

#include "tests.hpp"

int main(int argc, char** argv){
    std::srand(std::time(nullptr));
    //testCallByValue();
    //testCallByPointer();
    //testTablesSorting();
    //testCStrings();
    testCStringsFiveYears();
    return 0;
}