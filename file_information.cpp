#include <cctype>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "file_information.hpp"

/* Struct member function `count_word_frequency`:
   Return: none.

   Parameters:
   - `vector<string> src` — the lines under "Contents:", i.e., the actual text.
   - `map<char, size_t> map` — the word frequency stored as a map from `char`s
   to `size_t`s.

   Description: First, this function initializes every character in the alphabet
   to have count 0. This is done to ensure the printing out of all characters
   when the user displays the frequency. Next, we iterate over all characters in
   every line in `src` and check if it is an alphabetical character using
   `std::isalpha` — if it is, then we use it as a key in our map and add one to
   its value.
*/
void FileInformation::count_word_frequency(const std::vector<std::string> src) {
  Tree<std::string> tree;

  // // Initialize each character in the alphabet so they show up, even if at
  // 0%. for (char c = 'a'; c <= 'z'; c++) {
  //   map[c] = 0;
  // }

  for (std::string line : src) {
    std::string word;
    std::vector<std::string> words;
    while (std::getline(std::istringstream(line), word, ' ')) {
      words.push_back(word);
    }

    for (std::string word : words) {
      // `tolower` to avoid case-sensitivity.
      tree.Insert(word);
    }
  }

  word_frequency = tree;
};

/* Struct member function `count_words`:
   Return: `size_t` representing the count.

   Parameters: - `vector<string> src` — the lines under "Contents:", i.e., the
   actual text.

   Description: Counts the number of words in `src` by iterating over its
   elements (corresponding to lines in the file) and streaming into a
   `string_stream` each word. This works because the stream only accepts
   characters until spaces, with punctuation being coupled with the words so
   long as they are not delimited by spaces themselves. Every time this can be
   done (hence the while loop), we add one to the counter and return at the
   end.
*/
void FileInformation::count_words(const std::vector<std::string> src) {
  size_t num_words = 0;
  for (std::string line : src) {
    if (line.length() == 0)
      continue;
    std::stringstream ss(line);
    std::string word;
    while (ss >> word) {
      word_frequency.Insert(word);
    }
  }

  word_count = num_words;
};

auto FileInformation::get_total_words() -> size_t {
  size_t total_word_count = 0;

  std::vector<Node<std::string> *> all_words =
      word_frequency.GetAllAscending(word_frequency.get_root());
  for (auto word : all_words) {
    total_word_count += word->count;
  }

  return total_word_count;
}

/* Struct member function `count_lines`:
   Return: `size_t` representing the count.

   Parameters: - `vector<string> src` — the lines under "Contents:", i.e., the
   actual text.

   Description: Iterates through `src` and adds one to the counter `num_lines`
   with every iteration. A loop is used instead of `stc.size()` so you have the
   option of filtering out the appropriate lines, such as those which are empty.
   Note the commented out `if``.
*/
void FileInformation::count_lines(const std::vector<std::string> src) {
  size_t num_lines = 0;
  for (std::string line : src) {
    // NOTE(Ansh): The below if statement would ignore blank lines as escape
    // sequences do not contribute to the length of a string.
    //
    // if (line.length() != 0)
    num_lines += 1;
  }

  line_count = num_lines;
};

/* Struct member function `display_word_frequency`:
   Return: none.

   Parameters: none.

   Description: Prints out the title of the book, followed by calculating the
   number of words present in `src` using the stored word frequency. Inside
   the loop, we iterate through the `(key, value)` pairs in the map and access
   the elements according to their position inside it — `first` and `second`. To
   get the frequency as a percentage, we divide each number of occurences by the
   total word count and multiply by 100. Since the number of occurences of
   each words and the total number of words are both integers, we
   `static_cast` them for calculations.
*/
void FileInformation::display_word_frequency() {
  // NOTE(Ansh): Printing out `title` by itself doesn't actually work. This is
  // because it ends with a carriage return. Why? Because Windows. Windows
  // uses the CRLF format for files. This adds a linefeed ('\n') AND a
  // carriage return ('\r', renders as '^M' for me using `cat -ve`). I do not
  // wish to spend 30 minutes debugging this again -- please switch from
  // Windows.
  //
  // Using a substring works instead because the string length isn't affected
  // by escape sequences.
  // For carriage returns, see: https://en.wikipedia.org/wiki/Carriage_return.
  std::cout << title.substr(0, title.length())
            << " word frequency:" << std::endl;

  size_t total_words = get_total_words();
  std::vector<Node<std::string> *> words_alphabetical =
      word_frequency.GetAllAscending(word_frequency.get_root());
  for (auto word_node : words_alphabetical) {
    std::cout << word_node->data << ": "
              << static_cast<float>(word_node->count) /
                     static_cast<float>(total_words) * 100.
              << "%" << std::endl;
  }
  std::cout << std::endl;
}
