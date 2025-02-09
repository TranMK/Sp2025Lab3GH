#include <iostream>

#include "unit_tests.cpp"

int main() {
  // Tests.
  std::vector<std::tuple<bool, size_t>> passes(2, {false, 1});
  passes[0] = {test_1(), 1};
  passes[1] = {test_2(), 2};

  // If any test failed.
  for (size_t test_idx = 0; test_idx < passes.size(); test_idx++) {
    auto test_pass = passes[test_idx];
    if (!std::get<0>(test_pass)) {
      std::cout << "Test " << test_idx + 1 << " failed.";
      return 1;
    }
  }

  return 0;
}
