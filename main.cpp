#include <iostream>

#include "heaplotlittle.hpp"

int main(void) {
  Measurement m_1 = Measurement(161);
  std::cout << m_1 << std::endl;
  m_1.set_littles(161);
  std::cout << m_1 << std::endl;

  return 0;
}
