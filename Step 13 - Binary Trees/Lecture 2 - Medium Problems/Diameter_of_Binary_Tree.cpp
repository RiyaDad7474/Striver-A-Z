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

int height(TreeNode *root)
{
  if (root == NULL)
    return 0;

  int leftH = height(root->left);
  if (leftH == -1)
    return -1;

  int rightH = height(root->right);
  if (rightH == -1)
    return -1;

  if (abs(leftH - rightH) > 1)
    return -1;

  return max(leftH, rightH) + 1;
}

bool isBalanced(TreeNode *root)
{
  return height(root) != -1;
}

int main()
{
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(9);
  root->right = new TreeNode(20);
  root->right->left = new TreeNode(15);
  root->right->right = new TreeNode(7);
  // root->right->right->right = new TreeNode(8);

  cout << isBalanced(root);

  return 0;
}