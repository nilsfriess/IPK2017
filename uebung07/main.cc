
#include "word.hh"

#include <map>
#include <unordered_map>
#include <iostream>

int main() {

  std::map<char, double> frequencies = get_frequencies();

  print_frequencies(frequencies);

  return 0;
}