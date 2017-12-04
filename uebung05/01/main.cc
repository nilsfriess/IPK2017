#include <iostream>

#include "input.hh"
#include "lint.hh"

int main() {
  auto testString = read_stream(std::cin);
  std::cout << std::endl;

  auto is_valid = check_parantheses(testString);

  // std::cout << std::endl << "ret = " << is_valid;

  return is_valid;
}