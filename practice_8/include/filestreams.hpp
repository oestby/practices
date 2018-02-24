#ifndef FILESTREAMS_HPP
#define FILESTREAMS_HPP
#include <fstream>
#include <string>
#include <iostream>
#include <vector>

void writeToFile(std::string filename);
void readFromThenWriteToNewFile(std::string old_file, std::string new_file);
std::vector<std::string> readSingleLines(std::string filename);
void countCharacterOccurances(std::string);

#endif
