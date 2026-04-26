#include <bits/stdc++.h>
using namespace std;

// tc -> O(NlogN)+N
// sc ->O(1)

bool comparator(vector<int> &val1, vector<int> &val2)
{
  return (val1[1] < val2[1]);
}

int eraseOverlapIntervals(vector<vector<int>> &intervals)
{
  if (intervals.empty())
    return 0;

  sort(intervals.begin(), intervals.end(), comparator);

  int cnt = 1;
  int lastEndTime = intervals[0][1];
  int n = intervals.size();

  for (int i = 1; i < n; i++)
  {
    if (intervals[i][0] >= lastEndTime)
    {
      cnt++;
      lastEndTime = intervals[i][1];
    }
  }
  return n - cnt;
}

int main()
{
  // vector<vector<int>> intervals = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
  vector<vector<int>> intervals = {{1, 2}, {1, 2}, {1, 2}};
  cout << eraseOverlapIntervals(intervals);
  return 0;
}