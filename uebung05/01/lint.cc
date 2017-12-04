
#include <algorithm>
#include <iostream>
#include <stack>
#include <string>

bool is_bracket(char c) {
  return (c == '(') || (c == ')') || (c == '[') || (c == ']') || (c == '{') ||
         (c == '}');
}

bool is_matching_closing_bracket(char open, char close) {
  switch (open) {
  case '(':
    return close == ')';
  case '[':
    return close == ']';
  case '{':
    return close == '}';
  }
  return false;
}

bool is_opening_bracket(char c) {
  return (c == '(') || (c == '[') || (c == '{');
}

/*
    Checks if symbols contains only matching paratheses.
    Returns 0 if all opened parantheses are closed
    Returns 1 if the next closing pracket should be: ')'
    Returns 2 if the next closing pracket should be: ']'
    Returns 3 if the next closing pracket should be: '}'
    Returns 4 if bracket has been closed by wrong bracket
        e.g. ( } or [ ) ...
    Returns 5 if closing bracket has no matching opening bracket
    Prints error message to std:err
*/

int check_parantheses(const std::string &symbols) {

  std::stack<char> parantheses;
  char last_bracket = '-';
  std::string mSymbols = symbols;

  // just used for prettier outputs
  int pos = 1;

  // remove every character that is not any kind of bracket
  mSymbols.erase(std::remove_if(mSymbols.begin(), mSymbols.end(),
                                [](char x) { return !(is_bracket(x)); }),
                 mSymbols.end());

  for (auto &symbol : mSymbols) {
    pos++;

    // debug: std::cout << "last " << last_bracket << ", current " << symbol <<
    // ", total on stack " << parantheses.size() << std::endl;

    // push opening brackets to the stack
    // will be removed, if the following bracket closes this one
    if (is_opening_bracket(symbol)) {
      parantheses.push(symbol);
    } else // current symbol == closing bracket
    {
      if (last_bracket == '-') { // means the stack is empty, so there is an opening bracket missing
        std::cerr << "\033[1;31m" // terminal color red and bold
                  << "Error in string:'" << symbols << "'"
                  << "\nBrackets only:  '" << mSymbols << "':\033[0m\n"; // reset color and bold
        std::cerr << "               ";
        while (pos--)
          std::cerr << " ";
        std::cerr << "^\n";

        std::cerr
            << " \nFound closing bracket with no matching opening bracket: "
            << "'" << symbol << "'\n";
        return 5;
      }

      // if we found a matching opening bracket we remove it from the stack and proceed to the next symbol in the string
      if (is_matching_closing_bracket(last_bracket, symbol)) {
        parantheses.pop();
      } else // closing bracket with non matching opening bracket
      {
        std::cerr << "\033[1;31m"
                  << "Error in string:'" << symbols << "'"
                  << "\nBrackets only:  '" << mSymbols << "':\033[0m\n";
        std::cerr << "               ";
        while (pos--)
          std::cerr << " ";
        std::cerr << "^\n";

        std::cerr << " \nExpected closing bracket for '" << last_bracket
                  << "' but got '" << symbol << "'\n";
        return 4;
      }
    }

    if (parantheses.empty())
      last_bracket = '-';
    else
      last_bracket = parantheses.top();
  }


  // the parantheses stack should be empty
  // if not, there is an opening bracket that has not been closed
  // closing brackets, that have not been opened are captured above
  if (!parantheses.empty()) {
    pos += 2;
    last_bracket = parantheses.top();

    std::cerr << "\033[1;31m"
              << "Error in string:'" << symbols << "'"
              << "\nBrackets Only:  '" << mSymbols << "':\033[0m\n";
    std::cerr << "              ";
    while (pos--)
      std::cerr << " ";
    std::cerr << "^\n";

    std::cerr << "Bracket has not been closed: ";
    std::cerr << "'" << last_bracket << "'\n";

    switch (last_bracket) {
    case '(':
      return 1;
    case '[':
      return 2;
    case '{':
      return 3;
    default:
      return 4;
    }
  }
  return 0;
}