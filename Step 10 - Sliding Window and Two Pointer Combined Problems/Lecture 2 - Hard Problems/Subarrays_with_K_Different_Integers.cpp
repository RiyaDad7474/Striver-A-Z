#include <bits/stdc++.h>
using namespace std;

// Bruteforce solution
// int subarraysWithKDistinct(vector<int> &nums, int k)
// {
//   int count = 0;
//   for (int i = 0; i < nums.size(); i++)
//   {
//     unordered_map<int, int> mpp;

//     for (int j = i; j < nums.size(); j++)
//     {
//       mpp[nums[j]]++;

//       if (mpp.size() == k)
//       {
//         count++;
//       }
//       else if (mpp.size() > k)
//         break;
//     }
//   }
//   return count;
// }

// Optimal Solution
int atMostK(vector<int> &nums, int k)
{
  int l = 0, count = 0;
  unordered_map<int, int> mpp;

  for (int r = 0; r < nums.size(); r++)
  {
    mpp[nums[r]]++;

    while (mpp.size() > k)
    {
      mpp[nums[l]]--;
      if (mpp[nums[l]] == 0)
        mpp.erase(nums[l]);
      l++;
    }

    count += (r - l + 1);
  }
  return count;
}

int subarraysWithKDistinct(vector<int> &nums, int k)
{
  return atMostK(nums, k) - atMostK(nums, k - 1);
}

int main()
{
  vector<int> nums = {1, 2, 1, 2, 3};
  int k;
  cin >> k;
  cout << subarraysWithKDistinct(nums, k);
  return 0;
}