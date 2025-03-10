#include <string>
#include <utility>

#pragma once

class Part {
  std::string SKU;
  std::string Description;
  double Price;
  std::string UOM;
  int QuantityOnHand;
  double LeadTime;

public:
  Part(std::string SKU, std::string Description, double Price, std::string UOM,
       int QuantityOnHand = 0)
      : SKU(std::move(SKU)), Description(std::move(Description)), Price(Price),
        UOM(std::move(UOM)), QuantityOnHand(QuantityOnHand) {};

  auto GetPartInfo(Part) -> std::string { return SKU + "\n" + Description; };
  auto GetPrice() -> double { return Price; };
  auto GetQuantityOnHand() -> bool { return QuantityOnHand > 0; };
  auto Available(double date) -> bool;

  auto operator>(Part other) -> bool;
  auto operator<(Part other) -> bool;
  auto operator==(Part other) -> bool;
};
