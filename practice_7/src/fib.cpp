#include "fib.hpp"
#include <iostream>

void
fillInFibonacciNumbers(int result[], int length)
{
    int last = 0, current = 1, temp = 0;
    for (int i = 0; i < length; i++)
    {
        result[i] = current;
        temp = current;
        current += last;
        last = temp;
    }
}

void
printArray(int arr[], int length)
{
    for (int i = 0; i < length; i++)
    {
        std::cout << arr[i] << std::endl;
    }
}

void
createFibonacci()
{
    int length;
    std::cout << "How many Fibonacci numbers would you like?" << std::endl;
    std::cin >> length;

    int* array = new int [length];
    fillInFibonacciNumbers(array, length);
    printArray(array, length);

    delete[] array;
}
