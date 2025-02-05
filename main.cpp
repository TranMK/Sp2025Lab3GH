#include <iostream>

#include "heaplotlittle.hpp"

int main(void) {
  Measurement m_1 = Measurement(230);
  Measurement m_2 = Measurement(1, 9, 6);
  std::cout << (m_1 == m_2) << std::endl;

  return 0;
}
