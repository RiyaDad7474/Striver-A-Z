#include <bits/stdc++.h>
using namespace std;

// Recurrsive Bruteforce Approach
// int f(int idx, vector<int> &nums, int jumps)
// {
//   int n = nums.size();

//   if (idx >= n - 1)
//     return jumps;

//   int mini = INT_MAX;
//   for (int i = 1; i <= nums[idx]; i++)
//   {
//     mini = min(mini, f(idx + i, nums, jumps + 1));
//   }
//   return mini;
// }
// int jump(vector<int> &nums)
// {
//   return f(0, nums, 0);
// }

// Optimal Solution(DP) but not required here so instead this greddy solution is good

int jump(vector<int> &nums)
{
  int n = nums.size();
  int jumps = 0, l = 0, r = 0;

  while (r < n - 1)
  {
    int farthest = 0;
    for (int i = l; i <= r; i++)
    {
      farthest = max(farthest, i + nums[i]);
    }
    l = r + 1;
    r = farthest;
    jumps++;
  }
  return jumps;
}

int main()
{
  vector<int> nums = {2, 3, 1, 1, 4};
  cout << jump(nums);
  return 0;
}