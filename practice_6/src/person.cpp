
#include "person.hpp"


Person::Person(std::string name, std::string email, Car *car):
name(name), email(email), car_p(car)
{
    // Empty
}

std::string
Person::getEmail(void) const
{
    return this->email;
}

std::string
Person::getName(void) const
{
    return this->name;
}

void
Person::setEmail(std::string new_email)
{
    this->email = new_email;
}

bool
Person::hasAvailableSeats(void) const
{
    return this->car_p->hasFreeSeats();
}

bool
Person::operator<(const Person& rhs)
{
    if (this->name < rhs.getName())
        return true;
    else
        return false;
}

bool
Person::operator==(const Person& rhs)
{
    if (this->name == rhs.getName()
    && this->email == rhs.getEmail())
        return true;
    else return false;
}

std::ostream& operator<<(std::ostream& os, const Person& p)
{
    os << p.getName();
    return os;
}
