#include <bits/stdc++.h>
using namespace std;

// tc -> O(N)+O(NlogN)
// sc -> O(1)
long sjf(vector<int> arr)
{
  sort(arr.begin(), arr.end());
  int t = 0, wTime = 0;
  int n = arr.size();
  for (int i = 0; i < n; i++)
  {
    wTime += t;
    t += arr[i];
  }
  return (wTime / n);
}

int main()
{
  vector<int> arr = {4, 3, 7, 1, 2};
  cout << sjf(arr);
  return 0;
}