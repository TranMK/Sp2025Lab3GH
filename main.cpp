#include <iostream>

#include "Errors.hpp"
#include "LinkedList.hpp"
#include "Part.hpp"

auto print_user_options() -> void;
auto get_user_option() -> int;
auto handle_user_option(DoublyLinkedList<Part> &ll, int user_option_idx)
    -> void;

auto main() -> int {
  DoublyLinkedList<Part> ll = DoublyLinkedList<Part>(nullptr);
  while (true) {
    print_user_options();
    size_t user_option_idx = get_user_option() - 1;
    handle_user_option(ll, user_option_idx);
  }

  return 0;
}

auto print_user_options() -> void {
  constexpr std::array<const char *, 9> LL_OPTIONS = {
      "add_item", "get_item", "is_in_list", "is_empty", "get_size",
      "see_next", "see_prev", "see_at",     "reset"};

  std::cout << std::endl;
  std::cout << "------------------- " << std::endl << std::endl;
  std::cout << "LINKED LIST OPTIONS: " << std::endl;
  for (size_t idx = 0; idx < LL_OPTIONS.size(); idx++) {
    const char *option = LL_OPTIONS[idx];
    std::cout << idx + 1 << ". " << option << std::endl;
  }
  std::cout << std::endl;
  std::cout << "Enter -1 to quit." << std::endl;
}

auto get_user_option() -> int {
  std::cout << "Enter the index of the option you would like: ";
  std::string user_option_string;
  std::getline(std::cin, user_option_string);
  while (!std::stoi(user_option_string)) {
    std::cout << "Invalid option. Try again: ";
    std::getline(std::cin, user_option_string);
  }

  return std::stoi(user_option_string);
}

auto handle_user_option(DoublyLinkedList<Part> &ll, int user_option_idx)
    -> void {
  switch (user_option_idx) {
  case -2:
    // Quit.
    std::exit(0);
  case 0: {
    // `add_item`
    std::cout << "Enter the Part SKU: ";
    std::string part_sku;
    std::getline(std::cin, part_sku);
    std::cout << "Enter the Part Description: ";
    std::string part_description;
    std::getline(std::cin, part_description);
    std::cout << "Enter the Part Price: ";
    std::string part_price_str;
    std::getline(std::cin, part_price_str);
    double part_price = std::stod(part_price_str);
    std::cout << "Enter the Part UOM: ";
    std::string part_uom;
    std::getline(std::cin, part_uom);

    Part *part_to_add =
        new Part(part_sku, part_description, part_price, part_uom);
    ll.add_item(part_to_add);
    break;
  }
  case 1: {
    // "get_item"
    std::cout << "Enter the Part SKU: ";
    std::string part_sku;
    std::getline(std::cin, part_sku);
    std::cout << "Enter the Part Description: ";
    std::string part_description;
    std::getline(std::cin, part_description);
    std::cout << "Enter the Part Price: ";
    std::string part_price_str;
    std::getline(std::cin, part_price_str);
    double part_price = std::stod(part_price_str);
    std::cout << "Enter the Part UOM: ";
    std::string part_uom;
    std::getline(std::cin, part_uom);

    try {
      Part *part_to_find =
          new Part(part_sku, part_description, part_price, part_uom);
      ll.get_item(part_to_find);
    } catch (ItemNotFound e) {
      std::cout << e.display() << std::endl;
    }
    break;
  }
  case 2: {
    // "is_in_list"
    std::cout << "Enter the Part SKU: ";
    std::string part_sku;
    std::getline(std::cin, part_sku);
    std::cout << "Enter the Part Description: ";
    std::string part_description;
    std::getline(std::cin, part_description);
    std::cout << "Enter the Part Price: ";
    std::string part_price_str;
    std::getline(std::cin, part_price_str);
    double part_price = std::stod(part_price_str);
    std::cout << "Enter the Part UOM: ";
    std::string part_uom;
    std::getline(std::cin, part_uom);

    Part *part_to_find =
        new Part(part_sku, part_description, part_price, part_uom);
    ll.is_in_list(part_to_find);
    break;
  }
  case 3: {
    // "is_empty"
    std::cout << "List is empty: ";
    if (ll.is_empty()) {
      std::cout << "True";
    } else {
      std::cout << "False";
    }
    std::cout << std ::endl;
    break;
  }
  case 4: {
    // "get_size",
    std::cout << "List length: " << ll.get_size() << std::endl;
    break;
  }
  case 5: {
    // "see_next"
    std::cout << "List length: " << ll.see_next() << std::endl;
    break;
  }
  case 6: {
    // "see_prev"
    std::cout << "List length: " << ll.see_prev() << std::endl;
    break;
  }
  case 7: {
    // "see_at"
    std::string idx_to_see_at_str;
    std::cout << "Enter the index to peek at: ";
    std::getline(std::cin, idx_to_see_at_str);
    size_t idx_to_see_at = std::stod(idx_to_see_at_str);
    try {
      LinkedListNode<Part> *item_at_idx = ll.see_at(idx_to_see_at);
      std::cout << "List element at " << idx_to_see_at << " = "
                << item_at_idx->get_value()->GetPartInfo() << std::endl;
    } catch (OutOfBoundsError e) {
      std::cout << e.display();
    }
    break;
  }
  case 8: {
    // "reset"
    ll.reset();
    std::cout << "Reset list." << std::endl;
    break;
  }
  };
}
