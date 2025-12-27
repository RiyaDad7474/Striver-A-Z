#include <bits/stdc++.h>
using namespace std;

int main()
{
  string postfix;
  cin >> postfix;

  stack<string> st;

  for (char c : postfix)
  {
    if (isalnum(c))
    {
      st.push(string(1, c));
    }
    else
    {
      string b = st.top();
      st.pop();
      string a = st.top();
      st.pop();
      st.push("(" + a + c + b + ")");
    }
  }

  cout << st.top();
  return 0;
}
