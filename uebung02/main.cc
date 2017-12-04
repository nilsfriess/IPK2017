
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int parse_int(string);
bool is_Number(char);

int main(){
  string numString = "";

  cout << "Enter a number: ";
  getline(cin, numString);
 
  int parsedNum = parse_int(numString);

  cout << "'" << numString << "' = " << parsedNum;

  cout << endl << endl; 

  getline(cin, numString);
  return 0;
}

int parse_int(string number)
{
  int size = number.size();
  int retNum = 0;
  int sign = 1;

  // startAt -1, when no spaces are found, startAt will be 0
  int startAt = -1;

  // ignore spaces at beginning of string
  while(number[++startAt] == ' ');

  for (int i=startAt; i<size; i++) 
  {
    if (!is_Number(number[i]) && number[i] != '+' && number[i] != '-') 
    {
      throw invalid_argument("Number must not begin with a character other than 0-9, + or -");
    }
    if (is_Number(number[i]))
      break;
  }

  if (number[startAt] == '-') 
  {
    startAt++;
    sign = -1;
  } else if(number[startAt] == '+') {
    startAt++;
  }

  //count characters that are not numbers
  int nonNumbers = 0;
  for (int i=startAt; i<size; i++) 
    if (!is_Number(number[i]))
      nonNumbers++;
  size -= nonNumbers;

  // ignore whitespace and signs at beginning of the string
  // ignore characters that are not numbers at the end of the string
  for ( int i=startAt; i < size ; i++)
  {
    int currentNum = number[i] - '0';

    //cout << currentNum << endl;

    //1234 = 1*10^3 + 2*10^2 + 3*10^1 + 4*10^0
    retNum += currentNum * pow(10, size - 1 - i);
  }

  return sign * retNum;
}

bool is_Number(char c)
{
  return c >= '0' && c <= '9';
}
