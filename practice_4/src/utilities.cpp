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
    int num = std::rand() % (upper-lower+1) + lower;
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
randomizeCString(char array[], int len, int lower, int upper){
    int temp;
    for (int i = 0; i < len; i++){
        temp = randomWithLimits(lower, upper);
        array[i] = temp;
    }
    array[len] = '\0';
}

void
readInputToCString(char array[], int len, int lower, int upper){
    int fill = 0;
    char l = lower, u = upper, temp;
    std::cout << "Enter characters between " << l << " and " << u << ":" << std::endl;
    while (fill <= len-1){
        std::cout << "Enter a single character: ";
        std::cin >> temp;
        temp = toupper(temp);
        if (static_cast<int>(l) <= static_cast<int>(temp)
         && static_cast<int>(temp) <= static_cast<int>(u)){
            array[fill] = temp;
            fill++;            
        }else
        {
            std::cout << "That is not a valid character." << std::endl;
        }
    }
    array[len] = '\0';
}

int 
countOccurencesOfCharacter(char array[], int length, char chr){
    chr = toupper(chr);
    int count = 0;
    for (int i = 0; i<length; i++){
        if (array[i] == chr){
            count++;
        }
    }
    return count;
}

int
meanGrades(int array[], int length)
{
    double meanGrade = 0;
    for (int i = 0; i < length; i++)
    {
        meanGrade += array[i]*(i+1);
    }
    meanGrade /= length;
    return meanGrade;
}
