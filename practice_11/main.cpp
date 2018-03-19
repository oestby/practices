#include <vector>
#include <string>
#include <iostream>
#include <set>
#include <SimpleSet.h>

void replace(std::vector<std::string>& vec, std::string old_str, std::string new_str) {
    for (auto it = vec.begin(); it != vec.end(); it++) {
        if (*it == old_str) {
            vec.erase(it);
            vec.insert(it, new_str);
        }
    }
}

template <class T>
void printContainer(T& con) {
    for (auto it = con.begin(); it != con.end(); it++) {
        std::cout << *it << std::endl;
    }
}


int main() {
    std::cout << "Reverse iterator: " << std::endl;
    std::vector<std::string> test = { "Lorem", "Ipsum", "Dolor", "Sit", "Amet", "Consectetur" };
    for (auto it = test.rbegin(); it != test.rend(); it++) {
        std::cout << *it << std::endl;
    }
    std::cout << std::endl;

    std::cout << "Replacing Lorem with Biach: " << std::endl;
    replace(test, "Lorem", "Biach");
    printContainer(test); 
    std::cout << std::endl;
    
    SimpleSet integers;
    std::cout << "Adds all integers from 0 to 100 to the set" << std::endl;
    for (int i = 0; i < 100; i++) {
        std::cout << "Is " << i << " added? " << integers.insert(i) << std::endl;
    }
    //printContainer(integers);

    std::cout << "Checks out if numbers are in the set" << std::endl;
    for (int i = 0; i < 150; i++) {
       std::cout << "Does " << i << " exist in the set? " << integers.exists(i) << std::endl;
    }
    
    // Does nothing, they are already contained in the set.
    std::cout << "Tries to readd the integers" << std::endl;
    for (int i = 0; i < 100; i++) {
        std::cout << "Re-add " << i << "? "
        << integers.insert(i) << std::endl;
    }
    printContainer(integers);
    
    //std::cout << "Removed 2? " << integers.erase(2) << std::endl;
    //printContainer(integers);
    //std::cout << "Tries to remove 2 again? " << integers.erase(2) << std::endl;
    //printContainer(integers);
    int i = 0
    while (i < 100) {
        if (integers.at(i)%2 && integers.at(i) != 2) {
            std::cout << "Is " << integers.at(i) << " removed? " << integers.erase(integers.at(i))<< std::endl;
            continue;
        }
        i++;
    }
    
    printContainer(integers);

    /*
    std::cout << "Removes all non prime numbers" << std::endl;
    for(int i = 2; i < 50; i++) {
        std::cout << "Removes all divisible by " << i << std::endl;
        for (auto it = integers.begin(); it != integers.end();) {
            if (!(*it%i) && *it != i) {
                std::cout << "Is " << i << " removed? " << integers.erase(i) << std::endl;
                continue;
            }
            it++;
        }
    }
    */
}
