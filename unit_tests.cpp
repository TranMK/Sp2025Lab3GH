#include "heaplotlittle.hpp"

bool test_1();
bool test_2();

namespace test_suite {
bool test_1() {
  auto m_1 = Measurement(161);
  m_1.set_littles(162);
  auto m_2 = Measurement(2, 0, 1);
  m_1 + m_2;
  return m_1 == m_2;
}

bool test_2() {
  auto m_1 = Measurement(2, 7, 0);
  auto m_2 = Measurement(3, 0, 0);
  return m_1 == m_2;
}
} // namespace test_suite
