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

Node *deleteHead(Node *head)
{
  if (head == NULL || head->next == NULL)
  {
    return NULL;
  }
  Node *prev = head;
  head = head->next;

  head->back = nullptr;
  prev->next = nullptr;

  delete prev;
  return head;
}

Node *deletetail(Node *head)
{
  if (head == NULL || head->next == NULL)
  {
    return NULL;
  }
  Node *tail = head;
  while (tail->next != NULL)
  {
    tail = tail->next;
  }
  Node *newTail = tail->back;
  newTail->next = nullptr;
  tail->back = nullptr;
  delete tail;
  return head;
}

Node *removeKthElement(Node *head, int k)
{
  if (head == NULL)
  {
    return NULL;
  }
  int cnt = 0;
  Node *kNode = head;
  while (kNode != NULL)
  {
    cnt++;
    if (cnt == k)
      break;
    kNode = kNode->next;
  }
  Node *prev = kNode->back;
  Node *front = kNode->next;

  if (prev == NULL && front == NULL)
  {
    return NULL;
  }
  else if (prev == NULL)
  {
    return deleteHead(head);
  }
  else if (front == NULL)
  {
    return deletetail(head);
  }
  prev->next = front;
  front->back = prev;

  kNode->next = nullptr;
  kNode->back = nullptr;
  delete kNode;
  return head;
}

void deleteNode(Node *temp)
{
  Node *prev = temp->back;
  Node *front = temp->next;

  if (front == NULL)
  {
    prev->next = nullptr;
    temp->back = nullptr;
    free(temp);
    return;
  }
  prev->next = front;
  front->back = prev;

  temp->next = temp->back = nullptr;
  free(temp);
}

int main()
{
  vector<int> arr = {12, 5, 8, 7};
  Node *head = convertArr2DLL(arr);
  // head = deleteHead(head);
  // head = deletetail(head);
  // head = removeKthElement(head, 3);
  deleteNode(head->next->next);
  print(head);
  return 0;
}