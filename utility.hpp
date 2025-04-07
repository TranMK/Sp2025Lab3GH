#include <cctype>
#include <vector>

#include "file_information.hpp"

// Comments for the functions are replicated in the corresponding `.cpp` file.

/* Function `get_file_lines`:
   Return: `vector<string>`

   Parameters:
   - `string user_file_name` — is the file name the user input using `std::cin`.

   Description: Attempts to open the file, and if unsuccessful, prompts the user
   to try again. Once a file is open, it continually uses `getline` and pushes
   the contents into a vector. The output is not sanitized.
*/
auto get_file_lines(std::string user_file_name) -> std::vector<std::string>;

/* Function `get_content_source`:
   Return: `vector<string>`

   Parameters:
   - `vector<string> file_contents` — every line in the file the user wished
   to process as a vector.

   Description: Attempts to slice the vector assuming there exists a line
   beginning with "Contents:". If not, assumes the contents begin line 3.
   This does not treat empty lines with a '\n' separately or otherwise
   discard then, as they will be used to count the number of lines. Once it
   has established the index of the contents line, it pushes the rest of the
   content following it into another vector that is returned.
*/
auto get_content_source(std::vector<std::string> file_contents)
    -> std::vector<std::string>;

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
void save_file_information(FileInformation fi);
