#include <bits/stdc++.h>
using namespace std;

void printPrimeFactors(int n)
{
  // Print number of 2s that divide n
  while (n % 2 == 0)
  {
    cout << 2 << " ";
    n = n / 2;
  }

  // n must be odd at this point
  for (int i = 3; i * i <= n; i += 2)
  {
    while (n % i == 0)
    {
      cout << i << " ";
      n = n / i;
    }
  }

  // If n is still greater than 2, then it is prime
  if (n > 2)
    cout << n;
}

int main()
{
  int n;
  cin >> n;
  printPrimeFactors(n);
  return 0;
}
