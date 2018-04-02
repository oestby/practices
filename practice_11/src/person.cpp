#include <Person.hpp>

Person::Person(std::string name, std::string sure_name):
    name(name), sure_name(sure_name)
{
    //empty
}

std::string Person::getName(void) const {
    return name;
}

std::string Person::getSureName(void) const {
    return sure_name;
}

bool Person::operator<(const Person& p) const {
    if (sure_name < p.getSureName()) {
        return true;
    }
    if (sure_name == p.getSureName()) {
        if (name < p.getName()) {
            return true;
        }
    }
    return false;
}

bool Person::operator>(const Person& p) const {
    return !(*this < p);
}

bool Person::operator==(const Person& p) const {
    if (name == p.getName() && sure_name == p.getSureName())
        return true;
    else
        return false;
}

bool Person::operator<=(const Person& p) const {
    if (*this < p || *this == p)
        return true;
    else
        return false;
}

bool Person::operator>=(const Person& p) const {
    if (*this > p || *this == p)
        return true;
    else
        return false;
}

std::ostream& operator<<(std::ostream& os, const Person& p) {
    os << p.getName() << " " << p.getSureName();
    return os;
}

