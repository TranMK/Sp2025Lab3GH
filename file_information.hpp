#include <cctype>
#include <string>
#include <vector>

#include "BinaryTree.hpp"

#pragma once

// Should order the fields so sized fields appear first for faster read
// access, but it shouldn't make a noticeable difference here.
struct FileInformation {
  std::string title;
  std::string author;
  size_t word_count;
  size_t line_count;
  Tree<std::string> word_frequency;

  /* Struct member function `count_word_frequency`:
     Return: none.

     Parameters:
     - `vector<string> src` — the lines under "Contents:", i.e., the actual
     text.
     - `map<char, size_t> map` — the word frequency stored as a map from
     `char`s to `size_t`s.

     Description: First, this function initializes every character in the
     alphabet to have count 0. This is done to ensure the printing out of all
     characters when the user displays the frequency. Next, we iterate over all
     characters in every line in `src` and check if it is an alphabetical
     character using `std::isalpha` — if it is, then we use it as a key in our
     map and add one to its value.
  */
  void count_word_frequency(const std::vector<std::string> src);

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
  void count_words(const std::vector<std::string> src);

  auto get_total_words() -> size_t;

  /* Struct member function `count_lines`:
     Return: `size_t` representing the count.

     Parameters: - `vector<string> src` — the lines under "Contents:", i.e., the
     actual text.

     Description: Iterates through `src` and adds one to the counter `num_lines`
     with every iteration. A loop is used instead of `stc.size()` so you have
     the option of filtering out the appropriate lines, such as those which are
     empty. Note the commented out `if``.
  */
  void count_lines(const std::vector<std::string> src);

  /* Struct member function `display_word_frequency`:
     Return: none.

     Parameters: none.

     Description: Prints out the title of the book, followed by calculating the
     number of words present in `src` using the stored word frequency.
     Inside the loop, we iterate through the `(key, value)` pairs in the map and
     access the elements according to their position inside it — `first` and
     `second`. To get the frequency as a percentage, we divide each number of
     occurences by the total word count and multiply by 100. Since the number
     of occurences of each words and the total number of words are both
     integers, we `static_cast` them for calculations.
  */
  void display_word_frequency();
};
