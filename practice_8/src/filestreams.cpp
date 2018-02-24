#include "filestreams.hpp"

#include <map> //Duhh..
#include <sstream> //std::stringsream
#include <algorithm> //std::remove_if

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

void
wordStatistics(std::string filename)
{
    strvec words;
    int number_of_lines, number_of_words;
    std::string longest_word;
    std::map<std::string, int> word_occurances;
    strvec lines = readSingleLines(filename);
    number_of_lines = lines.size();

    std::string temp;
    for (std::string line: lines)
    {
        std::stringstream ss(line);
        while (ss>>temp)
        {
            //Removes punctuation from the string.
            temp.erase(std::remove_if(temp.begin(), temp.end(), ispunct), temp.end());
            for (char c: temp)
            {
                c = tolower(c);
            }
            words.push_back(temp);
        }
    }

    number_of_words = words.size();
    for (std::string wrd: words)
    {
        if(!word_occurances[wrd])
            word_occurances[wrd] = 1;
        else
            word_occurances[wrd] += 1;
        if(wrd.size() > longest_word.size())
            longest_word = wrd;
    }

    std::cout << "Word statistics:" << std::endl
    << "The longest word:" << longest_word << std::endl
    << "Number of words: " << number_of_words << std::endl
    << "Number of lines: " << number_of_lines << std::endl
    << "Word occurannce:" << std::endl;
    for (auto it = word_occurances.cbegin(); it != word_occurances.cend(); it++)
    {
        std::cout << it->first << ": " << it->second << std::endl;
    }

}
