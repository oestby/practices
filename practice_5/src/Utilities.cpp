#include <cstdlib>

#include "Utilities.hpp"

int randomWithLimits(int lower, int upper){
    int num = std::rand() % (upper-lower+1) + lower;
    return num;
}
