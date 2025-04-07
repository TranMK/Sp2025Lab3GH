#include <cctype>
#include <map>
#include <string>
#include <vector>

#pragma once

// Should order the fields so sized fields appear first for faster read
// access, but it shouldn't make a noticeable difference here.
struct FileInformation {
  std::string title;
  std::string author;
  size_t word_count;
  size_t line_count;
  // A `map` instead of a vector so the relationship between the key and the
  // value is more apparent. Iteration is also nicer.
  std::map<char, size_t> letter_frequency;

  /* Struct member function `count_letter_frequency`:
     Return: none.

     Parameters:
     - `vector<string> src` — the lines under "Contents:", i.e., the actual
     text.
     - `map<char, size_t> map` — the letter frequency stored as a map from
     `char`s to `size_t`s.

     Description: First, this function initializes every character in the
     alphabet to have count 0. This is done to ensure the printing out of all
     characters when the user displays the frequency. Next, we iterate over all
     characters in every line in `src` and check if it is an alphabetical
     character using `std::isalpha` — if it is, then we use it as a key in our
     map and add one to its value.
  */
  void count_letter_frequency(const std::vector<std::string> src);

  /* Struct member function `count_letters`:
     Return: `size_t` representing the count.

     Parameters: - `map<char, size_t> map` — the letter frequency stored as a
     map from `char`s to `size_t`s.

     Description: When this function is called, the letter frequency has already
     been calculated and stored within the struct. All this function has to do
     is iterate over all its values and sum them, which we do using a standard
     for loop.
  */
  size_t count_letters(std::map<char, size_t> map);

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

  /* Struct member function `display_letter_frequency`:
     Return: none.

     Parameters: none.

     Description: Prints out the title of the book, followed by calculating the
     number of letters present in `src` using the stored letter frequency.
     Inside the loop, we iterate through the `(key, value)` pairs in the map and
     access the elements according to their position inside it — `first` and
     `second`. To get the frequency as a percentage, we divide each number of
     occurences by the total letter count and multiply by 100. Since the number
     of occurences of each letters and the total number of letters are both
     integers, we `static_cast` them for calculations.
  */
  void display_letter_frequency();
};
