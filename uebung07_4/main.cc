#include "histogram.hh"
#include "io.hh"

#include <vector>

int main() {

  Histogram hist;

  std::vector<double> randVals = normal_distribution(random_seed(), 2000000, 50, 5);

  for (auto val: randVals)
    hist.insert(val);
  
  hist.print_graphical(8);

  return 0;
}