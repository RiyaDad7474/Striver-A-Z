#include <bits/stdc++.h>
using namespace std;

// bruteforce solution
int numberOfSubstrings(string s)
{
  int count = 0;
  for (int i = 0; i < s.length(); i++)
  {
    int hash[3] = {0};

    for (int j = i; j < s.length(); j++)
    {
      hash[s[j] - 'a'] = 1;
      if (hash[0] + hash[1] + hash[2] == 3)
      {
        count = count + 1;
      }
    }
  }
  return count;
}

// Optimal Solution

int numberOfSubstrings(string s)
{
  vector<int> lastSeen(3, -1); // for 'a', 'b', 'c'
  int count = 0;

  for (int i = 0; i < s.length(); i++)
  {
    lastSeen[s[i] - 'a'] = i;

    // if all characters seen at least once
    if (lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1)
    {
      count += 1 + min({lastSeen[0], lastSeen[1], lastSeen[2]});
    }
  }

  return count;
}

int main()
{
  string s;
  cin >> s;
  cout << numberOfSubstrings(s);
  return 0;
}