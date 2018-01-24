#include <iostream>

#include "utilities.hpp"

void
testCallByValue(){
    int v0 = 5, increment = 2, iterations = 10;
    int result = incrementByValueNumTimes(v0, increment, iterations);
    std::cout << "v0: " << v0
              << " increment: " << increment
              << " iterations: " << iterations
              << " result: " << result << std::endl;
}

void 
testCallByPointer(){
    int v0 = 5, increment = 2, iterations = 10;
    int result = incrementByValueNumTimes2(&v0, increment, iterations);
    std::cout << "v0: " << v0
              << " increment: " << increment
              << " iterations: " << iterations
              << " result: " << result << std::endl;
}

void 
testTablesSorting(){
    const int array_len = 25;
    int percentages[array_len];
    randomizeArray(percentages, array_len);
    printArray(percentages, array_len);
    swapNumbers(&percentages[0], &percentages[1]);
    printArray(percentages, array_len);
    sortArray(percentages, array_len);
    printArray(percentages, array_len);
    //Of course you'll get different answers...
    std::cout << "Median of array = " << medianOfArray(percentages, array_len)
    << std::endl;
}

void
testCStrings(){
    int array_len = 8;
    char grades[array_len];
    randomizeCString(grades, array_len, 0x41, 0x47);
    std::cout << grades << std::endl;
}

