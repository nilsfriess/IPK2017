#include <iostream>

using namespace std;

int fib(int);

int main()
{
  int n = 0;

  cout << "n = ";
  cin >> n;

  cout << "fibonacci bis " << n << ": ";
  for (int i=0; i<=n; i++)
    cout << fib(i) << " ";

  cout << endl;

  return 0;
}

int fib(int n)
{
  if (n <= 1)
    return n;
  
  return fib(n-1) + fib(n-2);
}