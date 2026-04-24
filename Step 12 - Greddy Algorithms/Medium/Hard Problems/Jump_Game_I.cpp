#include <bits/stdc++.h>
using namespace std;

bool canJump(vector<int> &nums)
{
  int maxLen = 0;

  for (int i = 0; i < nums.size(); i++)
  {
    if (i > maxLen)
      return false;

    maxLen = max(maxLen, i + nums[i]);
  }
  if (maxLen == INT_MIN)
    return false;

  return true;
}

int main()
{
  vector<int> nums = {2, 3, 1, 1, 4};
  cout << canJump(nums);
  return 0;
}