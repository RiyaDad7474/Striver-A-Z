#include <bits/stdc++.h>
using namespace std;

int xorTillN(int n)
{
  if (n % 4 == 0)
    return n;
  else if (n % 4 == 1)
    return 1;
  else if (n % 4 == 2)
    return n + 1;
  else if (n % 4 == 3)
    return 0;
  else
    return n;

  return 0;
}

int xorRange(int L, int R)
{
  return xorTillN(R) ^ xorTillN(L - 1);
}

int main()
{
  int L, R;
  cin >> L >> R;
  cout << xorRange(L, R);
  return 0;
}