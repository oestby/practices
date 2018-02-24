#include "filestreams.hpp"
#include <string>

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
    return 0;
}