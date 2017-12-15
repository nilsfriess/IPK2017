#ifndef WORD_HH
#define WORD_HH

#include <iostream>
#include <string>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <vector>
#include <utility>

#include "sanitizeword.hh"

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

  for (auto &ch : frequencies) {
    ch.second = static_cast<double>(ch.second) / sum;
  }

  return frequencies;
}

std::map<std::string, int> get_string_frequencies() {
  std::map<std::string, int> frequencies;

  while (true) {
    std::string word;

    std::cin >> word;

    if (not std::cin)
      break;

    word = sanitize_word(word);

    if( word.size() != 0) {
      frequencies[word]++;
    }      
  }

  return frequencies;
}

std::unordered_map<std::string, int> get_string_frequencies_unordered() {
  std::unordered_map<std::string, int> frequencies;

  while (true) {
    std::string word;

    std::cin >> word;

    if (not std::cin)
      break;

    word = sanitize_word(word);

    if( word.size() != 0) {
      frequencies[word]++;
    }      
  }

  return frequencies;
}

template <typename T>
void print_frequencies(const std::map<T, double> &frequencies) {
  for (auto ch : frequencies) {
    std::cout << ch.first << ": " << (ch.second * 100) << "%" << std::endl;
  }
}

template <typename T>
void print_frequencies(const std::map<T, int> &frequencies) {
  for (auto ch : frequencies) {
    std::cout << ch.first << ": " << (ch.second) << std::endl;
  }
}

template <typename Map>
void print_frequencies_sorted(const Map& map) {
  std::vector<std::pair<typename Map::key_type, typename Map::mapped_type>> sortVector;

  double sum = 0;

  for (auto entry: map) {
    sortVector.push_back(std::make_pair(entry.first, entry.second));
    sum += entry.second;
  }

  std::sort(sortVector.begin(), sortVector.end()
    , [](std::pair<typename Map::key_type, typename Map::mapped_type> p1, std::pair<typename Map::key_type, typename Map::mapped_type> p2) {
      if (p1.second == p2.second)
        return p1.first < p2.first;
      return p1.second >= p2.second;
    });

  for (auto ch : sortVector) {
    std::cout << ch.first << ": " << (ch.second / sum * 100) << "%" << std::endl;
  }
}

#endif // WORD_HH