#include <bits/stdc++.h>
using namespace std;

struct data
{
  int start, end, pos;
};

bool comparator(data val1, data val2)
{
  if (val1.end < val2.end)
    return true;
  else if (val1.end == val2.end)
    return val1.pos < val2.pos;

  return false;
}

vector<int> func(vector<int> &start, vector<int> &end, int N)
{
  vector<data> arr(N);

  for (int i = 0; i < N; i++)
  {
    arr[i].start = start[i];
    arr[i].end = end[i];
    arr[i].pos = i + 1;
  }

  sort(arr.begin(), arr.end(), comparator);

  vector<int> ans;
  data ds = arr[0];
  ans.push_back(ds.pos);

  for (int i = 1; i < N; i++)
  {
    if (arr[i].start > ds.end)
    {
      ans.push_back(arr[i].pos);
      ds = arr[i];
    }
  }

  return ans;
}

int main()
{
  vector<int> start = {1, 3, 0, 5, 8, 5};
  vector<int> end = {2, 4, 6, 7, 9, 9};

  int N = start.size();

  vector<int> res = func(start, end, N);

  for (int x : res)
    cout << x << " ";
}