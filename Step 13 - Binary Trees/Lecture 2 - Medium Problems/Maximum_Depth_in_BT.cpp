#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  Node *left;
  Node *right;

  Node(int val)
  {
    data = val;
    left = right = NULL;
  }
};

int maxDepth(Node *root)
{
  if (root == NULL)
    return 0;

  return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

int main()
{
  Node *root = new Node(3);
  root->left = new Node(9);
  root->right = new Node(20);
  root->right->left = new Node(15);
  root->right->right = new Node(7);

  cout << maxDepth(root);

  return 0;
}