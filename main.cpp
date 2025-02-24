#include <filesystem>
#include <fstream>
#include <iostream>

#include "Queue.hpp"
#include "Stack.hpp"

namespace fs = std::filesystem;

auto main() -> int {
  std::string input_src;
  std::cout << "Would you like to add input from the terminal or from a file? "
               "(t/f): ";
  std::getline(std::cin, input_src);
  std::cout << std::endl;

  switch (input_src[0]) {
  case 't': {
    break;
  }
  case 'f':
    std::string file_path;
    std::cout << "Enter the name of the file in this directory: ";
    std::getline(std::cin, file_path);
    std::cout << std::endl;

    // Determines if the file the user input is available.
    bool found_file_in_dir = false;
    for (const auto &entry : fs::directory_iterator("")) {
      if (entry.path().filename() == file_path) {
        found_file_in_dir = true;
      }
    }

    while (!found_file_in_dir) {
      std::cout
          << "Could not find the file in the current directory. Try again: ";
      std::getline(std::cin, file_path);
      for (const auto &entry : fs::directory_iterator("")) {
        if (entry.path().filename() == file_path) {
          found_file_in_dir = true;
        }
      }
    }

    // File is available. Open it.
    std::ifstream file{file_path};
    Stack<std::string> reverser(0);
    Queue sentencer_order_presevser;
    while (true) {
      // Work.
    }
    file.close();

    break;
  }

  return 0;
}
