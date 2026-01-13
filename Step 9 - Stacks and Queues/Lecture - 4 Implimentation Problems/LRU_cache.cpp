#include <bits/stdc++.h>
using namespace std;

class LRUCache
{
public:
  struct Node
  {
    int key, value;
    Node *prev;
    Node *next;
    Node(int k, int v)
    {
      key = k;
      value = v;
      prev = next = nullptr;
    }
  };

  int capacity;
  unordered_map<int, Node *> mpp;
  Node *head;
  Node *tail;

  // Constructor
  LRUCache(int cap)
  {
    capacity = cap;
    head = new Node(0, 0); // dummy head
    tail = new Node(0, 0); // dummy tail
    head->next = tail;
    tail->prev = head;
  }

  // Remove node from DLL
  void deleteNode(Node *node)
  {
    Node *prevNode = node->prev;
    Node *nextNode = node->next;
    prevNode->next = nextNode;
    nextNode->prev = prevNode;
  }

  // Insert node after head
  void insertFront(Node *node)
  {
    node->next = head->next;
    node->prev = head;
    head->next->prev = node;
    head->next = node;
  }

  int get(int key)
  {
    if (mpp.find(key) == mpp.end())
      return -1;

    Node *node = mpp[key];
    deleteNode(node);
    insertFront(node);
    return node->value;
  }

  void put(int key, int value)
  {
    if (mpp.find(key) != mpp.end())
    {
      Node *node = mpp[key];
      node->value = value;
      deleteNode(node);
      insertFront(node);
    }
    else
    {
      if (mpp.size() == capacity)
      {
        Node *lru = tail->prev;
        mpp.erase(lru->key);
        deleteNode(lru);
        delete lru;
      }

      Node *node = new Node(key, value);
      mpp[key] = node;
      insertFront(node);
    }
  }
};

int main()
{
  LRUCache cache(3);

  vector<int> keys = {1, 2, 3, 1, 4, 5};
  vector<int> values = {10, 20, 30, 40, 50, 60};

  for (int i = 0; i < keys.size(); i++)
  {
    cache.put(keys[i], values[i]);
    cout << "Inserted (" << keys[i] << ", " << values[i] << ")\n";
  }

  cout << "Get 1 -> " << cache.get(1) << endl;
  cout << "Get 2 -> " << cache.get(2) << endl;
}
