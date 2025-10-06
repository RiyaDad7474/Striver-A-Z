#include <iostream>
using namespace std;

struct Node
{
  int data;
  Node *prev;
  Node *next;
  Node(int x) : data(x), prev(NULL), next(NULL) {}
};

// Function to insert node at the end
Node *insertEnd(Node *head, int data)
{
  Node *newNode = new Node(data);
  if (head == NULL)
    return newNode;

  Node *temp = head;
  while (temp->next != NULL)
    temp = temp->next;

  temp->next = newNode;
  newNode->prev = temp;
  return head;
}

// Function to find pairs with a given sum in a sorted DLL
void findPairsWithSum(Node *head, int target)
{
  Node *first = head;
  Node *second = head;

  // Move second pointer to the last node
  while (second->next != NULL)
    second = second->next;

  bool found = false;

  // Two-pointer approach
  while (first != NULL && second != NULL && first != second && second->next != first)
  {
    int sum = first->data + second->data;

    if (sum == target)
    {
      cout << "(" << first->data << ", " << second->data << ") ";
      found = true;
      first = first->next;
      second = second->prev;
    }
    else if (sum < target)
      first = first->next; // move forward
    else
      second = second->prev; // move backward
  }

  if (!found)
    cout << "No pair found";
}

// Function to print DLL
void printList(Node *head)
{
  Node *temp = head;
  while (temp != NULL)
  {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}

// Main function
int main()
{
  Node *head = NULL;
  head = insertEnd(head, 1);
  head = insertEnd(head, 2);
  head = insertEnd(head, 4);
  head = insertEnd(head, 5);
  head = insertEnd(head, 6);
  head = insertEnd(head, 8);
  head = insertEnd(head, 9);

  cout << "Doubly Linked List: ";
  printList(head);

  int target = 7;
  cout << "Pairs with sum " << target << ": ";
  findPairsWithSum(head, target);
  cout << endl;

  return 0;
}
