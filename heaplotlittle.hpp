#include <string>
class Measurement {
private:
  double heaps;
  double lots;
  double littles;

public:
  // Constructors.
  Measurement();
  Measurement(double heaps, double lots, double littles);
  Measurement(double littles);

  // Getters.
  double get_heaps() { return heaps; }
  double get_lots() { return lots; }
  double get_littles() { return littles; }

  // Setters.
  void set_heaps(double heaps) { this->heaps = heaps; }
  void set_lots(double lots) { this->lots = lots; }
  void set_littles(double littles) { this->littles = littles; }

  // Overloads.
  void operator+(Measurement other);
  void operator-(Measurement other);
  void operator*(Measurement other);
  void operator/(Measurement other);
  bool operator==(Measurement other);

  // Convenience.
  std::string to_str();
  void rebalance();
};
