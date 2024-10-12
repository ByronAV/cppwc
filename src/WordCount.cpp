#include "WordCount.hpp"

#include <algorithm>
#include <codecvt>
#include <locale>
#include <sstream>

WordCount::WordCount(const std::string& filename) : input_file(filename) {
  if (!input_file.is_open()) {
    throw std::runtime_error("ERROR: Could not open file.");
  }
}

int WordCount::GetBytes() {
  input_file.seekg(0, std::ios::end);  // Move to end to calculate size
  int size = input_file.tellg();       // Get the size of the file in bytes
  input_file.seekg(0, std::ios::beg);  // Reset to beginning
  return size;
}

int WordCount::GetLines() {
  int line_count = 0;
  const std::size_t buffer_size = 8192;
  char buffer[buffer_size];

  // Read the file in chunks
  while (input_file.read(buffer, buffer_size)) {
    line_count += std::count(buffer, buffer + input_file.gcount(), '\n');
  }

  line_count += std::count(buffer, buffer + input_file.gcount(), '\n');

  input_file.clear();   // Clear the EOF flag
  input_file.seekg(0);  // Seek back to the beginning

  return line_count;
}

int WordCount::GetWords() {
  int word_count = 0;
  std::string line;

  while (std::getline(input_file, line)) {
    std::istringstream ss(line);
    std::string word;

    while (ss >> word) {
      word_count++;
    }
  }

  input_file.clear();   // Clear the EOF flag
  input_file.seekg(0);  // Seek back to the beginning

  return word_count;
}

int WordCount::GetChars() {
  int char_count = 0;
  std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
  std::wstring wline;
  std::string line;

  while (std::getline(input_file, line)) {
    wline = converter.from_bytes(line);  // Convert from UTF-8 to wide string
    char_count += wline.size();          // Count the number of characters
    char_count++;                        // Account for the newline character
  }

  input_file.clear();   // Clear the EOF flag
  input_file.seekg(0);  // Seek back to the beginning

  return char_count;
}