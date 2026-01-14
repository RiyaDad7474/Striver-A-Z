#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int key, value, cnt;
  Node *prev;
  Node *next;

  Node(int _key, int _value)
  {
    key = _key;
    value = _value;
    cnt = 1;
    prev = next = NULL;
  }
};

struct List
{
  int size;
  Node *head;
  Node *tail;

  List()
  {
    head = new Node(0, 0);
    tail = new Node(0, 0);
    head->next = tail;
    tail->prev = head;
    size = 0;
  }

  void addFront(Node *node)
  {
    Node *temp = head->next;
    node->next = temp;
    node->prev = head;
    head->next = node;
    temp->prev = node;
    size++;
  }

  void removeNode(Node *node)
  {
    Node *delPrev = node->prev;
    Node *delNext = node->next;
    delPrev->next = delNext;
    delNext->prev = delPrev;
    size--;
  }
};

class LFUCache
{
  unordered_map<int, Node *> keyNode;
  unordered_map<int, List *> freqListMap;
  int maxSizeCache;
  int minFreq;
  int curSize;

public:
  LFUCache(int capacity)
  {
    maxSizeCache = capacity;
    curSize = 0;
    minFreq = 0;
  }

  void updateFreq(Node *node)
  {
    int oldFreq = node->cnt;
    freqListMap[oldFreq]->removeNode(node);

    if (oldFreq == minFreq && freqListMap[oldFreq]->size == 0)
    {
      minFreq++;
    }

    node->cnt++;

    List *newList;
    if (freqListMap.find(node->cnt) != freqListMap.end())
    {
      newList = freqListMap[node->cnt];
    }
    else
    {
      newList = new List();
    }

    newList->addFront(node);
    freqListMap[node->cnt] = newList;
  }

  int get(int key)
  {
    if (keyNode.find(key) == keyNode.end())
      return -1;

    Node *node = keyNode[key];
    updateFreq(node);
    return node->value;
  }

  void put(int key, int value)
  {
    if (maxSizeCache == 0)
      return;

    if (keyNode.find(key) != keyNode.end())
    {
      Node *node = keyNode[key];
      node->value = value;
      updateFreq(node);
    }
    else
    {
      if (curSize == maxSizeCache)
      {
        List *list = freqListMap[minFreq];
        Node *nodeToRemove = list->tail->prev;

        keyNode.erase(nodeToRemove->key);
        list->removeNode(nodeToRemove);
        delete nodeToRemove;
        curSize--;
      }

      curSize++;
      minFreq = 1;

      List *listFreq;
      if (freqListMap.find(minFreq) != freqListMap.end())
      {
        listFreq = freqListMap[minFreq];
      }
      else
      {
        listFreq = new List();
      }

      Node *node = new Node(key, value);
      listFreq->addFront(node);
      freqListMap[minFreq] = listFreq;
      keyNode[key] = node;
    }
  }
};

int main()
{
  LFUCache lfu(2);
  lfu.put(1, 1);              // cache is {1=1}
  lfu.put(2, 2);              // cache is {1=1, 2=2}
  cout << lfu.get(1) << endl; // return 1
  lfu.put(3, 3);              // evicts key 2, cache is {1=1, 3=3}
  cout << lfu.get(2) << endl; // return -1 (not found)
  cout << lfu.get(3) << endl; // return 3
  lfu.put(4, 4);              // evicts key 1, cache is {4=4, 3=3}
  cout << lfu.get(1) << endl; // return -1 (not found)
  cout << lfu.get(3) << endl; // return 3
  cout << lfu.get(4) << endl; // return 4
  return 0;
}