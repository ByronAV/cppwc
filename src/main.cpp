#include <stdexcept>
#include <iostream>
#include <cxxopts.hpp>

#include "WordCount.hpp"


int main(int argc, char* argv[]) {
    try {
        // if (argc < 2) {
        //     throw std::runtime_error("ERROR: Expected at least a flag and a file.");
        // }

        cxxopts::Options options("cppwc", "Word Count tool");

        options.add_options()
            ("h, help", "Print help")
            ("c, bytes", "Outputs the number of bytes in a file.", cxxopts::value<std::string>())
            ;

        auto result = options.parse(argc, argv);
        if (result.count("help")) {
            std::cout << " ----------- Word count tool: -----------\n"
                      << " - help(h): Prints help message\n"
                      << " - bytes(c): Prints the bytes in a file\n" << std::endl;
        }
        if (result.count("bytes")) {
            auto byte_count = std::make_unique<WordCount>(result["bytes"].as<std::string>());
            std::cout << byte_count->GetBytes() << " " << result["bytes"].as<std::string>() << std::endl;
        }
    }
    catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }
}