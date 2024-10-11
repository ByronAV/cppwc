#include <fstream>

class WordCount {
public:
    WordCount(const std::string& filename);
    int GetLines();
    int GetBytes();
    int GetWords();
    int GetChars();
private:
    std::ifstream input_file;
};