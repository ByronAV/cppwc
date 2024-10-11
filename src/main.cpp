#include <stdexcept>
#include <iostream>
#include <boost/program_options.hpp>

#include "WordCount.hpp"


namespace po = boost::program_options;

int main(int argc, char* argv[]) {
    try {
        if (argc < 2) {
            throw std::runtime_error("ERROR: Expected at least a flag and a file.");
        }

        po::options_description desc("--------------- CPP Word Count Tool ---------------\n");

        desc.add_options()
            ("help,h", "Print help")
            ("byte,c", "Outputs the number of bytes in a file.")
            ("line,l", "Outputs the number of lines in a file")
            ("word,w", "Outputs the number of words in a file")
            ("char,m", "Outputs the number of characters in a file")
            ("file,f", po::value<std::string>(), "The input file")
            ;

        po::positional_options_description p;
        p.add("file", -1);

        po::variables_map vm;
        po::store(po::command_line_parser(argc, argv).
                    options(desc).positional(p).run(), vm);
        po::notify(vm);
        bool only_file = true;  

        if (vm.count("help")) {
            std::cout << desc << std::endl;
            return 0;
        }
        if (vm.count("line")) {
            auto line_count = std::make_unique<WordCount>(vm["file"].as<std::string>());
            std::cout << line_count->GetLines() << " ";
            only_file = false;
        }
        if (vm.count("word")) {
            auto word_count = std::make_unique<WordCount>(vm["file"].as<std::string>());
            std::cout << word_count->GetWords() << " ";
            only_file = false;
        }
        if (vm.count("byte")) {
            auto byte_count = std::make_unique<WordCount>(vm["file"].as<std::string>());
            std::cout << byte_count->GetBytes() << " ";
            only_file = false;
        }
        if (vm.count("char")) {
            auto char_count = std::make_unique<WordCount>(vm["file"].as<std::string>());
            std::cout << char_count->GetChars() << " ";
            only_file = false;
        }

        if (only_file) {
            auto count = std::make_unique<WordCount>(vm["file"].as<std::string>());
            std::cout << count->GetLines() << " " << count->GetWords() << " " << count->GetBytes() <<
                            " ";
        }

        std::cout << vm["file"].as<std::string>() << std::endl;

        return 0;
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 60;
    }
    catch (const po::error &ex) {
        std::cerr << "Error: " << ex.what() << std::endl;
        return 61;
    }
}