#ifndef HISTOGRAM_HH
#define HISTOGRAM_HH

#include <vector>
#include <utility>

class Histogram {
public:
  Histogram() = default;

  void insert(double x);

  long unsigned int size() { return _values.size(); }

  double min() const;
  double max() const;

  void print(unsigned int bin_count);
  void print_normalized(unsigned int bin_count);
  void print_graphical(unsigned int bin_count);

private:
  std::vector<double> _values;
  std::pair<double, double> calcInterval(double min, double max, int intervalNum, int numBins);
  long unsigned int getNumOfValsInInterval(std::pair<double, double> interval);
};

#endif // HISTOGRAM_HH