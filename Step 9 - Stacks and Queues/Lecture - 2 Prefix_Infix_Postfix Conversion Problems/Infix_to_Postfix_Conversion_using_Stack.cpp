#include <bits/stdc++.h>
using namespace std;

int prec(char c)
{
  if (c == '^')
    return 3;
  if (c == '*' || c == '/')
    return 2;
  if (c == '+' || c == '-')
    return 1;
  return -1;
}

int main()
{
  string infix;
  cin >> infix;

  stack<char> st;
  string postfix = "";

  for (char c : infix)
  {
    if (isalnum(c))
      postfix += c;
    else if (c == '(')
      st.push(c);
    else if (c == ')')
    {
      while (!st.empty() && st.top() != '(')
      {
        postfix += st.top();
        st.pop();
      }
      st.pop();
    }
    else
    {
      while (!st.empty() && prec(st.top()) >= prec(c))
      {
        postfix += st.top();
        st.pop();
      }
      st.push(c);
    }
  }

  while (!st.empty())
  {
    postfix += st.top();
    st.pop();
  }

  cout << postfix;
  return 0;
}
