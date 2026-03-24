#include <bits/stdc++.h>
using namespace std;

int helper(vector<int> &nums, int k)
{
  if (k < 0)
    return 0;

  int l = 0, r = 0, sum = 0, count = 0;

  while (r < nums.size())
  {
    sum += (nums[r] % 2);
    while (sum > k)
    {
      sum = sum - (nums[l] % 2);
      l = l + 1;
    }
    count = count + (r - l + 1);
    r = r + 1;
  }
  return count;
}

int numberOfSubarrays(vector<int> &nums, int k)
{

  return helper(nums, k) - helper(nums, k - 1);
}

int main()
{
  vector<int> nums = {1, 1, 0, 1, 1};
  int k;
  cin >> k;
  cout << numberOfSubarrays(nums, k);
  return 0;
}