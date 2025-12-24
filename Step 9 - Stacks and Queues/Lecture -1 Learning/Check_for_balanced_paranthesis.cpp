#include <bits/stdc++.h>
using namespace std;

bool isValid(string s)
{
  stack<char> st; // stack to hold opening brackets

  for (int i = 0; i < s.length(); i++)
  {
    char ch = s[i];

    // If opening bracket, push to stack
    if (ch == '(' || ch == '{' || ch == '[')
    {
      st.push(ch);
    }
    // If closing bracket
    else
    {
      if (st.empty())
        return false; // no matching opening

      char top = st.top();
      if ((ch == ')' && top == '(') ||
          (ch == '}' && top == '{') ||
          (ch == ']' && top == '['))
      {
        st.pop();
      }
      else
      {
        return false; // mismatched bracket
      }
    }
  }

  // If stack is empty → all brackets matched
  return st.empty();
}

int main()
{
  string s;
  cout << "Enter a string of parentheses: ";
  cin >> s;

  if (isValid(s))
    cout << "The parentheses are balanced." << endl;
  else
    cout << "The parentheses are not balanced." << endl;

  return 0;
}