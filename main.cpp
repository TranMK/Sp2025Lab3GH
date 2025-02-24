#include <filesystem>
#include <fstream>
#include <iostream>
#include <numeric>
#include <vector>

#include "Queue.hpp"
#include "Stack.hpp"

namespace fs = std::filesystem;

auto string_split(std::string to_split, std::string delimiter)
    -> std::vector<std::string>;
auto join_strings(std::vector<std::string> strings, std::string delimiter)
    -> std::string;
auto reverse_join_chars(Stack<char> s) -> std::string;

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

    // File is available.
    std::ifstream file{file_path};
    std::vector<std::string> reversed_words_sentence;

    std::string file_line;
    while (std::getline(file, file_line)) {
      std::vector<std::string> words_in_line =
          string_split(file_line, std::string(" "));
      size_t words_in_line_count = words_in_line.size();

      Queue<std::string> sentencer_order_preserver(words_in_line_count);
      Stack<char> reverser(file_line.size());
      for (std::string &word : words_in_line) {
        for (char &character : word) {
          reverser.push(&character);
        }
        std::string reversed_word =
            reverse_join_chars(reverser); // This call empties the reverser by
                                          // calling `pop()` repeatedly.
        reversed_words_sentence.push_back(reversed_word);
      }

      std::string reversed_sentence =
          join_strings(reversed_words_sentence, " ");
      std::cout << reversed_sentence << std::endl;
    }

    file.close();

    break;
  }

  return 0;
}

auto string_split(std::string to_split, std::string delimiter)
    -> std::vector<std::string> {
  std::vector<std::string> split_words;

  size_t delim_pos = 0;
  while ((delim_pos = to_split.find(delimiter)) != std::string::npos) {
    split_words.push_back(to_split.substr(0, delim_pos));
    to_split.erase(0, delim_pos + delimiter.length());
  }
  // Final iteration won't find an instance of a delimiter so push manually.
  split_words.push_back(to_split);

  return split_words;
}

auto join_strings(std::vector<std::string> strings, std::string delimiter)
    -> std::string {
  return std::accumulate(
      std::next(strings.begin()), strings.end(), strings[0],
      [delimiter](std::string a, std::string b) { return a + delimiter + b; });
};

auto reverse_join_chars(Stack<char> s) -> std::string {
  std::vector<char> chars;
  char c;
  while ((c = *s.pop())) {
    chars.push_back(c);
  }

  std::string first_char(1, chars[0]);
  return std::accumulate(
      std::next(chars.begin()), chars.end(), first_char,
      [](char a, char b) { return std::string(1, a) + std::string(1, b); });
};
