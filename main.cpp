#include <cctype>
#include <iostream>

#include "utility.hpp"

// Used an an indicator when opening a file to vary the access flags. Used in
// `utility.cpp`.
bool past_first_file = false;

auto main() -> int {
  past_first_file = false;
  // Infinite loop until the user does not wish to process another file.
  while (true) {

    std::string user_file_name;
    std::cout << "Type in the name of the file you would like information on: "
              << std::endl;
    std::getline(std::cin, user_file_name);
    // Load the file lines.
    std::vector<std::string> file_contents = get_file_lines(user_file_name);

    // Begin to initialize `FileInformation`.
    FileInformation fi = {.title = file_contents[0],
                          .author = file_contents[1]};
    // Get content source lines.
    std::vector<std::string> src = get_content_source(file_contents);

    // Do work to fill `FileInformation`.
    fi.count_words(src);
    fi.count_lines(src);

    save_file_information(fi);

    // Allow for the user to display the letter frequency of the file just
    // processed.
    std::cout << std::endl;
    std::cout << "Would you like to view the letter frequency? (Y/N): ";
    char see_letter_frequency;
    std::cin >> see_letter_frequency;
    std::cout << std::endl;
    if (see_letter_frequency == 'Y' || see_letter_frequency == 'y') {
      fi.display_word_frequency();
    }

    // Prompt the user to input another file if they wish.
    std::cout << "Would you like to process another file? (Y/N): ";
    char process_another_file;
    std::cin >> process_another_file;
    std::cout << std::endl;
    if (process_another_file == 'N' || process_another_file == 'n') {
      break;
    }
    past_first_file = true;

    // Need to do this so the '\n' remaining in the stream after pressing enter
    // does not trigger the `getline` at the beginning of this loop.
    std::cin.clear();
    std::cin.ignore();
  }

  // User has said no to processing another file.
  return 0;
}
