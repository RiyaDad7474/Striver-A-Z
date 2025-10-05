#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
  int data;   // Data stored in the node
  Node *next; // Pointer to the next node in the list (forward direction)
  Node *back; // Pointer to the previous node in the list (backward direction)

  // Constructor for a Node with both data, a reference to the next node, and a reference to the previous node
  Node(int data1, Node *next1, Node *back1)
  {
    data = data1;
    next = next1; // Similar to a singly linked list, but now with a 'back' pointer.
    back = back1; // Addition of 'back' pointer for the doubly linked list.
  }

  // Constructor for a Node with data, and no references to the next and previous nodes (end of the list)
  Node(int data1)
  {
    data = data1;
    next = nullptr; // Similar to a singly linked list.
    back = nullptr; // Addition of 'back' pointer initialization.
  }
};
Node *convertArr2DLL(vector<int> &arr)
{
  Node *head = new Node(arr[0]);
  Node *prev = head;
  for (int i = 1; i < arr.size(); i++)
  {
    Node *temp = new Node(arr[i], nullptr, prev);
    prev->next = temp;
    prev = temp;
  }
  return head;
}
void print(Node *head)
{
  while (head != NULL)
  {
    cout << head->data << " ";
    head = head->next;
  }
}

// Insert before

Node *insertBeforeHead(Node *head, int val)
{
  Node *newHead = new Node(val, head, nullptr);
  head->back = newHead;

  return newHead;
}

Node *insertBeforeTail(Node *head, int val)
{
  if (head->next == NULL)
  {
    return insertBeforeHead(head, val);
  }
  Node *tail = head;
  while (tail->next != NULL)
  {
    tail = tail->next;
  }

  Node *prev = tail->back;
  Node *newNode = new Node(val, tail, prev);
  prev->next = newNode;
  tail->back = newNode;
  return head;
}
Node *insertBeforeKthElement(Node *head, int k, int val)
{
  if (k == 1)
  {
    return insertBeforeHead(head, val);
  }
  Node *temp = head;
  int cnt = 0;
  while (temp != NULL)
  {
    cnt++;
    if (cnt == k)
      break;
    temp = temp->next;
  }
  Node *prev = temp->back;
  Node *newNode = new Node(val, temp, prev);
  prev->next = newNode;
  temp->back = newNode;
  return head;
}
void insertBeforeNode(Node *node, int val)
{
  Node *prev = node->back;
  Node *newNode = new Node(val, node, prev);
  prev->next = newNode;
  node->back = newNode;
}
int main()
{
  vector<int> arr = {12, 5, 8, 7};
  Node *head = convertArr2DLL(arr);
  // head = insertBeforeHead(head, 10);
  // head = insertBeforeTail(head, 10);
  // head = insertBeforeKthElement(head, 2, 10);
  insertBeforeNode(head->next->next, 100);
  print(head);
  return 0;
}