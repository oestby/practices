#include <iostream>
#include <cmath>

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
    int array_len = 10;
    char grades[array_len];
    
    randomizeCString(grades, array_len, 65, 71);
    
    std::cout << grades << std::endl;
    
    readInputToCString(grades, array_len, 65, 71);
    
    std::cout << grades << std::endl;
    
    std::cout << "Amount of A's: " 
    << countOccurencesOfCharacter(grades, array_len, 'A')
    << std::endl;
    
    const int grade_length = 6;
    int gradeCount[] = {0,0,0,0,0,0};
    char letter[] = {'A', 'B', 'C', 'D', 'E', 'F'};
    
    for (int i = 0; i < 6; i++)
    {
        gradeCount[i] = countOccurencesOfCharacter(grades, array_len, letter[i]);
    }
    printArray(gradeCount, 6);
    
    float meanGrade = meanGrades(gradeCount, grade_length);
    std::cout << "Your mean grade is: " << meanGrade << std::endl;


}

void
testCStringsFiveYears()
{
    const int array_len = 8;
    char grades[5][array_len];
    for (int i = 0; i < 5; i++)
    {
        //randomizeCString(grades[i], array_len, 'A', 'F');
        readInputToCString(grades[i], array_len, 'A', 'F');
        std::cout << "Year " << (i+1) << ": " << grades[i] << std::endl;
    }

    int gradeCount[] = {0,0,0,0,0,0};
    for (int i = 0; i < 5; i++)
    {
        gradeCount[0] += countOccurencesOfCharacter(grades[i], array_len, 'A');
        gradeCount[1] += countOccurencesOfCharacter(grades[i], array_len, 'B');
        gradeCount[2] += countOccurencesOfCharacter(grades[i], array_len, 'C');
        gradeCount[3] += countOccurencesOfCharacter(grades[i], array_len, 'D');
        gradeCount[4] += countOccurencesOfCharacter(grades[i], array_len, 'E');
        gradeCount[5] += countOccurencesOfCharacter(grades[i], array_len, 'F');
    }
    
    std::cout << "Grade occurences:" << std::endl;
    printArray(gradeCount, 6);

    double gradeSum = 0;
    int totalAmountOfGrades = 0;
    for (int i = 0; i < 6; i++)
    {
        gradeSum += gradeCount[i] *(i+1);
        totalAmountOfGrades += gradeCount[i];
    }
    double meanGrade = gradeSum/totalAmountOfGrades;
    std::cout << "Mean grade for your five years: " << meanGrade << std::endl;
    std::cout << "That is about the same as a " << static_cast<char>('A'+round(meanGrade) -1) << std::endl;
}
