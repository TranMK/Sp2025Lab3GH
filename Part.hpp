#include <cstddef>
#include <string>
#include <utility>

#pragma once

class Part {
  std::string SKU;
  std::string Description;
  double Price;
  std::string UOM;
  size_t QuantityOnHand;
  size_t LeadTime;

public:
  Part() = default;
  Part(std::string SKU, std::string Description, double Price, std::string UOM,
       int QuantityOnHand, size_t LeadTime)
      : SKU(std::move(SKU)), Description(std::move(Description)),
        Price(std::move(Price)), UOM(std::move(UOM)),
        QuantityOnHand(std::move(QuantityOnHand)),
        LeadTime(std::move(LeadTime)) {};

  auto GetPartInfo() -> std::string {
    return "SKU: " + SKU + "\n" + "Description: " + Description;
  };
  auto GetSKU() -> std::string { return SKU; };
  auto GetPrice() -> double { return Price; };
  auto GetQuantityOnHand() -> bool { return QuantityOnHand > 0; };
  auto Available(double date) -> bool;
  auto Display() -> void;

  auto operator<(Part other) -> bool { return SKU < other.GetSKU(); }
  auto operator>(Part other) -> bool { return SKU > other.GetSKU(); }
  auto operator==(Part other) -> bool { return SKU == other.GetSKU(); }
};
