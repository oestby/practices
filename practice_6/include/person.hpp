#ifndef PERSON_HPP
#define PERSON_HPP

#include <iostream>
#include <string>

#include "car.hpp"

class Person
{
public:
    Person(std::string name, std::string email, Car* car = nullptr);
    void setEmail(std::string new_email);
    std::string getEmail(void) const;
    std::string getName(void) const;
    bool hasAvailableSeats(void) const;
    bool operator<(const Person& rhs);
    bool operator==(const Person& rhs);

private:
    std::string name, email;
    Car *car_p;

};

std::ostream& operator<<(std::ostream& os, const Person& p);

#endif
