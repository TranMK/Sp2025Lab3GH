class Measurement {
private:
  double heaps;
  double lots;
  double littles;

public:
  Measurement();
  Measurement(double heaps, double lots, double littles);
  Measurement(double littles);

  double get_heaps() { return heaps; }
  double get_lots() { return lots; }
  double get_littles() { return littles; }
  void set_heaps(double heaps) { this->heaps = heaps; }
  void set_lots(double lots) { this->lots = lots; }
  void set_littles(double littles) { this->littles = littles; }
};
