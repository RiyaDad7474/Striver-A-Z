#include <bits/stdc++.h>
using namespace std;

int subarraysWithSumK(vector<int> a, int k)
{
  int xr = 0;
  map<int, int> mpp;
  int cnt = 0;
  mpp[0] = 1;
  for (int i = 0; i < a.size(); i++)
  {
    xr = xr ^ a[i];
    // k
    int x = xr ^ k;
    cnt += mpp[x];
    mpp[xr]++;
  }
  return cnt;
}

int main()
{
  vector<int> a = {1, 2, 3, 2};
  int k = 2;
  cout << subarraysWithSumK(a, k);
  return 0;
}