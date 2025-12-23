#include <iostream>
using namespace std;

// Node structure
struct Node
{
  int data;
  Node *next;
};

class Stack
{
  Node *top;

public:
  Stack()
  {
    top = NULL;
  }

  // Push operation
  void push(int x)
  {
    Node *temp = new Node(); // using temp
    temp->data = x;
    temp->next = top;
    top = temp;
    cout << x << " pushed\n";
  }

  // Pop operation
  void pop()
  {
    if (top == NULL)
    {
      cout << "Stack Underflow\n";
      return;
    }
    Node *temp = top; // using temp
    cout << temp->data << " popped\n";
    top = top->next;
    delete temp;
  }

  // Top operation
  void Top()
  {
    if (top == NULL)
    {
      cout << "Stack is empty\n";
      return;
    }
    cout << "Top element: " << top->data << endl;
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
