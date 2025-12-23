#include <iostream>
using namespace std;

// Node structure
struct Node
{
  int data;
  Node *next;
};

class Queue
{
  Node *start;
  Node *end;

public:
  Queue()
  {
    start = NULL;
    end = NULL;
  }

  // Enqueue operation
  void enqueue(int x)
  {
    Node *temp = new Node(); // using temp
    temp->data = x;
    temp->next = NULL;

    if (start == NULL)
    { // empty queue
      start = temp;
      end = temp;
    }
    else
    {
      end->next = temp;
      end = temp;
    }
    cout << x << " inserted\n";
  }

  // Dequeue operation
  void dequeue()
  {
    if (start == NULL)
    {
      cout << "Queue Underflow\n";
      return;
    }
    Node *temp = start; // using temp
    cout << temp->data << " removed\n";
    start = start->next;

    if (start == NULL)
    { // queue becomes empty
      end = NULL;
    }
    delete temp;
  }

  // Display queue
  void display()
  {
    if (start == NULL)
    {
      cout << "Queue is empty\n";
      return;
    }
    Node *temp = start;
    while (temp != NULL)
    {
      cout << temp->data << " ";
      temp = temp->next;
    }
    cout << endl;
  }
};

int main()
{
  Queue q;
  q.enqueue(10);
  q.enqueue(20);
  q.enqueue(30);
  q.display();
  q.dequeue();
  q.display();
  return 0;
}
