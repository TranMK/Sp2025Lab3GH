#include <iostream>

#include "unit_tests.cpp"

const double little_to_meter = 1.;

void debug_tests();

int main(int argc, char *argv[]) {
  if (argv[1] != NULL && std::string(argv[1]) == "test") {
    debug_tests();
  } else {
    // Run required test.
    double x, y;
    std::cout << "Enter a distance x in meters: ";
    std::cin >> x;
    std::cin.ignore();
    std::cin.clear();
    std::cout << "Enter a distance y in meters: ";
    std::cin >> y;

    double total_x_littles = x / little_to_meter;
    Measurement m_x = Measurement(x);
    double total_y_littles = y / little_to_meter;
    Measurement m_y = Measurement(y);

    std::cout << m_x << std::endl;
    std::cout << m_y << std::endl;

    bool should_stop = false;
    while (!should_stop) {
      std::cout << "What operation would you like to perform on x and y?"
                << std::endl;
      std::cout << "1) Add" << std::endl;
      std::cout << "2) Subtract" << std::endl;
      std::cout << "3) Multiply" << std::endl;
      std::cout << "4) Divide" << std::endl;

      std::cout << "Operation: ";
      size_t operation;
      std::cin >> operation;
      std::cin.ignore();
      std::cin.clear();

      Measurement result = m_x;
      switch (operation) {
      case 1:
        result + m_y;
      case 2:
        result + m_y;
      case 3:
        result * m_y;
      case 4:
        result / m_y;
      }
      std::cout << "Result: " << std::endl << result;

      std::cout << "Do you wish to try another operation? (Y/N): ";
      char user_continue;
      std::cin >> user_continue;
      if (user_continue != 'Y' && user_continue != 'y') {
        should_stop = true;
      }
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
