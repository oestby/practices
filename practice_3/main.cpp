#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>

#include "cannonball.hpp"
#include "utilities.hpp"

int main(int argc, char** argv){
    std::srand(std::time(nullptr));

    //Checking if we get correct results
    double result = posX(0, 50.0, 5.0);
    double expected = 250.0;
    double error = std::pow(expected-result, 2);
    double margin = 0.0001;
    if(error < margin){
        std::cout << "You did good, comrade" << std::endl;
    }
    else{
        std::cout << "Back to training!" << std::endl;
    }
    
    std::cout << "Random number: " << randomWithLimits(0, 13) << std::endl;

    return 0;
}

