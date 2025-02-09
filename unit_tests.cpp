#include <vector>

#include "heaplotlittle.hpp"

namespace test_suite {
bool test_1();
bool test_2();

std::vector<std::tuple<size_t, bool>> run() {
  // Custom unit tests.
  std::vector<std::tuple<size_t, bool>> passes(2, {false, 1});
  passes[0] = {test_1(), 1};
  passes[1] = {test_2(), 2};

  return passes;
}

// Addition.
bool test_1() {
  auto m_1 = Measurement(162);
  auto m_2 = Measurement(0, 0, 6);
  m_1 + m_2; // Assigns to `m_1`
  auto expected = Measurement(1, 1, 0);

  return m_1 == expected;
}

// Rebalancing upon construction.
bool test_2() {
  auto m_1 = Measurement(2, 23, 0);
  auto expected = Measurement(3, 0, 0);

  return m_1 == expected;
}
} // namespace test_suite
