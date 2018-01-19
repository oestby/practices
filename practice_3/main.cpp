#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>

#include "cannonball.hpp"
#include "utilities.hpp"

int main(int argc, char** argv){
    std::srand(std::time(nullptr));
    bool play = true;
    char choice = 'y';
    while(play){
        playTargetPractice();
        std::cout << "Play again? (y/n)";
        std::cin >> choice;
        switch(choice){
            case 'y':
                play = true;
                break;
            case 'n':
                play = false;
                break;
            default:
                std::cout << "Not a valid input, exiting." << std::endl;
                play = false;
                break;
        }
    }
    return 0;
}

