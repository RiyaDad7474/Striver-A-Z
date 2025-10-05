#include <bits/stdc++.h>
using namespace std;

int upperBound(vector<int> arr, int n, int x)
{
  int low = 0, high = n - 1;
  int ans = n;
  while (low <= high)
  {
    int mid = (low + high) / 2;
    // maybe an answer
    if (arr[mid] > x)
    {
      // look for more small index on left
      high = mid - 1;
    }
    else
    {
      low = mid + 1; // look for right
    }
  }
  return ans;
}

// ub = upper_bound(arr.begin(), arr.end(), n) - arr.begin();