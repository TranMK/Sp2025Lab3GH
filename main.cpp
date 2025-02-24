#include <fstream>
#include <iostream>
#include <numeric>
#include <unistd.h>
#include <vector>

#include "Errors.hpp"
#include "Queue.hpp"
#include "Stack.hpp"

namespace fs = std::filesystem;

auto string_split(std::string to_split, std::string delimiter)
    -> std::vector<std::string>;
auto join_strings(std::vector<std::string> strings, std::string delimiter)
    -> std::string;
auto reverse_join_chars(Stack<char> s) -> std::string;

auto main() -> int {
  char input_src;
  std::cout << "Would you like to add input from the terminal or from a file? "
               "(t/f): ";
  std::cin >> input_src;
  std::cin.ignore();
  std::cin.clear();

  switch (input_src) {
  case 't': {
    break;
  }
  case 'f': {
    std::string file_path;
    std::cout << "Enter the name of the file in this directory: ";
    std::getline(std::cin, file_path);

    // Determines if the file the user input is available.
    std::ifstream file(file_path);
    while (!file.good()) {
      std::cout
          << "Could not find the file in the current directory. Try again: ";
      std::getline(std::cin, file_path);
      file.open(file_path);
    }

    // File is available.
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
  std::vector<std::string> chars;
  try {

    char *c = s.pop();
    while (s.length() != 0) {
      chars.push_back(std ::string(1, *c));
      c = s.pop();
    }
  } catch (StackUnderflowError e) {
    std::cout << e.message << "AT" << __FILE__ << __LINE__;
  }

  return std::accumulate(std::next(chars.begin()), chars.end(), chars[0],
                         [](std::string a, std::string b) { return a + b; });
};
