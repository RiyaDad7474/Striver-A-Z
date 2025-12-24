#include <bits/stdc++.h>
using namespace std;

class MyQueue
{
public:
  stack<int> s1, s2;

  // Push element to back of queue
  void push(int x)
  {
    s1.push(x);
  }

  // Remove element from front of queue
  int pop()
  {
    if (s2.empty())
    {
      while (!s1.empty())
      {
        s2.push(s1.top());
        s1.pop();
      }
    }
    int front = s2.top();
    s2.pop();
    return front;
  }

  // Get front element
  int peek()
  {
    if (s2.empty())
    {
      while (!s1.empty())
      {
        s2.push(s1.top());
        s1.pop();
      }
    }
    return s2.top();
  }

  // Check if queue is empty
  bool empty()
  {
    return s1.empty() && s2.empty();
  }
};

int main()
{
  MyQueue q;

  q.push(10);
  q.push(20);
  q.push(30);

  cout << "Front element: " << q.peek() << endl; // 10
  cout << "Popped: " << q.pop() << endl;         // 10
  cout << "Front element: " << q.peek() << endl; // 20

  if (q.empty())
    cout << "Queue is empty" << endl;
  else
    cout << "Queue is not empty" << endl;

  return 0;
}
