#include <fstream>

class WordCount {
public:
    WordCount(const std::string& filename);
    int GetBytes();
private:
    std::ifstream input_file;
};