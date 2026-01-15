#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> subsets(vector<int> &nums)
{
  int n = nums.size();
  int total = 1 << n; // 2^n
  vector<vector<int>> ans;

  for (int mask = 0; mask < total; mask++)
  {
    vector<int> temp;
    for (int i = 0; i < n; i++)
    {
      if (mask & (1 << i))
      {
        temp.push_back(nums[i]);
      }
    }
    ans.push_back(temp);
  }
  return ans;
}

int main()
{
  vector<int> nums = {1, 2, 3};

  vector<vector<int>> result = subsets(nums);

  for (auto &subset : result)
  {
    cout << "[ ";
    for (int x : subset)
    {
      cout << x << " ";
    }
    cout << "]\n";
  }

  return 0;
}
