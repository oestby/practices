#include <vector>
#include <string>
#include <iostream>
#include <set>
#include <forward_list>
#include <list>
#include <SimpleSet.h>
//#include <LinkedList.h>
#include <tests.hpp>


int main() {
    int choice = -1;
    while (choice) {
        std::cout << "What do you want to see?" << std::endl
            << "1 - STL Set" << std::endl
            << "2 - SimpleSet" << std::endl
            << "3 - Forward List" << std::endl
            << "4 - STL List" << std::endl
            << "5 - LinkedList" << std::endl
            << "0 - Quit" << std::endl
            << "Enter a number: " << std::endl;
        std::cin >> choice;

        switch (choice) {
            case 1:
                testStdSet();
                break;
            case 2:
                testSimpleSet();
                break;
            case 3:
                testForwardLists();
                break;
            case 4:
                testStdLists();
                break;
            case 5:
                testLinkedLists();
                break;
            default:
                std::cout << "Not a valid choice" << std::endl;
                break;
        }
    }
    return 0;
}
