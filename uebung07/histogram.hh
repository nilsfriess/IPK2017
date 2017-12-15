#ifndef HISTOGRAM_HH
#define HISTOGRAM_HH

class Histogram {
public:
  Histogram();

  void insert(double x);

  unsigned int size();

  double min() const;

  double max() const;

  // classify the data into bin_count bins and
  // print the histogram for the data set to stdout
  void print(unsigned int bin_count);
};

#endif // HISTOGRAM_HH