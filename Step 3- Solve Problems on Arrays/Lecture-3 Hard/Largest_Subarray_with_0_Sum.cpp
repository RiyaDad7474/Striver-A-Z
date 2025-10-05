#include <bits/stdc++.h>
using namespace std;

int maxLen(int A[], int n)
{
  unordered_map<int, int> mpp;
  int maxi = 0;
  int sum = 0;
  for (int i = 0; i < n; i++)
  {
    sum += A[i];
    if (sum == 0)
    {
      maxi = i + 1;
    }
    else
    {
      if (mpp.find(sum) != mpp.end())
      {
        maxi = max(maxi, i - mpp[sum]);
      }
      else
      {
        mpp[sum] = i;
      }
    }
  }
  return maxi;
}
int main()
{
  int A[] = {2, -2, 4, 8, -8, -4, 5, 3, 6};
  int n = sizeof(A) / sizeof(A[0]);
  cout << maxLen(A, n) << endl;

  return 0;
}