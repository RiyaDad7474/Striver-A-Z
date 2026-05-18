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

vector<int> inorderTraversal(Node *root)
{
  stack<Node *> st;
  Node *node = root;

  vector<int> inorder;
  while (true)
  {
    if (node != NULL)
    {
      st.push(node);
      node = node->left;
    }
    else
    {
      if (st.empty() == true)
        break;
      node = st.top();
      st.pop();
      inorder.push_back(node->data);
      node = node->right;
    }
  }

  return inorder;
}

int main()
{
  Node *root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->right = new Node(4);

  vector<int> result = inorderTraversal(root);

  for (int i = 0; i < result.size(); i++)
  {
    cout << result[i] << " ";
  }

  return 0;
}