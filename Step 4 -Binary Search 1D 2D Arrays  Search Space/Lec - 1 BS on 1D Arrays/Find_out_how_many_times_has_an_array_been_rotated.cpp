#include <bits/stdc++.h>
using namespace std;

int findKRotation(const vector<int> &nums)
{
  int n = nums.size();
  if (n == 0)
    return 0; // or some invalid marker
  int low = 0, high = n - 1;

  // If the array is already sorted (no rotation) then minimum is at index 0
  if (nums[low] <= nums[high])
  {
    return 0;
  }

  // Binary search for pivot (smallest element)
  while (low < high)
  {
    int mid = low + (high - low) / 2;

    if (nums[mid] > nums[high])
    {
      // min is in right half (mid+1 … high)
      low = mid + 1;
    }
    else
    {
      // nums[mid] <= nums[high] ⇒ min is at mid or in left half (low … mid)
      high = mid;
    }
  }

  // At the end low == high, pointing to index of minimum element
  return low;
}

int main()
{
  vector<int> nums = {4, 5, 6, 7, 0, 1, 2, 3};
  int ans = findKRotation(nums);
  cout << "The array is rotated " << ans << " times.\n";
  return 0;
}