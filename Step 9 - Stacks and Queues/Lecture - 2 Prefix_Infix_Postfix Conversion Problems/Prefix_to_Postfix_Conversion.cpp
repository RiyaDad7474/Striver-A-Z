#include <bits/stdc++.h>
using namespace std;

int main()
{
  string prefix;
  cin >> prefix;

  stack<string> st;

  for (int i = prefix.length() - 1; i >= 0; i--)
  {
    if (isalnum(prefix[i]))
    {
      st.push(string(1, prefix[i]));
    }
    else
    {
      string a = st.top();
      st.pop();
      string b = st.top();
      st.pop();
      st.push(a + b + prefix[i]);
    }
  }

  cout << st.top();
  return 0;
}
