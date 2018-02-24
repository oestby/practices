#include "filestreams.hpp"
#include "coursecatalog.hpp"

#include <string>
#include <iostream>

void
addCourses(CourseCatalog& cc)
{
    cc.addCourse("Informasjonsteknologi grunnkurs","TDT4110");
    cc.addCourse("Prosedyre- og objektorientert programmering","TDT4102");
    cc.addCourse("Matematikk 1", "TMA4100");

}

int main(int argc, char** argv)
{
    std::string file_1, file_2;
    switch(argc)
    {
        case 2:
        writeToFile(argv[1]);
        countCharacterOccurances(argv[1]);
        return 0;
        break;

        case 3:
        readFromThenWriteToNewFile(argv[1], argv[2]);
        return 0;
        break;

        default:
        std::cout << "No arguments provided! Continuing program." << std::endl;
        break;
    }

    CourseCatalog first;
    addCourses(first);
    first.addCourse("C++","TDT4102");
    std::cout << first;
    CourseCatalog second("test.txt");
    std::cout << second;

    
    return 0;
}