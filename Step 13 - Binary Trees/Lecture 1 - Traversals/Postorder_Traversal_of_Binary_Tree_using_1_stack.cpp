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

  stack<TreeNode *> st;
  TreeNode *curr = root;

  while (curr != NULL || !st.empty())
  {
    if (curr != NULL)
    {
      st.push(curr);
      curr = curr->left;
    }
    else
    {
      TreeNode *temp = st.top()->right;

      if (temp == NULL)
      {
        temp = st.top();
        st.pop();
        postorder.push_back(temp->data);

        while (!st.empty() && temp == st.top()->right)
        {
          temp = st.top();
          st.pop();
          postorder.push_back(temp->data);
        }
      }
      else
      {
        curr = temp;
      }
    }
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