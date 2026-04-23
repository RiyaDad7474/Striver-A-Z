#include <bits/stdc++.h>
using namespace std;

bool checkValidString(string s)
{
  int leftMin = 0, leftMax = 0;
  for (char ch : s)
  {
    if (ch == '(')
    {
      leftMin++;
      leftMax++;
    }
    else if (ch == ')')
    {
      leftMin--;
      leftMax--;
    }
    else
    {            // '*'
      leftMin--; // treat as ')'
      leftMax++; // treat as '('
    }

    if (leftMax < 0)
      return false; // too many ')'
    if (leftMin < 0)
      leftMin = 0; // can't go below 0
  }
  return leftMin == 0;
}

int main()
{
  string s;
  cin >> s;
  cout << checkValidString(s);
}