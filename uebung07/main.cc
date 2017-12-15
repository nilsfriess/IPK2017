
#include "word.hh"

#include <map>
#include <unordered_map>
#include <iostream>
#include <string>

int main() {

  std::map<char, double> frequencies = get_frequencies();

  print_frequencies_sorted(frequencies);

  return 0;
}