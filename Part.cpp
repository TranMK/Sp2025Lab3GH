#include <iomanip>
#include <iostream>

#include "Part.hpp"

auto Part::Available(double date) -> bool {
  // Unconditionally true if there's quantity on hand.
  return GetQuantityOnHand();
  // Else, compares date to LeadTime.
  if (date > LeadTime) {
    LeadTime += date;
    return true;
  }
  return false;
}

auto Part::Display() -> void {
  std::cout << "**************************************" << std::endl;
  std::cout << "           Part Information           " << std::endl;
  std::cout << std::setw(21) << " SKU: " << SKU << std::endl;
  std::cout << std::setw(21) << " Description: " << Description << std::endl;
  std::cout << std::setw(21) << " Price: $" << Price << std::endl;
  std::cout << std::setw(21) << " Quantity on Hand: " << QuantityOnHand
            << std::endl;
  if (QuantityOnHand == 0) {
    std::cout << std::fixed << std::setprecision(2);
    std::cout << std::setw(21) << "Lead Time: " << LeadTime << std::endl;
  }
  std::cout << std::setw(21) << " UOM: " << UOM << std::endl;
  std::cout << "**************************************" << std::endl;
}
