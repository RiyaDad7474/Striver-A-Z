#include <bits/stdc++.h>
using namespace std;

list<int> primeFactors(int n)
{
  list<int> li;

  for (int i = 2; i <= sqrt(n); i++)
  {
    if (n % i == 0)
    {
      li.push_back(i);
    }

    while (n % i == 0)
    {
      n = n / i;
    }
  }

  if (n > 1) // last prime factor
  {
    li.push_back(n);
  }

  return li;
}

int main()
{
  int n;
  cin >> n;

  list<int> result = primeFactors(n);

  for (int x : result)
  {
    cout << x << " ";
  }

  return 0;
}