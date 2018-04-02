#ifndef PERSON_HPP
#define PERSON_HPP
#include <string>
#include <iostream>

class Person {
    public:
        Person(std::string name = "Jon", std::string sure_name = "Doe");
        std::string getName(void) const;
        std::string getSureName(void) const;
        bool operator<(const Person& p) const;
        bool operator>(const Person& p) const;
        bool operator==(const Person& p) const;
        bool operator<=(const Person& p) const;
        bool operator>=(const Person& p) const;

    private:
        std::string name, sure_name;
};

std::ostream& operator<<(std::ostream& os, const Person& p);

#endif

