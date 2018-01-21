#include <iostream>

#include "date.hh"

int main()
{
  Date a(2016,8,25);
  Date b(2016, 6,30);
  Date c(2015,13,2);

  std::cout << "Date a = " << a << " is " << (a.valid() ? "valid" : "not valid") << std::endl;
  std::cout << "Date b = " << b << " is " << (b.valid() ? "valid" : "not valid") << std::endl;
  std::cout << "Date c = " << c << " is " << (c.valid() ? "valid" : "not valid") << std::endl;

  std::cout << std::endl;

  int daysToAdd = 26;
  int monthsToAdd = 2;
  int yearsToAdd = 1;

  std::cout << a << " + " << daysToAdd << " days = ";
  a.addDays(daysToAdd);
  std::cout << a << std::endl;

  std::cout << a << " + " << monthsToAdd << " months = ";
  a.addMonths(monthsToAdd);
  std::cout << a << std::endl;

  std::cout << a << " + " << yearsToAdd << " year = ";
  a.addYears(yearsToAdd);
  std::cout << a << std::endl;

  std::cout << "Days between " << a << " and " << b << " = " << a.daysAfter(b);
  

  std::cout << std::endl;
  return 0;
}