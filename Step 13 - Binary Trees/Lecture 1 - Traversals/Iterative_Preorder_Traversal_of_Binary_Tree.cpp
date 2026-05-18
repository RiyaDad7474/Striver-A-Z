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

vector<int> preorderTraversal(Node *root)
{
  vector<int> preorder;
  if (root == NULL)
    return preorder;

  stack<Node *> st;
  st.push(root);
  while (!st.empty())
  {

    root = st.top();
    st.pop();
    preorder.push_back(root->data);
    if (root->right != NULL)
    {
      st.push(root->right);
    }
    if (root->left != NULL)
    {
      st.push(root->left);
    }
  }
  return preorder;
}

int main()
{
  Node *root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->right = new Node(4);

  vector<int> result = preorderTraversal(root);
  for (int i = 0; i < result.size(); i++)
  {
    cout << result[i] << " ";
  }
  return 0;
}