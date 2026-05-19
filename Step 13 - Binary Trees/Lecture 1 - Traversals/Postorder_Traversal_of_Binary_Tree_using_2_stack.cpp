#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
  int data;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int val)
  {
    data = val;
    left = right = NULL;
  }
};

vector<int> postorderTraversal(TreeNode *root)
{
  vector<int> postorder;

  if (root == NULL)
    return postorder;

  stack<TreeNode *> st1, st2;

  st1.push(root);

  while (!st1.empty())
  {

    root = st1.top();
    st1.pop();

    st2.push(root);

    if (root->left != NULL)
    {
      st1.push(root->left);
    }

    if (root->right != NULL)
    {
      st1.push(root->right);
    }
  }

  while (!st2.empty())
  {
    postorder.push_back(st2.top()->data);
    st2.pop();
  }

  return postorder;
}

int main()
{
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->right = new TreeNode(4);

  vector<int> result = postorderTraversal(root);

  for (int i = 0; i < result.size(); i++)
  {
    cout << result[i] << " ";
  }
  return 0;
}