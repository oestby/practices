#ifndef UTILITIES_HPP
#define UTILITIES_HPP

int incrementByValueNumTimes(int startValue, int increment, int numTimes);
int incrementByValueNumTimes2(int* startValue, int increment, int numTimes);
void swapNumbers(int* a, int* b);
void printArray(const int array[], int lenOfArray);
void randomizeArray(int array[], int lenOfArray);
int randomWithLimits(int lower, int upper);
void sortArray(int array[], int len);
double medianOfArray(int array[], int len);
void randomizeCString(char array[], int len, int lower, int upper);
void readInputToCString(char array[], int lower, int upper);

#endif
