#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
  int data;
  Node *next;

  // Constructor with both data and next node
  Node(int data1, Node *next1)
  {
    data = data1;
    next = next1;
  }

  // Constructor with only data (assuming next is initially null)
  Node(int data1)
  {
    data = data1;
    next = nullptr;
  }
};

// Function to print the linked list
void print(Node *head)
{
  while (head != NULL)
  {
    cout << head->data << " ";
    head = head->next;
  }
}

Node *insertHead(Node *head, int val)
{
  return new Node(val, head);
}
Node *insertTail(Node *head, int val)
{
  if (head == NULL)
  {
    return new Node(val);
  }
  Node *temp = head;
  while (temp->next != NULL)
  {
    temp = temp->next;
  }
  Node *newNode = new Node(val);
  temp->next = newNode;
  return head;
}
Node *insertPosition(Node *head, int el, int k)
{
  if (head == NULL)
  {
    if (k == 1)
    {
      return new Node(el);
    }
    else
    {
      return head;
    }
  }
  if (k == 1)
  {
    return new Node(el, head);
  }
  int cnt = 0;
  Node *temp = head;
  while (temp != NULL)
  {
    cnt++;
    if (cnt == (k - 1))
    {
      Node *x = new Node(el, temp->next);
      temp->next = x;
      break;
    }
    temp = temp->next;
  }
  return head;
}
Node *insertBeforeValue(Node *head, int el, int val)
{
  if (head == NULL)
    return NULL;
  if (head->data == val)
  {
    return new Node(el, head);
  }
  Node *temp = head;
  bool found = false;
  while (temp->next != NULL)
  {

    if (temp->next->data == val)
    {
      Node *x = new Node(el, temp->next);
      temp->next = x;
      found = 1;
      break;
    }
    temp = temp->next;
  }
  if (found == false)
  {
  }
  return head;
}
int main()
{
  vector<int> arr = {12, 5, 8, 7};

  Node *head = new Node(arr[0]);
  head->next = new Node(arr[1]);
  head->next->next = new Node(arr[2]);
  head->next->next->next = new Node(arr[3]);

  // head = insertHead(head, 100);
  // head = insertTail(head, 100);
  // head = insertPosition(head, 100, 2);
  head = insertBeforeValue(head, 100, 5);
  print(head);
}