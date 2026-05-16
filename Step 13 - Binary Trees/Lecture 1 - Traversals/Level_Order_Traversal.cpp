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

vector<int> levelOrder(Node *root)
{
  vector<int> ans;
  if (root == NULL)
    return ans;

  queue<Node *> q;
  q.push(root);

  while (!q.empty())
  {
    Node *curr = q.front();
    q.pop();

    ans.push_back(curr->data);

    if (curr->left != NULL)
      q.push(curr->left);

    if (curr->right != NULL)
      q.push(curr->right);
  }

  return ans;
}

int main()
{
  Node *root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->right = new Node(4);

  vector<int> result = levelOrder(root);

  for (int i = 0; i < result.size(); i++)
  {
    cout << result[i] << " ";
  }

  return 0;
}