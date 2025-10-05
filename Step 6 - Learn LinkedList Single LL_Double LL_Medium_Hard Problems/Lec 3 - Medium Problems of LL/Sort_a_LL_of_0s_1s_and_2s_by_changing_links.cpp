#include <bits/stdc++.h>
using namespace std;

// Node definition
class Node
{
public:
  int data;
  Node *next;
  Node(int val)
  {
    data = val;
    next = nullptr;
  }
};

Node *sortList(Node *head)
{
  if (!head || !head->next)
    return head;

  // Dummy Nodes
  Node *zeroHead = new Node(-1);
  Node *oneHead = new Node(-1);
  Node *twoHead = new Node(-1);

  // Nodes for travrsal
  Node *zero = zeroHead;
  Node *one = oneHead;
  Node *two = twoHead;
  Node *temp = head;

  // Traverse
  while (temp)
  {
    if (temp->data == 0)
    {
      zero->next = temp;
      zero = zero->next;
    }
    else if (temp->data == 1)
    {
      one->next = temp;
      one = one->next;
    }
    else
    {
      two->next = temp;
      two = two->next;
    }
    temp = temp->next;
  }

  zero->next = (oneHead->next) ? (oneHead->next) : (twoHead->next);
  one->next = twoHead->next;
  two->next = NULL;

  Node *newHead = zeroHead->next;

  delete zeroHead;
  delete oneHead;
  delete twoHead;
  return newHead;
}

// Helper function: Insert node at end
Node *insert(Node *head, int val)
{
  Node *newNode = new Node(val);
  if (!head)
    return newNode;
  Node *temp = head;
  while (temp->next)
    temp = temp->next;
  temp->next = newNode;
  return head;
}

// Helper function: Print list
void printList(Node *head)
{
  while (head)
  {
    cout << head->data << " ";
    head = head->next;
  }
  cout << endl;
}

// Driver code
int main()
{
  Node *head = nullptr;

  // Example input: 1 → 2 → 0 → 1 → 2 → 0
  head = insert(head, 1);
  head = insert(head, 2);
  head = insert(head, 0);
  head = insert(head, 1);
  head = insert(head, 2);
  head = insert(head, 0);

  cout << "Original List: ";
  printList(head);

  head = sortList(head);

  cout << "Sorted List:   ";
  printList(head);

  return 0;
}