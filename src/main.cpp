#include <boost/program_options.hpp>
#include <iostream>
#include <stdexcept>

#include "WordCount.hpp"

namespace po = boost::program_options;

int main(int argc, char* argv[]) {
  try {
    
    po::options_description desc(
        "--------------- CPP Word Count Tool ---------------\n");

    desc.add_options()("help,h", "Print help")(
        "byte,c", "Outputs the number of bytes in a file.")(
        "line,l", "Outputs the number of lines in a file")(
        "word,w", "Outputs the number of words in a file")(
        "char,m", "Outputs the number of characters in a file")(
        "file,f", po::value<std::string>()->default_value(""), "The input file");

    po::positional_options_description p;
    p.add("file", -1);

    po::variables_map vm;
    po::store(
        po::command_line_parser(argc, argv).options(desc).positional(p).run(),
        vm);

    bool only_file = true;

    // Extend the functionality to include standard input
    std::unique_ptr<WordCount> file;
    if (vm["file"].as<std::string>() == "") {
      std::stringstream buffer;
      buffer << std::cin.rdbuf();
      file = std::make_unique<WordCount>(buffer);
    } else {
      file = std::make_unique<WordCount>(vm["file"].as<std::string>());
    }
    po::notify(vm);

    if (vm.count("help")) {
      std::cout << desc << std::endl;
      return 0;
    }
    if (vm.count("line")) {
      std::cout << file->GetLines() << " ";
      only_file = false;
    }
    if (vm.count("word")) {
      std::cout << file->GetWords() << " ";
      only_file = false;
    }
    if (vm.count("byte")) {
      std::cout << file->GetBytes() << " ";
      only_file = false;
    }
    if (vm.count("char")) {
      std::cout << file->GetChars() << " ";
      only_file = false;
    }

    if (only_file) {
      std::cout << file->GetLines() << " " << file->GetWords() << " "
                << file->GetBytes() << " ";
    }

    std::cout << vm["file"].as<std::string>() << std::endl;

    return 0;
  } catch (const std::runtime_error& e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return 60;
  } catch (const po::error& ex) {
    std::cerr << "Error: " << ex.what() << std::endl;
    return 61;
  }
}