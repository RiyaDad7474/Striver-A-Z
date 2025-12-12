#include <bits/stdc++.h>
using namespace std;

bool possible(vector<int> &bloomday, int day, int r, int b)
{
  int cnt = 0;
  int no0fB = 0;
  for (int i = 0; i < bloomday.size(); i++)
  {
    if (bloomday[i] <= day)
    {
      cnt++;
    }
    else
    {
      no0fB += (cnt / b);
      cnt = 0;
    }
  }
  no0fB += (cnt / b);
  return no0fB >= r;
}
int roseGarden(vector<int> &bloomday, int m, int k)
{
  long long val = m * 1LL * k * 1LL;
  if (val > bloomday.size())
    return -1;
  int mini = INT_MAX, maxi = INT_MIN;
  for (int i = 0; i < bloomday.size(); i++)
  {
    mini = min(mini, bloomday[i]);
    maxi = max(maxi, bloomday[i]);
  }
  int low = mini, high = maxi;
  while (low <= high)
  {
    int mid = (low + high) / 2;
    if (possible(bloomday, mid, m, k))
    {
      high = mid - 1;
    }
    else
      low = mid + 1;
  }
  return low;
}

int main()
{
  vector<int> bloomday = {1, 10, 3, 10, 2};
  int m = 3;
  int k = 1;
  cout << roseGarden(bloomday, m, k) << endl;
  return 0;
}