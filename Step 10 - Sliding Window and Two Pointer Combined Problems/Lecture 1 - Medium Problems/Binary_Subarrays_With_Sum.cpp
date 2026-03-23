#include <bits/stdc++.h>
using namespace std;

int helper(vector<int> &nums, int goal)
{

  if (goal < 0)
    return 0;

  int l = 0, r = 0, sum = 0, count = 0;

  while (r < nums.size())
  {
    sum += nums[r];
    while (sum > goal)
    {
      sum = sum - nums[l];
      l = l + 1;
    }
    count = count + (r - l + 1);
    r = r + 1;
  }
  return count;
}

int numSubarraysWithSum(vector<int> &nums, int goal)
{
  return helper(nums, goal) - helper(nums, goal - 1);
}

int main()
{
  vector<int> nums = {1, 0, 1, 0, 1};
  int goal;
  cin >> goal;
  cout << numSubarraysWithSum(nums, goal);
  return 0;
}