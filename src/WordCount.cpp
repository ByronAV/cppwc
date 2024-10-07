#include "WordCount.hpp"

WordCount::WordCount(const std::string& filename) : input_file(filename) {
    if (!input_file.is_open()){
        throw std::runtime_error("ERROR: Could not open file.");
    }
}

int WordCount::GetBytes()
{
    input_file.seekg(0, std::ios::end); // Move to end to calculate size
    int size = input_file.tellg(); // Get the size of the file in bytes
    input_file.seekg(0, std::ios::beg); // Reset to beginning
    return size;
}