#ifndef WORD_HH
#define WORD_HH

#include <iostream>
#include <map>

std::map<char, double> get_frequencies() {
  std::map<char, double> frequencies;
  double sum = 0;

  while (true) {
    unsigned char c;

    std::cin >> c;

    if (not std::cin)
      break;

    c = static_cast<char>(std::toupper(c));

    if (std::isalpha(c))
      frequencies[c]++;
  }

  for (auto ch : frequencies)
    sum += ch.second;

  for (auto &ch: frequencies) {
    ch.second = static_cast<double>(ch.second) / sum;
  }

  return frequencies;
}

template <typename T>
void print_frequencies(const std::map<T, double> &frequencies) {
  for (auto ch : frequencies) {
    std::cout << ch.first << ": " << (ch.second * 100) << "%" << std::endl;
  }
}

#endif // WORD_HH