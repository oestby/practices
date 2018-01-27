#include <iostream>
#include <ctime>

#include "tests.hpp"
#include "mastermind.hpp"

int main(int argc, char** argv){
    std::srand(std::time(nullptr));
    bool go = true;
    int choice = 0;
    while(go)
    {
        std::cout << "Welcome! What would you like to test?" << std::endl
        << "1 - Test call by value function." << std::endl
        << "2 - Test call by pointer function." << std::endl
        << "3 - Test table sorting with insertionsort." << std::endl
        << "4 - Test C string stuff." << std::endl
        << "5 - Test average grade calculation." << std::endl
        << "6 - Play mastermind." << std::endl
        << "0 - Exit the program." << std::endl
        << "Enter your choice(0-6): ";
        std::cin >> choice;
        std::cout << std::endl;
        switch(choice)
        {
            case 1:
                testCallByValue();
                break;
            case 2:
                testCallByPointer();
                break;
            case 3:
                testTablesSorting();
                break;
            case 4:
                testCStrings();
                break;
            case 5:
                testCStringsFiveYears();
                break;
            case 6:
                playMastermind();
                break;
            case 0:
                go = false;
                break;
            default:
                std::cout << "That is not a valid option..." << std::endl;
                break;
        }
    }
    return 0;
}