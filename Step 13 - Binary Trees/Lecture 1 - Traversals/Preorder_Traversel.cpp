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

vector<int> ans;

void preorder(Node *root)
{
  if (root == NULL)
    return;

  ans.push_back(root->data);
  preorder(root->left);
  preorder(root->right);
}

vector<int> preorderTraversal(Node *root)
{
  preorder(root);
  return ans;
}

int main()
{
  Node *root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->right = new Node(4);

  vector<int> result = preorderTraversal(root);
  for (int i = 1; i < result.size(); i++)
  {
    cout << i << " ";
  }
  return 0;
}