#ifndef UTILS_HPP
#define UTILS_HPP

#include <cstdlib>

int
randomInt(int lower, int upper)
{
    int num = std::rand() % (upper-lower+1) + lower;
    return num;
}

#endif
