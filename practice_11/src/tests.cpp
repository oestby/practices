#include <Person.hpp>
#include <LinkedList.h>
#include <SimpleSet.h>
#include <functions.hpp>

#include <iostream>
#include <utility>
#include <string>
#include <set>
#include <forward_list>
#include <list>
#include <vector>

void testStdSet() {
    std::cout << "Reverse iterator: " << std::endl;
    std::vector<std::string> test = {"Lorem", "Ipsum", "Dolor",
                                    "Sit", "Amet", "Consectetur"};
    for (auto it = test.rbegin(); it != test.rend(); it++) {
        std::cout << *it << std::endl;
    }
    std::cout << std::endl;

    std::cout << "Replacing Lorem with Bach: " << std::endl;
    replace(test, "Lorem", "Bach");
    printContainer(test);
    std::cout << std::endl;
    
    std::set<int> integers;
    std::cout << "Adds all integers from 0 to 100 to the set" << std::endl;
    for (int i = 0; i < 100; i++) {
        std::cout << "Is " << i << " added?" 
            << (integers.insert(i).second ? "yes":"no") << std::endl;
    }

    std::cout << "Checks out if numbers are in the set" << std::endl;
    for (int i = 0; i < 150; i++) {
        std::cout << "Does " << i << " exist in the set? "
            << (integers.count(i) ? "yes" : "no") << std::endl;
    }

    std::cout << "Tries to readd the integers" << std::endl;
    for (int i = 0; i < 100; i++) {
        std::cout << "Re-add " << i << "? "
            << (integers.insert(i).second ? "yes":"no") << std::endl;
    }
    printContainer(integers);

    for (auto it = integers.begin(); it != integers.end(); ++it) {
        if (!(*it % 2) && *it != 2) {
            std::cout << "Is " << *it << " removed? "
                << (integers.erase(*it) ? "yes":"no") << std::endl;
            continue;
        }
    }

    printContainer(integers);

    std::cout << "Removes all non primes: " << std::endl;
    for (int i = 2; i < 50; i++) {
        std::cout << "Removes all numbers divisable by " << i << std::endl;
        for (auto it = integers.begin(); it != integers.end(); ++it) {
            if (!(*it%2) && *it != i) {
                std::cout << "Is " << i << " removed? "
                    << (integers.erase(*it) ? "yes":"no") << std::endl;
            }
        }
    }
    
    printContainer(integers);

}

void testSimpleSet() {
    
    SimpleSet integers;
    std::cout << "Adds all integers from 0 to 100 to the set" << std::endl;
    for (int i = 0; i < 100; i++) {
        std::cout << "Is " << i << " added?" << integers.insert(i) << std::endl;
    }

    std::cout << "Checks out if numbers are in the set" << std::endl;
    for (int i = 0; i < 150; i++) {
        std::cout << "Does " << i << " exist in the set? "
            << (integers.exists(i) ? "yes" : "no") << std::endl;
    }

    std::cout << "Tries to readd the integers" << std::endl;
    for (int i = 0; i < 100; i++) {
        std::cout << "Re-add " << i << "? "
            << (integers.insert(i) ? "yes":"no") << std::endl;
    }
    printContainer(integers);

    for (int i = 0; i < 100; ) {
        if (integers.at(i) % 2 && integers.at(i) != 2) {
            std::cout << "Is " << integers.at(i) << " removed? "
                << (integers.erase(integers.at(i)) ? "yes":"no") << std::endl;
            continue;
        }
        i++;
    }

    printContainer(integers);

    std::cout << "Removes all non primes: " << std::endl;
    for (int i = 2; i < 50; i++) {
        std::cout << "Removes all numbers divisable by " << i << std::endl;
        for (int j = 0; j < integers.getLength(); ) {
            if (!(integers.at(j)%2) && integers.at(j) != i) {
                std::cout << "Is " << i << " removed? "
                    << (integers.erase(integers.at(j)) ? "yes":"no") << std::endl;
                continue;
            }
            j++;
        }
    }
    
    printContainer(integers);
}

void testLinkedLists() {
    LinkedList list;
    auto first = list.insert(list.end(), "first!");
    for (int i = 0; i < 100; i++) {
        list.insert(list.end(), "test");
    }
    std::cout << *first << std::endl;
    std::cout << list << std::endl;
}

void testForwardLists() {

    std::forward_list<Person> list;
    Person a("Oskar", "Oestby");
    Person b("Aadne", "Kaarstad");
    Person c("Andrine", "Gudbrandsen");
    Person d("Elin", "Roed");
    Person e("Kamilla", "Roed");
    list.push_front(a);

    std::cout << "Adding Aadne" << std::endl;
    insertOrdered(list, b);
    printContainer(list);

    std::cout << "Adding Andrine" << std::endl;
    insertOrdered(list, c);
    printContainer(list);

    std::cout << "Adding Elin" << std::endl;
    insertOrdered(list, d);
    printContainer(list);

    std::cout << "Adding Kamilla" << std::endl;
    insertOrdered(list, e);
    printContainer(list);
}

void testStdLists() {
    std::list<Person> list;
    Person a("Oskar", "Oestby");
    Person b("Aadne", "Kaarstad");
    Person c("Andrine", "Gudbrandsen");
    Person d("Elin", "Roed");
    Person e("Kamilla", "Roed");
    
    std::cout << "Adding Oskar" << std::endl;
    insertOrdered(list, a);
    printContainer(list);
    std::cout << std::endl;

    std::cout << "Adding Aadne" << std::endl;
    insertOrdered(list, b);
    printContainer(list);
    std::cout << std::endl;

    std::cout << "Adding Andrine" << std::endl;
    insertOrdered(list, c);
    printContainer(list);
    std::cout << std::endl;

    std::cout << "Adding Elin" << std::endl;
    insertOrdered(list, d);
    printContainer(list);
    std::cout << std::endl;

    std::cout << "Adding Kamilla" << std::endl;
    insertOrdered(list, e);
    printContainer(list);
    std::cout << std::endl;
}
