#include "histogram.hh"

#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>
#include <iostream>

void Histogram::insert(double x) { this->_values.push_back(x); }

double Histogram::min() const {
  return *std::min_element(this->_values.begin(), this->_values.end());
}
double Histogram::max() const {
  return *std::max_element(this->_values.begin(), this->_values.end());
}

std::pair<double, double>
Histogram::calcInterval(double min, double max, int intervalNum, int numBins) {
  double lowerBound = min + (intervalNum - 1) * ((max - min) / numBins);
  double upperBound = min + intervalNum * ((max - min) / numBins);
  return std::make_pair(lowerBound, upperBound);
}

void Histogram::print(unsigned int bin_count) {
  std::cout << "Histogram of " << this->size() << " entries, "
            << "min = " << this->min() << ", "
            << "max = " << this->max() << std::endl;

  std::vector<std::pair<double, double>> intervals(bin_count);

  for (unsigned int i = 0; i < bin_count; i++) {
    intervals[i] = calcInterval(this->min(), this->max(), i + 1, bin_count);
  }

  for (auto interval : intervals) {
    std::cout << std::fixed << std::setprecision(2) << interval.first << " -- "
              << interval.second << ": ";

    std::cout << getNumOfValsInInterval(interval);

    std::cout << std::endl;
  }

  std::cout << std::endl;
}

void Histogram::print_normalized(unsigned int bin_count) {
  std::cout << "Normalized histogram of " << this->size() << " entries, "
            << "min = " << this->min() << ", "
            << "max = " << this->max() << std::endl;

  std::vector<std::pair<double, double>> intervals(bin_count);

  for (unsigned int i = 0; i < bin_count; i++) {
    intervals[i] = calcInterval(this->min(), this->max(), i + 1, bin_count);
  }

  for (auto interval : intervals) {
    std::cout << std::fixed << std::setprecision(2) << interval.first << " -- "
              << interval.second << ": ";

    std::cout << static_cast<double>(getNumOfValsInInterval(interval)) /
                     static_cast<double>(this->size()) * 100
              << "%";

    std::cout << std::endl;
  }

  std::cout << std::endl;
}

void Histogram::print_graphical(unsigned int bin_count) {
  std::cout << "Normalized histogram of " << this->size() << " entries, "
            << "min = " << this->min() << ", "
            << "max = " << this->max() << std::endl;

  std::vector<std::pair<double, double>> intervals(bin_count);

  for (unsigned int i = 0; i < bin_count; i++) {
    intervals[i] = calcInterval(this->min(), this->max(), i + 1, bin_count);
  }

  for (auto interval : intervals) {
    std::cout << std::fixed << std::setprecision(2) << interval.first << " -- "
              << interval.second << ": ";

    double perc = static_cast<double>(getNumOfValsInInterval(interval)) /
                  static_cast<double>(this->size());

    int width = static_cast<int>(std::ceil(40.0 * perc));

    std::cout << std::setfill(' ');
    std::cout << std::setw(40) << std::left;

    std::string stars;

    for (int i = 0; i < width; i++)
      stars += "*";

    std::cout << stars;
    std::cout << perc;

    std::cout << std::endl;
  }

  std::cout << std::endl;
}

long unsigned int
Histogram::getNumOfValsInInterval(std::pair<double, double> interval) {
  std::vector<double> vals;

  for (auto val : this->_values)
    if (val >= interval.first && val < interval.second)
      vals.push_back(val);

  return vals.size();
}