#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int> &nums, int target)
{
  int n = nums.size();
  vector<vector<int>> ans;
  sort(nums.begin(), nums.end());
  for (int i = 0; i < n; i++)
  {
    if (i > 0 && nums[i] == nums[i - 1])
      continue;
    for (int j = i + 1; j < n; j++)
    {
      if (j != i + 1 && nums[j] == nums[j - 1])
        continue;
      int k = j + 1;
      int l = n - 1;
      while (k < l)
      {
        long long sum = nums[i];
        sum = sum + nums[j];
        sum = sum + nums[k];
        sum = sum + nums[l];
        if (sum == target)
        {
          vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
          ans.push_back(temp);
          k++;
          l--;
          while (k < l && nums[k] == nums[k - 1])
            k++;
          while (k < l && nums[l] == nums[l + 1])
            l--;
        }
        else if (sum < target)
          k++;
        else
          l--;
      }
    }
  }
  return ans;
}

int main()
{
  vector<int> nums = {1, 1, 1, 2, 2, 2, 4, 4, 4, 6, 6, 6, 7, 7};

  int target = 10;

  vector<vector<int>> res = fourSum(nums, target);

  for (int i = 0; i < res.size(); i++)
  {
    for (int j = 0; j < res[i].size(); j++)
    {
      cout << res[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}