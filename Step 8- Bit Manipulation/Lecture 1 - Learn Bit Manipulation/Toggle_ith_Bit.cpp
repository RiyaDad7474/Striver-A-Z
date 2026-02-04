#include <bits/stdc++.h>
using namespace std;

int toggleIthBit(int n, int i)
{
  return (n ^ (1 << i));
}

int main()
{
  int n, i;
  cin >> n >> i;
  cout << toggleIthBit(n, i) << endl;
  return 0;
}