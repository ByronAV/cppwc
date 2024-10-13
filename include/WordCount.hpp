#include <fstream>

class WordCount {
 public:
  WordCount(const std::string& filename);
  WordCount(std::stringstream& ss);
  int GetLines();
  int GetBytes();
  int GetWords();
  int GetChars();

 private:
  std::ifstream input_file;
};