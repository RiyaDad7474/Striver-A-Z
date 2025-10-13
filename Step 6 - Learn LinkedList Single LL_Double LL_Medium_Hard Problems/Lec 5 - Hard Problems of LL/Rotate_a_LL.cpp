#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
  int num;
  Node *next;
  Node(int a)
  {
    num = a;
    next = NULL;
  }
};

void insertNode(Node *&head, int val)
{
  Node *newNode = new Node(val);
  if (head == NULL)
  {
    head = newNode;
    return;
  }
  Node *temp = head;
  while (temp->next != NULL)
    temp = temp->next;

  temp->next = newNode;
  return;
}
Node *rotateRight(Node *head, int k)
{
  if (head == NULL || head->next == NULL)
    return head;
  for (int i = 0; i < k; i++)
  {
    Node *temp = head;
    while (temp->next->next != NULL)
      temp = temp->next;
    Node *end = temp->next;
    temp->next = NULL;
    end->next = head;
    head = end;
  }
  return head;
}

void printList(Node *head)
{
  while (head->next != NULL)
  {
    cout << head->num << "->";
    head = head->next;
  }
  cout << head->num << endl;
  return;
}

int main()
{
  Node *head = NULL;

  insertNode(head, 1);
  insertNode(head, 2);
  insertNode(head, 3);
  insertNode(head, 4);
  insertNode(head, 5);

  cout << "Original list: ";
  printList(head);

  int k = 2;
  Node *newHead = rotateRight(head, k);

  cout << "After" << k << " iterations: ";
  printList(newHead);
  return 0;
}