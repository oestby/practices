#include <iostream>

#include "car.hpp"

Car::Car(unsigned int number_of_free_seats):
free_seats(number_of_free_seats)
{
    // Empty
}

bool
Car::hasFreeSeats() const
{
    if (this->free_seats > 0)
        return true;
    else 
        return false;
}

void
Car::reserveFreeSeat()
{
    if (this->hasFreeSeats())
    {
        free_seats--;
    }
    else
    {
        std::cout << "There is no free seats." << std::endl;
    }
}

