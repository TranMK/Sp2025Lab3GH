#include <cctype>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "utility.hpp"

// References the global variable in `main.cpp`.
extern bool past_first_file;

/* Function `get_file_lines`:
   Return: `vector<string>`

   Parameters:
   - `string user_file_name` — is the file name the user input using `std::cin`.

   Description: Attempts to open the file, and if unsuccessful, prompts the user
   to try again. Once a file is open, it continually uses `getline` and pushes
   the contents into a vector. The output is not sanitized.
*/
auto get_file_lines(std::string user_file_name) -> std::vector<std::string> {
  // Attempt to open file and reprompt the user for a file if unsuccessful.
  std::ifstream file(user_file_name, std::ios::in);
  while (file.fail()) {
    std::cout << "Failed to open/find the file. Type in the name of another "
                 "file you would like information on: "
              << std::endl;
    std::getline(std::cin, user_file_name);
    file.open(user_file_name, std::ios::in);
  }

  // NOTE(Ansh): Assumes the contents of the file are correctly formatted. Can
  // use asserts otherwise, or other kinds of validation.
  //
  // Reads the contents of the file until EOF.
  std::vector<std::string> file_contents;
  std::string line;
  while (getline(file, line)) {
    if (line != "\0")
      file_contents.push_back(line);
  }
  file.close();

  return file_contents;
}

/* Function `get_content_source`:
   Return: `vector<string>`

   Parameters:
   - `vector<string> file_contents` — every line in the file the user wished to
   process as a vector.

   Description: Attempts to slice the vector assuming there exists a line
   beginning with "Contents:". If not, assumes the contents begin line 3. This
   does not treat empty lines with a '\n' separately or otherwise discard then,
   as they will be used to count the number of lines. Once it has established
   the index of the contents line, it pushes the rest of the content following
   it into another vector that is returned.
*/
auto get_content_source(std::vector<std::string> file_contents)
    -> std::vector<std::string> {
  // Find the index at which the line "Contents: " exists.
  // Need this so we can slice the vector from its index onwards (exclusive) and
  // treat the rest as the source of the text.
  size_t contents_idx = 0;
  for (contents_idx = 0; contents_idx < file_contents.size(); contents_idx++) {
    // NOTE(Ansh): Ignore LSP error.
    if (file_contents[contents_idx].starts_with("Contents:")) {
      break;
    }
  }
  if (contents_idx == file_contents.size())
    contents_idx = 2;

  std::vector<std::string> src;
  for (size_t i = contents_idx + 1; i < file_contents.size(); i++) {
    std::string file_content = file_contents[i];
    src.push_back(file_content);
  }

  return src;
}

/* Function ``:
   Return: none.

   Parameters:
   - `struct FileInformation fi` — all the current information stored about a
   file (as a struct).

   Description: Attempts to open a hardcoded file called `CardCatalog.txt` with
   specified access flags in the current directory. It is created if
   non-existent. Following this, it does some work to separate the first and
   last name of the author and outputs all the information in `fi` in the order:
   title, full name, first name, last name, word count, and line count.
*/
void save_file_information(FileInformation fi) {
  // Strange desired behavior of varying access flags.
  std::ofstream card_catalog_file;
  if (past_first_file) {
    card_catalog_file.open("CardCatalog.txt", std::ios::trunc);
  } else {
    card_catalog_file.open("CardCatalog.txt", std::ios::app);
  }

  std::string string_delimiter = " ";
  size_t space_index = fi.author.find(string_delimiter);
  std::string first_name = fi.author.substr(0, space_index);
  std::string last_name =
      fi.author.substr(space_index + 1, fi.author.size() - 1);

  card_catalog_file << "Title: " << fi.title << "\n\n";
  card_catalog_file << "Full Author: " << fi.author << "\n\n";
  card_catalog_file << "Author First Name: " << first_name << "\n\n";
  card_catalog_file << "Author Last Name: " << last_name << "\n\n";
  card_catalog_file << "Word Count: " << fi.word_count << "\n\n";
  card_catalog_file << "Line Count: " << fi.line_count << "\n\n";
}
