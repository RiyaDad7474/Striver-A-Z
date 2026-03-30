#include <bits/stdc++.h>
using namespace std;

// Bruteforce approach
// int subStr(string s, int k)
// {
//   int maxlen = 0;
//   int n = s.length();
//   unordered_map<char, int> mpp;

//   for (int i = 0; i < n; i++)
//   {
//     mpp.clear();
//     for (int j = i; j < n; j++)
//     {
//       mpp[s[j]]++;
//       if (mpp.size() <= k)
//       {
//         maxlen = max(maxlen, j - i + 1);
//       }
//       else
//         break;
//     }
//   }
//   return maxlen;
// }

// Optimal Solution
int subStr(string s, int k)
{
  int maxlen = 0, l = 0, r = 0;
  int n = s.length();
  unordered_map<char, int> mpp;

  while (r < n)
  {
    mpp[s[r]]++;
    if (mpp.size() > k)
    {
      mpp[s[l]]--;
      if (mpp[s[l]] == 0)
        mpp.erase(s[l]);

      l = l + 1;
    }
    if (mpp.size() <= k)
    {
      maxlen = max(maxlen, r - l + 1);
    }
    r = r + 1;
  }
  return maxlen;
}
int main()
{
  string s;
  cin >> s;
  int k;
  cin >> k;
  cout << subStr(s, k);
  return 0;
}