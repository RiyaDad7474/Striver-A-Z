#include <iostream>
using namespace std;

#define MAX 100 // Maximum size of the stack

class Stack
{
  int top;
  int arr[MAX]; // Fixed-size array

public:
  Stack() { top = -1; } // Initialize top to -1 (empty)

  bool push(int x)
  {
    if (top >= (MAX - 1))
    {
      cout << "Stack Overflow" << endl;
      return false;
    }
    arr[++top] = x;
    return true;
  }

  int pop()
  {
    if (top < 0)
    {
      cout << "Stack Underflow" << endl;
      return 0;
    }
    return arr[top--];
  }

  int peek()
  {
    if (top < 0)
    {
      cout << "Stack is Empty" << endl;
      return 0;
    }
    return arr[top];
  }

  bool isEmpty()
  {
    return (top < 0);
  }
};

int main()
{
  Stack s;
  s.push(10);
  s.push(20);
  s.push(30);
  cout << s.pop() << " Popped from stack\n";
  cout << "Top element is: " << s.peek() << endl;
  return 0;
}
