
#include "date.hh"

#include <iostream>
#include <iomanip>

bool Date::valid() const
{
  int dom = daysOfMonth(this->_month, this->isLeapYear());

  return (this->month() >= 1 && this->month() <= 12) &&
         (this->days() >= 1 && this->days() <= dom);
}

void Date::addDays(int days)
{
  this->_days += days;
  bool isLeapYear = this->isLeapYear();

  while(this->_days > daysOfMonth(this->_month, isLeapYear)) 
  {
    this->_days -= daysOfMonth(this->_month, isLeapYear);

    this->_month++;
    if (this->_month > 12)
    {
      this->_month = 1;
      this->_year++;
      isLeapYear = this->isLeapYear();
    }
  }
}

void Date::addMonths(int months)
{
  this->_month += months;

  while(this->_month > 12) 
  {
    this->_month -= 12;

    this->_year++;
  }

  bool isLeapYear = this->isLeapYear();
  int dom = daysOfMonth(this->_month, isLeapYear);
  while(this->_days > dom)
    this->_days--;
}

void Date::addYears(int years)
{
  this->_year += years;
}

int Date::daysAfter(const Date &other) const 
{
  Date tempDate = Date(other);

  int daysAdded = 0;
  while((*this) != tempDate)
  {
    tempDate.addDays(1);
    daysAdded++;
  }

  return daysAdded;
} 

bool Date::operator==(const Date& other) const
{
  return (
    this->year() == other.year() &&
    this->month() == other.month() &&
    this->days() == other.days()
  );
}

bool Date::operator!=(const Date& other) const
{
  return !(*this == other);
}

std::ostream& operator<<(std::ostream& out, const Date& date) 
{
  return out << 
    std::setfill('0') << std::setw(2) << date._days << '.' <<
    std::setfill('0') << std::setw(2) << date._month << '.' <<
    date._year;
}

int Date::daysOfMonth(int month, bool leapYear)
{
  switch (month)
  {
  case 1:
  case 3:
  case 5:
  case 7:
  case 8:
  case 10:
  case 12:
    return 31;
  case 4:
  case 6:
  case 9:
  case 11:
    return 30;
  case 2:
    return leapYear ? 29 : 28;
  }

  return 0;
}

bool Date::isLeapYear() const
{
  return this->_year % 4 == 0 && (this->_year % 100 != 0 || this->_year % 400 == 0);
}
