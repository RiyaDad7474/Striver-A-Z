#include <bits/stdc++.h>
using namespace std;

int floor(vector<long long> arr, long long n, long long x)
{
  int ans = -1;
  int low = 0, high = n - 1;
  while (low <= high)
  {
    int mid = (low + high) / 2;
    if (arr[mid] <= mid)
    {
      ans = arr[mid];
      low = mid + 1;
    }
    else
    {
      high = mid - 1;
    }
  }
  return ans;
}