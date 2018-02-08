#include <iostream>

#include "person.hpp"

int main(void)
{
    Person p("Oskar Østby", "oskar.oestby@gmail.com");
    std::cout << p << std::endl;

    return 0;
}