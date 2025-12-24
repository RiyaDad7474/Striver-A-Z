#include <bits/stdc++.h>
using namespace std;

class MinStack
{
  stack<long long> st;
  long long mini;

public:
  MinStack() {}

  void push(int val)
  {
    if (st.empty())
    {
      st.push(val);
      mini = val;
    }
    else if (val >= mini)
    {
      st.push(val);
    }
    else
    {
      long long newMin = 2LL * val - mini;
      st.push(newMin);
      mini = val;
    }
  }

  void pop()
  {
    if (st.empty())
      return;

    long long topVal = st.top();
    st.pop();

    if (topVal < mini)
    {
      // restore previous minimum
      mini = 2 * mini - topVal;
    }
  }

  int top()
  {
    if (st.top() >= mini)
      return st.top();
    else
      return mini;
  }

  int getMin()
  {
    return mini;
  }
};

int main()
{
  MinStack ms;

  ms.push(5);
  ms.push(3);
  ms.push(7);
  ms.push(2);

  cout << "Top: " << ms.top() << endl;    // 2
  cout << "Min: " << ms.getMin() << endl; // 2

  ms.pop();
  cout << "Top: " << ms.top() << endl;    // 7
  cout << "Min: " << ms.getMin() << endl; // 3

  return 0;
}
