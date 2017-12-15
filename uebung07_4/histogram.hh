#ifndef HISTOGRAM_HH
#define HISTOGRAM_HH

#include <vector>

class Histogram {
public:
  Histogram() = default;

  void insert(double x);

  unsigned int size();

  double min() const;
  double max() const;

  void print(unsigned int bin_count);

private:
  std::vector<double> values;
};

#endif // HISTOGRAM_HH