#include <string>
using namespace std;
#pragma once

class Part{
    std::string SKU;
    std::string Description;
    double Price;
    std::string UOM;
    int QuantityOnHand;
    double LeadTime;

    public:
        Part(std::string SKU, std::string Description, double Price,
             std::string UOM, int QuantityOnHand=0):
             SKU(SKU), Description(Description), Price(Price), UOM(UOM), QuantityOnHand(QuantityOnHand){};
        std::string GetPartInfo(Part){return SKU+"\n"+Description;};
        double GetPrice(){return Price;};
        bool GetQuantityOnHand(){return QuantityOnHand>0;};
        bool Available(double date){};
        auto operator>(Part other)->bool{};
        auto operator<(Part other)->bool{};
        auto operator==(Part other)->bool{};
};