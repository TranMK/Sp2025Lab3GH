#include <cstdlib>
#include <iostream>

#include "unit_tests.cpp"

void debug_tests();

int main(int argc, char* argv[]) {
  if (std::string(argv[1]) == "test") {
    debug_tests();
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
      std::cout << "Test " << test_idx + 1 << " failed." << std::endl;
      failed_any = true;
    } else {
      // Test passed.
      std::cout << "Test " << test_idx + 1 << " passed." << std::endl;
    }
  }

  if (failed_any) {
    std::exit(1);
  };
}
