#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> singleNumber(vector<int> &nums)
  {
    int xorr = 0;

    // Step 1: XOR of all elements
    for (int num : nums)
      xorr ^= num;

    // Step 2: Rightmost set bit
    int diffBit = xorr & (-xorr);

    // Step 3: Divide into two groups
    int a = 0, b = 0;
    for (int num : nums)
    {
      if (num & diffBit)
        a ^= num;
      else
        b ^= num;
    }

    return {a, b};
  }
};

int main()
{
  int n;
  cin >> n;

  vector<int> nums(n);
  for (int i = 0; i < n; i++)
    cin >> nums[i];

  Solution obj;
  vector<int> ans = obj.singleNumber(nums);

  cout << ans[0] << " " << ans[1] << endl;
  return 0;
}
