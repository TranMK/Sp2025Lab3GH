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
  std::cout << std::setw(21) << " Price: $" << Price << UOM << std::endl;
  std::cout << std::setw(21) << " Quantity on Hand: " << QuantityOnHand
            << std::endl;
  if (!QuantityOnHand) {
    std::cout << std::fixed << std::setprecision(2);
    std::cout << std::setw(21) << "Lead Time: " << LeadTime << std::endl;
  }
  std::cout << "**************************************" << std::endl;
}

auto Part::operator<(Part other) -> bool {
  std::string desc = other.GetPartInfo();
  std::string SKU2;
  while (desc[0] != '\n') {
    SKU2.push_back(desc[0]);
    desc.erase(0, 1);
  }
  return SKU < SKU2;
}

auto Part::operator>(Part other) -> bool {
  std::string desc = other.GetPartInfo();
  std::string SKU2;
  while (desc[0] != '\n') {
    SKU2.push_back(desc[0]);
    desc.erase(0, 1);
  }
  return SKU > SKU2;
}

auto Part::operator==(Part other) -> bool {
  std::string desc = other.GetPartInfo();
  std::string SKU2;
  while (desc[0] != '\n') {
    SKU2.push_back(desc[0]);
    desc.erase(0, 1);
  }
  return SKU == SKU2;
}
