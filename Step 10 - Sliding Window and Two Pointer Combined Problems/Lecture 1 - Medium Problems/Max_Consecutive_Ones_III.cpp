#include <bits/stdc++.h>
using namespace std;

// Bruteforce Approach
// int longestOnes(vector<int> &nums, int k)
// {
//   int maxlen = 0;

//   for (int i = 0; i < nums.size(); i++)
//   {
//     int zeros = 0;
//     for (int j = i; j < nums.size(); j++)
//     {
//       if (nums[j] == 0)
//       {
//         zeros++;
//       }
//       if (zeros > k)
//       {
//         break;
//       }
//       maxlen = max(maxlen, j - i + 1);
//     }
//   }
//   return maxlen;
// }

// Better Approach
// int longestOnes(vector<int> &nums, int k)
// {
//   int maxlen = 0, l = 0, zeros = 0;

//   for (int r = 0; r < nums.size(); r++)
//   {

//     if (nums[r] == 0)
//     {
//       zeros++;
//     }
//     while (zeros > k)
//     {
//       if (nums[l] == 0)
//       {
//         zeros--;
//       }
//       l++;
//     }
//     maxlen = max(maxlen, r - l + 1);
//   }
//   return maxlen;
// }

// Optimal Approach
int longestOnes(vector<int> &nums, int k)
{
  int l = 0, r = 0, zeros = 0, maxlen = 0;

  while (r < nums.size())
  {
    if (nums[r] == 0)
      zeros++;

    if (zeros > k)
    {
      if (nums[l] == 0)
        zeros--;
      l++;
    }
    if (zeros <= k)
    {
      int len = r - l + 1;
      maxlen = max(maxlen, len);
    }
    r++;
  }
  return maxlen;
}

int main()
{
  int k;
  cin >> k;
  vector<int> nums = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};

  cout << longestOnes(nums, k) << endl;

  return 0;
}