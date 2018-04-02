#include <iostream>
#include <vector>
#include <string>
#include <forward_list>
#include <list>
#include <Person.hpp>

void replace(std::vector<std::string>& vec, std::string old_str, std::string new_str) {
    for (auto it = vec.begin(); it != vec.end(); it++) {
        if (*it == old_str) {
            vec.erase(it);
            vec.insert(it, new_str);
        }
    }
}

void insertOrdered(std::forward_list<Person>& l, const Person& p) {
    auto temp = l.begin();
    for (auto it = l.begin(); it != l.end(); ++it) {
        if (*it > p) {
            if (temp == l.begin()) {
                l.push_front(p);
                return;
            }
            else { 
                l.insert_after(temp, p); 
                return;
            }
        }
        temp = it;
    }
    l.insert_after(temp, p);
}

void insertOrdered(std::list<Person>& l, const Person& p) {
    for (auto it = l.begin(); it != l.end(); ++it) {
        if (*it >= p) {
            l.insert(it, p);
            return;
        }
    }
    l.insert(l.end(), p);

}

