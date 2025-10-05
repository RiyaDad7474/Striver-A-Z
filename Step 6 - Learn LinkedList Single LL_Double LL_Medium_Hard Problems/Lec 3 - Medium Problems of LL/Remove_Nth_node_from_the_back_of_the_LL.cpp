#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
  ListNode *removeNthFromEnd(ListNode *head, int n)
  {
    // Step 1: Create a dummy node before head
    ListNode *dummy = new ListNode(0, head);

    // Step 2: Set up two pointers
    ListNode *fast = dummy;
    ListNode *slow = dummy;

    // Step 3: Move fast n+1 steps ahead
    for (int i = 0; i <= n; i++)
    {
      fast = fast->next;
    }

    // Step 4: Move both until fast reaches the end
    while (fast != nullptr)
    {
      fast = fast->next;
      slow = slow->next;
    }

    // Step 5: Delete the nth node
    ListNode *toDelete = slow->next;
    slow->next = slow->next->next;
    delete toDelete; // free memory

    // Step 6: Return new head
    ListNode *newHead = dummy->next;
    delete dummy; // cleanup dummy node
    return newHead;
  }
};

// ---------- Example usage ----------
int main()
{
  // Create linked list: 1 -> 2 -> 3 -> 4 -> 5
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);

  Solution sol;
  int n = 2;
  head = sol.removeNthFromEnd(head, n); // should remove 4

  // Print updated list: 1 -> 2 -> 3 -> 5
  ListNode *temp = head;
  while (temp != nullptr)
  {
    cout << temp->val << " ";
    temp = temp->next;
  }
  cout << endl;

  return 0;
}
