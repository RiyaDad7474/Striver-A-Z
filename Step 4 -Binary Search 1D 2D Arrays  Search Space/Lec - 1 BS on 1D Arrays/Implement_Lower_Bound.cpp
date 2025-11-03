#include <bits/stdc++.h>
using namespace std;

int lowerBound(const vector<int> &arr, int n, int x)
{
  int low = 0, high = n - 1;
  int ans = n;
  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    if (arr[mid] >= x)
    {
      ans = mid;
      high = mid - 1;
    }
    else
    {
      low = mid + 1;
    }
  }
  return ans;
}

// lb = lower_bound(arr.begin(), arr.end(), n) - arr.begin();

int main()
{
  vector<int> arr = {1, 2, 4, 7, 7, 9};
  int x = 7;
  int n = arr.size();
  int result = lowerBound(arr, n, x);
  cout << "lower bound index for " << x << " is " << result;
  return 0;
}
