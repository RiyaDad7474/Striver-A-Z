#include <bits/stdc++.h>
using namespace std;

// BruteForce Approach
//  int lengthOfLongestSubstring(string s)
//  {
//    int maxlen = 0;
//    for (int i = 0; i < s.length(); i++)
//    {
//      int hash[256] = {0};
//      for (int j = i; j < s.length(); j++)
//      {
//        if (hash[s[j]] == 1)
//          break;

//       int len = j - i + 1;
//       maxlen = max(len, maxlen);
//       hash[s[j]] = 1;
//     }
//   }
//   return maxlen;
// }

// Optimal Approach
int lengthOfLongestSubstring(string s)
{
  int n = s.length();

  int hash[256];
  /* Initialize hash table with
  -1 (indicating no occurrence)*/
  for (int i = 0; i < 256; i++)
  {
    hash[i] = -1;
  }
  int l = 0, r = 0, maxlen = 0;
  while (r < n)
  {
    if (hash[s[r]] != -1)
    {
      l = max(hash[s[r]] + 1, l);
    }
    int len = r - l + 1;
    maxlen = max(len, maxlen);
    hash[s[r]] = r;
    r++;
  }
  return maxlen;
}

int main()
{
  cout << lengthOfLongestSubstring("abcabcbb") << endl;
  return 0;
}