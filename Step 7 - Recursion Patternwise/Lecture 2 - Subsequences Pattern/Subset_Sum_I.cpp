#include <bits/stdc++.h>
using namespace std;

void func(int ind, int sum, vector<int> &arr, int N, vector<int> &sumSubset)
{
  if (ind == N)
  {
    sumSubset.push_back(sum);
    return;
  }

  // pick the element
  func(ind + 1, sum + arr[ind], arr, N, sumSubset);

  // not pick the element
  func(ind + 1, sum, arr, N, sumSubset);
}

vector<int> subsetSum(vector<int> arr, int N)
{
  vector<int> subsetSum;
  func(0, 0, arr, N, subsetSum);
  sort(subsetSum.begin(), subsetSum.end());
  return subsetSum;
}

int main()
{
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  vector<int> result = subsetSum(arr, n);
  for (auto &sum : result)
  {
    cout << sum << " ";
  }
  return 0;
}