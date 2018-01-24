#include <iostream>
#include <cstdlib>

int 
incrementByValueNumTimes(int startValue, int increment, int numTimes){
    for (int i = 0; i < numTimes; i++){
        startValue += increment;
    }
    return startValue;
}

int
incrementByValueNumTimes2(int* startValue, int increment, int numTimes){
    for (int i = 0; i < numTimes; i++){
        *startValue += increment;
    }
    return *startValue;
}

//This function has to be pointer to actually do what it does.
void
swapNumbers(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void
printArray(const int array[], int lenOfArray){
    for (int i = 0; i < lenOfArray; i++){
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

int
randomWithLimits(int lower, int upper){
    int num = std::rand() % upper + lower;
    return num;
}

void
randomizeArray(int array[], int lenOfArray){
    for (int i = 0; i < lenOfArray; i++){
        array[i] = randomWithLimits(0, 100);
    }
}

void
sortArray(int array[], int len){
    int x, j;
    if (len>0){
        sortArray(array, len-1);
        x = array[len];
        j = len-1;
        while(j >= 0 && array[j] > x){
            swapNumbers(&array[j+1], &array[j]);
            j -= 1;
        }
        array[j+1] = x;
    }
}

double
medianOfArray(int array[], int len){
    if (len%2 == 0){
        return (array[len/2 - 1]+array[len/2])/2;
    }
    else{
        return array[(len-1)/2];
    }
}

void
randomWithLimits(char array[], int len, int lower, int upper){
    for (int i = 0; i < len-1; i++){
        array[i] = randomWithLimits(lower, upper);
    }
}

void
readInputToCString(){
    
}
