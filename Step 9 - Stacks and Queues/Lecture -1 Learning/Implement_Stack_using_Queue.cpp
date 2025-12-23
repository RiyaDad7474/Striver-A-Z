#include <bits/stdc++.h>
using namespace std;

#define MAX 50

class MyStack
{
public:
  queue<int> q;

  MyStack()
  {
  }

  void push(int x)
  {
    q.push(x);
    int size = q.size();
    for (int i = 1; i < size; i++)
    {
      q.push(q.front());
      q.pop();
    }
  }

  int pop()
  {
    int val = q.front();
    q.pop();
    return val;
  }

  int top()
  {
    return q.front();
  }

  bool empty()
  {
    return q.empty();
  }
};
int main()
{
  MyStack s;
  s.push(10);
  s.push(20);
  s.push(30);
  cout << s.top() << " is on the top of the stack\n";
  cout << s.pop() << " popped from stack\n";
  cout << s.top() << " is on the top of the stack\n";
  return 0;
}
