#include <bits/stdc++.h>
using namespace std;

string removeKdigits(string num, int k)
{
  string st = "";

  for (char c : num)
  {
    while (!st.empty() && k > 0 && st.back() > c)
    {
      st.pop_back();
      k--;
    }
    st.push_back(c);
  }

  // if k still remains, remove from end
  while (k > 0 && !st.empty())
  {
    st.pop_back();
    k--;
  }

  // remove leading zeros
  int i = 0;
  while (i < st.size() && st[i] == '0')
    i++;

  string ans = st.substr(i);

  return ans.empty() ? "0" : ans;
}

int main()
{
  string num = "1432219";
  int k = 3;
  cout << "Result after removing " << k << " digits: " << removeKdigits(num, k) << endl;
  return 0;
}
