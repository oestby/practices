#include <map>

#include "filestreams.hpp"

typedef std::vector<std::string> strvec;


void
writeToFile(std::string filename)
{
    std::ofstream filestream(filename);
    if(!filestream.is_open())
    {
        std::cout << "Could not open file: \"" << filename << "\"" << std::endl;
        filestream.close();
        return;
    }
    std::cout << "Enter messages to print to the file \"" << filename << "\". " << std::endl
    << "Enter \"quit\" or \"q\" to quit." << std::endl;
    std::string msg = "q";    
    while (filestream.is_open())
    {
        std::cout << "Enter a line:\n";
        std::cin >> msg;
        if(msg == "quit" || msg == "q")
            break;
        filestream << msg << "\n";
    }
    filestream.close();
}

void
readFromThenWriteToNewFile(std::string old_file, std::string new_file)
{
    std::ifstream input_file(old_file);
    std::ofstream output_file(new_file);
    std::string line;
    if(input_file.is_open() && output_file.is_open())
    {
        while(getline(input_file, line))
        {
            output_file << line << "\n";
        }
    }
    else
    {
        std::cout << "Could not open files!" << std::endl;
    }

}

strvec
readSingleLines(std::string filename)
{
    strvec vec;
    std::string line;
    std::ifstream file(filename);
    while (getline(file, line))
    {
        vec.push_back(line);
    }
    return vec;
}

void
countCharacterOccurances(std::string filename)
{
    std::map<char, int> char_map;
    strvec vec = readSingleLines(filename);
    for (auto x: vec)
    {
        for (char c: x)
        {
            if (!char_map[c])
            {
                char_map[c] = 1;
            }
            else
            {
                char_map[c] += 1;
            }
        }
    }
    int n_l = 0;
    int amount_of_characters = 0;
    std::cout << "Character statistics:" << std::endl;
    for (auto it = char_map.begin(); it != char_map.end(); it++)
    {
        std::cout << it->first << ":" << it->second;
        n_l++;
        if(!(n_l%8)) std::cout << std::endl;
        else std::cout << "\t";
        amount_of_characters += it->second;
    }
    std::cout << "\nTotal number of characters: " << amount_of_characters << std::endl;
}