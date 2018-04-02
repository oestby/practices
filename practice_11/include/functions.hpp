#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP
#include <iostream>
#include <vector>
#include <string>
#include <forward_list>
#include <list>
#include <Person.hpp>

template <class T>
void printContainer(T& con) {
    for (auto it = con.begin(); it != con.end(); ++it) {
        std::cout << *it << std::endl;
    }
}

void replace(std::vector<std::string>& vec, std::string old_str, std::string new_str);
void insertOrdered(std::forward_list<Person>& l, const Person& p);
void insertOrdered(std::list<Person>& l, const Person& p);
#endif 

