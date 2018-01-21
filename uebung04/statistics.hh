#ifndef STATISTICS_HH
#define STATISTICS_HH

#include <algorithm>
#include <iostream>
#include <cmath>
#include <random>


template <typename IteratorT>
long double mean(const IteratorT &begin, const IteratorT &end)
{
  long double sum = 0;

  for (IteratorT it = begin; it != end; it++)
    sum = sum + *it;

  return sum / std::distance(begin, end);
}

template <typename ContainerT>
long double mean(const ContainerT &container)
{
  return mean(container.begin(), container.end());
}

template <typename ContainerT>
long double median(const ContainerT &container)
{
  auto sort_vector = container;
  std::sort(sort_vector.begin(), sort_vector.end());
  unsigned size = sort_vector.size();

  if (size % 2 == 0)
  {
    return 0.5 * ( sort_vector[size / 2 - 1] + sort_vector[size / 2]);
  }
  else
  {
    return sort_vector[(size + 1) / 2 - 1];
  }
}

template <typename IteratorT>
long double moment(const IteratorT &begin, const IteratorT &end, unsigned int k)
{
  std::vector<typename IteratorT::value_type> tempVec;

  // map over each item. c => c^k
  std::transform(begin, end, std::back_inserter(tempVec),
    [k](const typename IteratorT::value_type num) {
      return std::pow(num, k);
  });  

  return mean(tempVec);
}

template <typename ContainerT>
long double moment(ContainerT &container, unsigned int k)
{
  return moment(container.begin(), container.end(), k);
}

template <typename IteratorT>
long double standard_deviation(const IteratorT &begin, const IteratorT &end)
{
  auto m = mean(begin, end);

  std::vector<typename IteratorT::value_type> tempVec;

  // map over each item. c => (c - mean)^2
  std::transform(begin, end, std::back_inserter(tempVec),
    [m](const typename IteratorT::value_type num) {
      return std::pow(num - m, 2);
  });

  return std::sqrt(mean(tempVec));
}

template <typename ContainerT>
long double standard_deviation(const ContainerT &container)
{
  return standard_deviation(container.begin(), container.end());
}

template <typename ContainerT, typename DistributionT>
void fill_random(int seed, DistributionT &dist, ContainerT &container)
{
  std::mt19937_64 rng(seed);
  for (auto& c : container)
    c = dist(rng);
}

#endif