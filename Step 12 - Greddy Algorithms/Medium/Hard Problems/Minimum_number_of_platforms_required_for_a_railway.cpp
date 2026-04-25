#include <bits/stdc++.h>
using namespace std;

// TC -> O(N^2)
// SC -> O(1)

// int platform(vector<int> &arrival, vector<int> &dept)
// {
//   int maxCnt = 1;
//   int n = arrival.size();

//   for (int i = 0; i < n; i++)
//   {
//     int cnt = 1;
//     for (int j = 0; j < n; j++)
//     {
//       if (i != j)
//       {
//         if (arrival[j] <= dept[i] && dept[j] >= arrival[i])
//         {
//           cnt++;
//         }
//       }
//     }
//     maxCnt = max(maxCnt, cnt);
//   }

//   return maxCnt;
// }

// TC -> 2(NlogN+N)
// SC -> O(1)

int platform(vector<int> &arrival, vector<int> &dept)
{

  sort(arrival.begin(), arrival.end());
  sort(dept.begin(), dept.end());
  int n = arrival.size();

  int i = 0, j = 0, cnt = 0, maxCnt = 0;
  while (i < n && j < n)
  {
    if (arrival[i] <= dept[j])
    {
      cnt++;
      i++;
    }
    else
    {
      cnt--;
      j++;
    }

    maxCnt = max(maxCnt, cnt);
  }

  return maxCnt;
}

int main()
{
  vector<int> arrival = {900, 950, 940};
  vector<int> dept = {910, 1200, 1120};
  cout << platform(arrival, dept);
  return 0;
}
