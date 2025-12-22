#include <bits/stdc++.h>
using namespace std;

bool isAnagram(string s, string t)
{
  sort(begin(s), end(s));
  sort(begin(t), end(t));

  return s == t;
}
int main()
{
  string s = "anagram", t = "nagaram";
  cout << (isAnagram(s, t) ? "true" : "false") << endl;
  return 0;
}