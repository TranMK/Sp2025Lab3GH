#include <cctype>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

#include "file_information.hpp"

/* Struct member function `count_letter_frequency`:
   Return: none.

   Parameters:
   - `vector<string> src` — the lines under "Contents:", i.e., the actual text.
   - `map<char, size_t> map` — the letter frequency stored as a map from `char`s
   to `size_t`s.

   Description: First, this function initializes every character in the alphabet
   to have count 0. This is done to ensure the printing out of all characters
   when the user displays the frequency. Next, we iterate over all characters in
   every line in `src` and check if it is an alphabetical character using
   `std::isalpha` — if it is, then we use it as a key in our map and add one to
   its value.
*/
void FileInformation::count_letter_frequency(
    const std::vector<std::string> src) {
  std::map<char, size_t> map;

  // Initialize each character in the alphabet so they show up, even if at 0%.
  for (char c = 'a'; c <= 'z'; c++) {
    map[c] = 0;
  }

  for (std::string line : src) {
    for (char character : line) {
      if (std::isalpha(character))
        // `tolower` to avoid case-sensitivity.
        map[std::tolower(character)] += 1;
    }
  }

  letter_frequency = map;
};

/* Struct member function `count_letters`:
   Return: `size_t` representing the count.

   Parameters: - `map<char, size_t> map` — the letter frequency stored as a map
   from `char`s to `size_t`s.

   Description: When this function is called, the letter frequency has already
   been calculated and stored within the struct. All this function has to do is
   iterate over all its values and sum them, which we do using a standard for
   loop.
*/
size_t FileInformation::count_letters(std::map<char, size_t> map) {
  size_t count = 0;
  for (auto key_value_pair : map) {
    count += key_value_pair.second;
  }

  return count;
}

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
      num_words += 1;
    }
  }

  word_count = num_words;
};

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

/* Struct member function `display_letter_frequency`:
   Return: none.

   Parameters: none.

   Description: Prints out the title of the book, followed by calculating the
   number of letters present in `src` using the stored letter frequency. Inside
   the loop, we iterate through the `(key, value)` pairs in the map and access
   the elements according to their position inside it — `first` and `second`. To
   get the frequency as a percentage, we divide each number of occurences by the
   total letter count and multiply by 100. Since the number of occurences of
   each letters and the total number of letters are both integers, we
   `static_cast` them for calculations.
*/
void FileInformation::display_letter_frequency() {
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
  std::cout << title.substr(0, title.length() - 1)
            << " letter frequency:" << std::endl;

  size_t total_letters = count_letters(letter_frequency);
  for (auto key_value_pair : letter_frequency) {
    std::cout << key_value_pair.first << ": "
              << static_cast<float>(key_value_pair.second) /
                     static_cast<float>(total_letters) * 100.
              << "%" << std::endl;
  }
  std::cout << std::endl;
}
