#include "utilities.hpp"
#include <cstdlib>

int
randomWithLimits(int lower, int upper)
{
    int num = std::rand() % (upper-lower+1) + lower;
    return num;
}

void
removeStoppedCannonballs(std::vector<Cannonball> v)
{
    auto it = v.begin();
    for (it; it != v.end();)
    {
        if (it->hasLanded())
        {
            it = v.erase(it);
        }
        else
        {
            it++;
        }
    }
}
