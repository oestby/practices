#include <iostream>
#include "include/task_2.hpp"
#include "include/task_1.hpp"
#include "include/task_4.hpp"

void multipleTable(){
    int size;
    std::cout << "What size of table do you want: ";
    std::cin >> size;
    for(int i = 1; i <= size; i++){
        for(int j = 1; j <= size; j++){
            std::cout << i * j << (i*j<10 ? "  ":" ");
        }
        std::cout << std::endl;
    }    
}

int main(int argc, char** argv){
    // 3a)
    int choice = -1;
    while(1){
    std::cout << "____________________" << std::endl
    << "Choose a function:" << std::endl
    << "0) Exit." << std::endl
    << "1) Sum two numbers." << std::endl
    << "2) Sum multiple numbers." << std::endl
    << "3) Convert NOK to EUR." << std::endl
    << "4) Print a table of multiplication." << std::endl
    << "5) Solve a quadratic equation." << std::endl;
    << "Enter your choice: ";
    std::cin >> choice;
    std::cout << std::endl;
    system("clear");
    switch(choice){
        case 0:
            break;
        case 1:
            inputIntegersAndPrintSum();
            break;
        case 2:
            inputIntegersUsingLoopAndPrintSum();
            break;
        case 3:
            nokToEur();
            break;
        case 4:
            multipleTable();
            break;
        case 5:
            solveQuadraticEquation();
            break;
        default:
            std::cout << "Not a valid option." << std::endl;
    }
    if(!choice){
        break;
    }
    }

}
