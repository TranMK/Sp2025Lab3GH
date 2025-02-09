#include <iostream>
#include <vector>

#include "heaplotlittle.hpp"

namespace test_suite {
bool test_1();
bool test_2();
bool test_3();
bool test_4();
bool test_5();

std::vector<std::tuple<size_t, bool>> run() {
  std::vector<std::tuple<size_t, bool>> passes(5, {false, 1});
  // Custom unit tests.
  passes[0] = {test_1(), 1};
  passes[1] = {test_2(), 2};
  passes[2] = {test_3(), 3};
  passes[3] = {test_4(), 4};
  passes[4] = {test_5(), 5};

  return passes;
}

// Addition.
bool test_1() {
  auto m_1 = Measurement(162);          // 1, 0, 1
  auto m_2 = Measurement(0, 0, 6);      // 0, 0, 6
  m_1 + m_2;                            // Assigns to `m_1` = 1, 0, 7
  auto expected = Measurement(1, 1, 0); // 1, 1, 0

  return m_1 == expected;
}

// Rebalancing upon construction.
bool test_2() {
  auto m_1 = Measurement(2, 23, 0);
  auto expected = Measurement(3, 0, 0);

  return m_1 == expected;
}

// Addition.
bool test_3() {
  auto m_1 = Measurement(1);
  auto m_2 = Measurement(6);
  m_1 + m_2;
  auto expected = Measurement(0, 1, 0); // 1, 1, 0

  return m_1 == expected;
}

bool test_4() {
  auto m_1 = Measurement(40);
  auto m_2 = Measurement(3);
  m_1 * m_2;
  auto expected = Measurement(0, 17, 1); // 1, 1, 0

  return m_1 == expected;
}

bool test_5() {
  auto m_1 = Measurement(15);
  auto m_2 = Measurement(3);
  m_1 / m_2;
  auto expected = Measurement(0, 0, 5); // 1, 1, 0

  return m_1 == expected;
}
} // namespace test_suite
