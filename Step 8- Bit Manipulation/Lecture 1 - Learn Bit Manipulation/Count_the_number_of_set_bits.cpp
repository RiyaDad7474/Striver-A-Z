#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  int cnt = 0;
  while (n != 0)
  {
    n = n & (n - 1);
    cnt++;
  }
  cout << cnt << endl;

  // for c++ user this is directly available in built in function

  // int ans = __builtin_popcount(n);
  // cout << ans << endl;
  return 0;
}