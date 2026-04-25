#include <bits/stdc++.h>
using namespace std;

struct jobs
{
  int id, profit, dedline;
};

bool comp(jobs val1, jobs val2)
{
  if (val1.profit > val2.profit)
  {
    return true;
  }
  return false;
}

vector<int> seq(jobs arr[], int n)
{

  sort(arr, arr + n, comp);
  int totalP = 0;
  int cnt = 0;
  int maxDeadline = -1;
  for (int i = 0; i < n - 1; i++)
  {
    maxDeadline = max(maxDeadline, arr[i].dedline);
  }

  vector<int> hash(maxDeadline + 1, -1);

  for (int i = 0; i < n; i++)
  {
    for (int j = arr[i].dedline; j > 0; j--)
    {
      if (hash[j] == -1)
      {
        cnt++;
        hash[i] = arr[i].id;
        totalP += arr[i].profit;
        break;
      }
    }
  }
  return {cnt, totalP};
}

int main()
{
  jobs arr[] = {
      {1, 100, 2},
      {2, 19, 1},
      {3, 27, 2},
      {4, 25, 1},
      {5, 15, 3}};
  int n = sizeof(arr) / sizeof(arr[0]);

  vector<int> ans = seq(arr, n);

  cout << "Jobs done: " << ans[0] << endl;
  cout << "Total Profit: " << ans[1] << endl;
  return 0;
}