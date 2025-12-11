#include <bits/stdc++.h>
using namespace std;

int findMax(vector<int> &v)
{
  int maxi = INT_MIN;
  int n = v.size();
  for (int i = 0; i < n; i++)
  {
    maxi = max(maxi, v[i]);
  }
  return maxi;
}

int calculateTotalHours(vector<int> &v, int hourly)
{
  int totalH = 0;
  int n = v.size();
  for (int i = 0; i < n; i++)
  {
    totalH += ceil((double)v[i] / (double)hourly);
  }
  return totalH;
}

int minumumRateToEatBananas(vector<int> v, int h)
{
  int low = 1, high = findMax(v);
  while (low <= high)
  {
    int mid = (low + high) / 2;
    int totalH = calculateTotalHours(v, mid);
    if (totalH <= h)
    {
      high = mid - 1;
    }
    else
    {
      low = mid + 1;
    }
  }
  return low;
}

int main()
{
  vector<int> v = {3, 6, 7, 11};
  int h = 8;
  int result = minumumRateToEatBananas(v, h);
  cout << result;

  return 0;
}

// ye upper vla code leetcode p accept nhi hua to ye chatgpt ka code h niche vla
// class Solution {
// public:
//     int findMax(vector<int> &piles)
//     {
//         int maxi = INT_MIN;
//         for (int x : piles)
//             maxi = max(maxi, x);
//         return maxi;
//     }

//     long long calculateTotalHours(vector<int> &piles, int hourly)
//     {
//         long long totalH = 0;
//         for (int x : piles)
//         {
//             totalH += (x + hourly - 1) / hourly;  // integer ceil
//         }
//         return totalH;
//     }

//     int minEatingSpeed(vector<int>& piles, int h)
//     {
//         int low = 1, high = findMax(piles);

//         while (low <= high)
//         {
//             int mid = low + (high - low) / 2;

//             long long totalH = calculateTotalHours(piles, mid);

//             if (totalH <= h)
//                 high = mid - 1;
//             else
//                 low = mid + 1;
//         }

//         return low;
//     }
// };
