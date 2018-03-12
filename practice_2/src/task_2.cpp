#include <iostream>
#include <iomanip>

// 2a)
int inputIntegersUsingLoopAndPrintSum(){
    int temp, itterations, sum = 0;
    std::cout << "How many itterations do you want? ";
    std::cin >> itterations;
    for(int i = 1; i <= itterations; i++){
        std::cout << "Enter an integer: ";
        std::cin >> temp;
        sum += temp;
    }
    std::cout << "The sum of all your numbers is: " << sum << std::endl;
}

/* 2b)
If the loop runs until the user enters 0 a while loop is the best.
If you know how many itterations you want a for loop is better.

*/

// 2c)
double inputDouble(){
    std::cout << "Enter a double: ";
    double x;
    std::cin >> x;
    return x;
}

// 2d)
void nokToEur(){
    double x = -1;
    while(x < 0){
        x = inputDouble();
    }
    double eur = x / 9.64;
    std::cout << std::setprecision(2) << std::fixed << x << " NOK = " << eur << " EUR" << std::endl;;
}

/* 2e)
If we use the integer funciton the user will not be able to enter decimal numbers.
The reason for using double as a return type is because it has higher accuracy,
which is favorable when working with currency.
*/

/*
int main(int argc, char** argv){
    inputIntegersUsingLoopAndPrintSum();

    nokToEur();
}
*/
