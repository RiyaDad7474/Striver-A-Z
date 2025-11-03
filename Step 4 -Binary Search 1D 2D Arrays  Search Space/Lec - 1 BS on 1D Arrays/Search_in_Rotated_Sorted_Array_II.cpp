#include <bits/stdc++.h>
using namespace std;

bool searchTarget(const vector<int> &nums, int target)
{
  int low = 0, high = (int)nums.size() - 1;
  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    if (nums[mid] == target)
    {
      return true;
    }
    if (nums[low] == nums[mid] && nums[mid] == nums[high])
    {
      low++;
      high--;
    }
    else if (nums[low] <= nums[mid])
    {
      if (nums[low] <= target && target < nums[mid])
      {
        high = mid - 1;
      }
      else
      {
        low = mid + 1;
      }
    }
    else
    {
      if (nums[mid] < target && target <= nums[high])
      {
        low = mid + 1;
      }
      else
      {
        high = mid - 1;
      }
    }
  }
  return false;
}

int main()
{
  vector<int> nums = {2, 5, 6, 0, 0, 1, 2};
  int target = 0;
  bool found = searchTarget(nums, target);
  cout << (found ? "Target found\n" : "Target not found\n");
  return 0;
}
