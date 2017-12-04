
#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <random>

#include "io.hh"
#include "statistics.hh"

int main()
{
  std::uniform_real_distribution<> dist(1.0, 100.0);
  std::vector<long double> test(100000);
  fill_random(random_seed(), dist, test);

  std::cout << "Mean : " << mean(test.begin(), test.begin()+5) << std::endl;
  std::cout << "Median : " << median(test) << std::endl;
  std::cout << "Moment (k=2) : " << moment(test, 2) << std::endl;
  std::cout << "Standard deviation : " << standard_deviation(test) << std::endl;

  return 0;
}