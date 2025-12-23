#include <bits/stdc++.h>
using namespace std;

#define MAX 5

class Stack
{
  int arr[MAX];
  int top;

public:
  Stack()
  {
    top = -1;
  }

  // Push operation
  void push(int x)
  {
    if (top == MAX - 1)
    {
      cout << "Stack Overflow\n";
      return;
    }
    top++;
    arr[top] = x;
    cout << x << " pushed\n";
  }

  // Pop operation
  void pop()
  {
    if (top == -1)
    {
      cout << "Stack Underflow\n";
      return;
    }
    cout << arr[top] << " popped\n";
    top--;
  }

  // Top operation
  void Top()
  {
    if (top == -1)
    {
      cout << "Stack is empty\n";
      return;
    }
    cout << "Top element: " << arr[top] << endl;
  }
};

int main()
{
  Stack s;
  s.push(10);
  s.push(20);
  s.push(30);
  s.Top();
  s.pop();
  s.Top();
  return 0;
}
