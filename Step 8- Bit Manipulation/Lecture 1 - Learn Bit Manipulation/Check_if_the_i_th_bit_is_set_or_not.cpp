#include <bits/stdc++.h>
using namespace std;

int isIthBitSet(int n, int i)
{
  if (n & (1 << i))
  {
    return 1; // ith bit is set
  }
  else if ((n >> i) & 1 == 0)
  {
    return 0; // ith bit is not set
  }
  else
  {
    return 0; // ith bit is not set
  }
}

int main()
{
  int n, i;
  cin >> n >> i;
  cout << isIthBitSet(n, i) << endl;
  return 0;
}