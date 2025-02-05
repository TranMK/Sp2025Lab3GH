#include <iostream>

#include "heaplotlittle.hpp"

int main(void) {
  Measurement m = Measurement(230);
  std::cout << m.get_heaps() << std::endl;
  std::cout << m.get_lots() << std::endl;
  std::cout << m.get_littles() << std::endl;

  return 0;
}
