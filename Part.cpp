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

auto Part::operator<(Part other) -> bool {
  std::string desc = GetPartInfo(other);
  std::string SKU2;
  while (desc[0] != '\n') {
    SKU2.push_back(desc[0]);
    desc.erase(0, 1);
  }
  return SKU < SKU2;
}

auto Part::operator>(Part other) -> bool {
  std::string desc = GetPartInfo(other);
  std::string SKU2;
  while (desc[0] != '\n') {
    SKU2.push_back(desc[0]);
    desc.erase(0, 1);
  }
  return SKU > SKU2;
}

auto Part::operator==(Part other) -> bool {
  std::string desc = GetPartInfo(other);
  std::string SKU2;
  while (desc[0] != '\n') {
    SKU2.push_back(desc[0]);
    desc.erase(0, 1);
  }
  return SKU == SKU2;
}
