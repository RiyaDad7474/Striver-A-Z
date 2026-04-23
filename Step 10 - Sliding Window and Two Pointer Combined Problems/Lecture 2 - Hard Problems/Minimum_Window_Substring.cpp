#include <bits/stdc++.h>
using namespace std;

string minWindow(string s, string t)
{
  int l = 0, r = 0;
  int hash[256] = {0};
  int minLen = INT_MAX;
  int SIndex = -1;
  int count = 0;
  int m = t.size();

  for (char c : t)
    hash[c]++;

  while (r < s.size())
  {
    if (hash[s[r]] > 0)
      count++;

    hash[s[r]]--;

    while (count == m)
    {
      if ((r - l + 1) < minLen)
      {
        minLen = r - l + 1;
        SIndex = l;
      }

      hash[s[l]]++;

      if (hash[s[l]] > 0)
        count--;

      l++;
    }
    r++;
  }

  return SIndex == -1 ? "" : s.substr(SIndex, minLen);
}

int main()
{
  string s, t;
  cin >> s;
  cin >> t;

  cout << minWindow(s, t);
  return 0;
}