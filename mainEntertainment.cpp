#include <iostream>
#include <string>

#include "EntertainmentCollection.hpp"
#include "Game.hpp"

void get_and_add_game_attributes(Game *game);

int main() {
  EntertainmentCollection<Game> collection;

  while (true) {
    std::cout << "--- OPTIONS ---" << std::endl;
    std::cout << "Press 1 to add a Game to the collection" << std::endl;
    std::cout << "Press 2 to remove a Game from the collection" << std::endl;
    std::cout << "Press 3 to see how many Games are on the collection"
              << std::endl;
    std::cout << "Press 4 to quit" << std::endl;
    std::string user_option;
    std::getline(std::cin, user_option);
    if (user_option == "4") {
      break;
    }

    switch (std::stoul(user_option)) {
    case 1: {
      auto *new_game = new Game;
      try {
        collection.add_item(new_game);
      } catch (std::string e) {
        std::cout << e << std::endl;
      };
      get_and_add_game_attributes(new_game);
      break;
    }
    case 2: {
      try {
        Game *removed_game = collection.remove_item();
        removed_game->Details();
      } catch (std::string e) {
        std::cout << e << std::endl;
        ;
      };
      break;
    }
    case 3:
      size_t game_count = collection.get_item_count();
      std::cout << game_count << " Game(s) left in the collection."
                << std::endl;
      break;
    }
  }

  return 0;
}

void get_and_add_game_attributes(Game *game) {
  std::string game_title, game_description, game_rating_as_str;
  std::cout << "Enter the title of the game: ";
  std::getline(std::cin, game_title);
  std::cout << std::endl;
  std::cout << "Enter the description of the game: ";
  std::getline(std::cin, game_description);
  std::cout << std::endl;
  std::cout << "Enter the rating of the game: ";
  std::getline(std::cin, game_rating_as_str);
  std::cout << std::endl;

  double game_rating = std::stod(game_rating_as_str);
  game->set_title(game_title);
  game->set_description(game_description);
  game->set_rating(game_rating);
};
