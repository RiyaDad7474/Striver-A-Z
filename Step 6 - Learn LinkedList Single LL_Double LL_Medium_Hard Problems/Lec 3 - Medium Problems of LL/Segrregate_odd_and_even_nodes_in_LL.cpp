#include <iostream>
using namespace std;

// Definition for singly-linked list
struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
  ListNode *oddEvenList(ListNode *head)
  {
    if (!head || !head->next)
      return head;

    ListNode *odd = head;
    ListNode *even = head->next;
    ListNode *evenHead = head->next;

    while (even != NULL && even->next != NULL)
    {
      odd->next = odd->next->next;
      even->next = even->next->next;

      odd = odd->next;
      even = even->next;
    }

    odd->next = evenHead;
    return head;
  }
};

// Helper function to print the list
void printList(ListNode *head)
{
  while (head)
  {
    cout << head->val;
    if (head->next)
      cout << " -> ";
    head = head->next;
  }
  cout << endl;
}

int main()
{
  // Create linked list: 1 -> 2 -> 3 -> 4 -> 5
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);

  Solution s;
  ListNode *newHead = s.oddEvenList(head);

  // Output: 1 -> 3 -> 5 -> 2 -> 4
  printList(newHead);

  return 0;
}
