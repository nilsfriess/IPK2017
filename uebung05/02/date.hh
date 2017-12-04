#ifndef DATE_HH
#define DATE_HH

#include <iostream>

class Date
{
public:
  Date() = default;
  Date(int year, int month, int days)
      : _year(year),
        _month(month),
        _days(days){};

  bool valid() const;

  void addDays(int days);
  void addMonths(int months);
  void addYears(int years);

  int days() const  { return this->_days; };
  int month() const { return this->_month; };
  int year() const  { return this->_year; };

  int daysAfter(const Date &) const;

  bool isLeapYear() const;

  static int daysOfMonth(int month, bool leapYear);

  bool operator==(const Date& other) const;
  bool operator!=(const Date& other) const;

private:
  int _year = 1970;
  int _month = 1;
  int _days = 1;

  friend std::ostream& operator<<(std::ostream&, const Date&);
};

#endif