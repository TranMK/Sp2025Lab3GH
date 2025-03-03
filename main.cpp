#include <fstream>
#include <iostream>
#include <numeric>
#include <sstream>
#include <unistd.h>
#include <vector>

#include "Errors.hpp"
#include "Queue.hpp"
#include "Stack.hpp"

auto string_split(std::string to_split,
                  std::string delimiter) -> std::vector<std::string>;
auto join_strings(Queue<std::string> reversed_words,
                  std::string delimiter) -> std::string;
auto reverse_join_chars(Stack<char> &s) -> std::string;

auto main() -> int {
  char input_src;
  std::cout << "Would you like to add input from the terminal or from a file? "
               "(t/f): ";
  std::cin >> input_src;
  std::cin.ignore();
  std::cin.clear();

  switch (input_src) {
  case 't': {
    std::string user_text;
    std::getline(std::cin, user_text);
    size_t user_text_count = user_text.size();
    std::vector<std::string> words_in_line =
        string_split(user_text, std::string(" "));

    Queue<std::string> sentence_order_preserver(0);
    for (std::string &word : words_in_line) {
      Stack<char> reverser(0);
      for (char &character : word) {
        reverser.push(std::make_unique<char>(character));
      }

      std::string reversed_word =
          reverse_join_chars(reverser); // This call empties the reverser by
                                        // calling `pop()` repeatedly.
      sentence_order_preserver.enqueue(
          std::make_unique<std::string>(reversed_word));
    }

    std::string reversed_sentence =
        join_strings(std::move(sentence_order_preserver), " ");
    std::cout << reversed_sentence <<  std::endl;

    break;
  }
  case 'f': {
    std::string file_path;
    std::cout << "Enter the name of the file in this directory: ";
    std::getline(std::cin, file_path);

    // Determines if the file the user input is available.
    std::ifstream file(file_path);
    while (!file.is_open()) {
      std::cout
          << "Could not find the file in the current directory. Try again: ";
      std::getline(std::cin, file_path);
      file.open(file_path);
    }

    std::cout << "HERE";
    // File is available.
    std::string file_line;
    while (std::getline(file, file_line)) {
      std::vector<std::string> words_in_line =
          string_split(file_line, std::string(" "));
      size_t words_in_line_count = words_in_line.size();

      Queue<std::string> sentence_order_preserver(0);
      for (std::string &word : words_in_line) {
        Stack<char> reverser(0);
        for (char &character : word) {
          reverser.push(std::make_unique<char>(character));
        }

        std::string reversed_word =
            reverse_join_chars(reverser); // This call empties the reverser by
                                          // calling `pop()` repeatedly.
        sentence_order_preserver.enqueue(
            std::make_unique<std::string>(reversed_word));
      }

      std::string reversed_sentence =
          join_strings(std::move(sentence_order_preserver), " ");
      std::cout << reversed_sentence << std::endl;
    }

    file.close();
    break;
  }
  }

  return 0;
}

auto string_split(std::string to_split,
                  std::string delimiter) -> std::vector<std::string> {
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

auto join_strings(Queue<std::string> reversed_words,
                  std::string delimiter) -> std::string {
  std::stringstream reversed_sentence;

  try {
    std::unique_ptr<std::string> reversed_word;
    reversed_word = reversed_words.dequeue();
    while (reversed_word != nullptr) {
      reversed_sentence << *reversed_word + " ";
      reversed_word = reversed_words.dequeue();
    }
  } catch (QueueUnderflowError e) {
    // Do nothing.
  }

  return reversed_sentence.str();
};

auto reverse_join_chars(Stack<char> &s) -> std::string {
  std::vector<std::string> chars;

  try {
    while (s.length() != 0) {
      std::unique_ptr<char> *c = s.pop();
      chars.push_back(std::string(1, **c));
    }
  } catch (StackUnderflowError e) {
    // Do nothing.
  }

  return std::accumulate(std::next(chars.begin()), chars.end(), chars[0],
                         [](std::string a, std::string b) { return a + b; });
};
