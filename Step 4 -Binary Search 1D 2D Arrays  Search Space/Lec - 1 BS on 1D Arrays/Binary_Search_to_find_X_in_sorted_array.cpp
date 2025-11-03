#include <bits/stdc++.h>
using namespace std;

int bsRecursive(const vector<int> &nums, int low, int high, int target)
{
  if (low > high)
    return -1;
  int mid = low + (high - low) / 2;
  if (nums[mid] == target)
    return mid;
  else if (nums[mid] < target)
    return bsRecursive(nums, mid + 1, high, target);
  else
    return bsRecursive(nums, low, mid - 1, target);
}

int searchIterative(const vector<int> &nums, int target)
{
  int n = nums.size();
  int low = 0, high = n - 1;
  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    if (nums[mid] == target)
      return mid;
    else if (nums[mid] < target)
      low = mid + 1;
    else
      high = mid - 1;
  }
  return -1;
}

int main()
{
  vector<int> nums = {1, 2, 4, 7, 9};
  int target = 4;

  // Choose one:
  int result1 = searchIterative(nums, target);
  cout << "Iterative: index = " << result1 << "\n";

  int result2 = bsRecursive(nums, 0, nums.size() - 1, target);
  cout << "Recursive: index = " << result2 << "\n";

  return 0;
}
