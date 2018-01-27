#include "utilities.hpp"
#include <cstdlib>

int randomWithLimits(int lower, int upper){
    int num = std::rand() % (upper-lower) + lower;
    return num;
}

