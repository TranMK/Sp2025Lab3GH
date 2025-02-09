#include <iostream>

#include "unit_tests.cpp"

const double little_to_meter = 1.;

void debug_tests();

int main(int argc, char *argv[]) {
  if (argv[1] != NULL && std::string(argv[1]) == "test") {
    debug_tests();
    return 0;
  }
  // Run required test.
  std::string x_i, y_i;
  std::cout << "Enter a distance x in meters: ";
  std::getline(std::cin, x_i);
  std::cout << "Enter a distance y in meters: ";
  std::getline(std::cin, y_i);

  double x, y;
  x = std::stod(x_i);
  y = std::stod(y_i);
  double total_x_littles = x / little_to_meter;
  double total_y_littles = y / little_to_meter;
  Measurement m_x = Measurement(x);
  Measurement m_y = Measurement(y);

  bool should_stop = false;
  while (!should_stop) {
    std::cout << "What operation would you like to perform on x and y?"
              << std::endl;
    std::cout << "1) Add" << std::endl;
    std::cout << "2) Subtract" << std::endl;
    std::cout << "3) Multiply" << std::endl;
    std::cout << "4) Divide" << std::endl;

    std::cout << "Operation: ";
    std::string operation_selection;
    std::getline(std::cin, operation_selection);
    int operation = std::stoi(operation_selection);

    Measurement result = m_x;
    switch (operation) {
    case 1:
      result + m_y;
      break;
    case 2:
      result - m_y;
      break;
    case 3:
      result *m_y;
      break;
    case 4:
      result / m_y;
      break;
    }

    if (operation != 1 && operation != 2 && operation != 3 && operation != 4)
      std::cout << "Invalid operation." << std::endl;
    std::cout << "Result: " << std::endl << result;

    std::cout << "Do you wish to try another operation? (Y/N): ";
    std::string user_continue;
    std::getline(std::cin, user_continue);
    if (user_continue != "Y" && user_continue != "y") {
      should_stop = true;
    }
  }

  return 0;
}

void debug_tests() {
  auto passes = test_suite::run();
  bool failed_any = false;
  for (size_t test_idx = 0; test_idx < passes.size(); test_idx++) {
    auto test_pass = passes[test_idx];
    if (!std::get<0>(test_pass)) {
      // Test failed.
      std::cout << "[Test " << test_idx + 1 << "] failed." << std::endl;
      failed_any = true;
    } else {
      // Test passed.
      std::cout << "[Test " << test_idx + 1 << "] passed." << std::endl;
    }
  }
}
