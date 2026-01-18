#include <bits/stdc++.h>
using namespace std;

void findCombination(int ind, int target, vector<int> &arr,
                     vector<vector<int>> &ans, vector<int> &ds)
{
  if (ind == arr.size())
  {
    if (target == 0)
    {
      ans.push_back(ds);
    }
    return;
  }

  if (arr[ind] <= target)
  {
    ds.push_back(arr[ind]);
    findCombination(ind, target - arr[ind], arr, ans, ds);
    ds.pop_back();
  }
  findCombination(ind + 1, target, arr, ans, ds);
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
  vector<vector<int>> ans;
  vector<int> ds;
  findCombination(0, target, candidates, ans, ds);
  return ans;
}

int main()
{
  int n, target;
  cin >> n;
  vector<int> candidates(n);
  for (int i = 0; i < n; i++)
  {
    cin >> candidates[i];
  }
  cin >> target;
  vector<vector<int>> result = combinationSum(candidates, target);
  for (auto &v : result)
  {
    for (auto &num : v)
    {
      cout << num << " ";
    }
    cout << endl;
  }
  return 0;
}