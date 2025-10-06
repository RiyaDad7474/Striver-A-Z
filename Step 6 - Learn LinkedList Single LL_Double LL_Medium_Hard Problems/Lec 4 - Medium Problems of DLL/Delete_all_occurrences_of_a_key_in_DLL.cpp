#include <iostream>
using namespace std;

struct Node
{
  int data;
  Node *prev;
  Node *next;
  Node(int x) : data(x), prev(NULL), next(NULL) {}
};

// Function to delete all occurrences of key
Node *deleteAllOccurrences(Node *head, int key)
{
  Node *curr = head;

  while (curr != NULL)
  {
    if (curr->data == key)
    {
      Node *temp = curr;

      // If node to be deleted is head
      if (curr == head)
        head = curr->next;

      // Update previous node
      if (curr->prev != NULL)
        curr->prev->next = curr->next;

      // Update next node
      if (curr->next != NULL)
        curr->next->prev = curr->prev;

      curr = curr->next; // Move to next node
      delete temp;       // Free memory
    }
    else
    {
      curr = curr->next;
    }
  }
  return head;
}

// Function to insert node at end
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
  head = insertEnd(head, 2);
  head = insertEnd(head, 5);
  head = insertEnd(head, 2);
  head = insertEnd(head, 4);
  head = insertEnd(head, 2);
  head = insertEnd(head, 10);

  cout << "Original DLL: ";
  printList(head);

  int key = 2;
  head = deleteAllOccurrences(head, key);

  cout << "After deleting all occurrences of " << key << ": ";
  printList(head);

  return 0;
}
