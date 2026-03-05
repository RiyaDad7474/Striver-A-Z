#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s)
{
  int maxlen = 0;
  for (int i = 0; i < s.length(); i++)
  {
    int hash[256] = {0};
    for (int j = i; j < s.length(); j++)
    {
      if (hash[s[j]] == 1)
        break;

      int len = j - i + 1;
      maxlen = max(len, maxlen);
      hash[s[j]] = 1;
    }
  }
  return maxlen;
}
int main()
{
  cout << lengthOfLongestSubstring("abcabcbb") << endl;
  return 0;
}
