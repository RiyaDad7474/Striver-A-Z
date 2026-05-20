#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int x)
  {
    val = x;
    left = right = NULL;
  }
};

class Solution
{
public:
  vector<vector<int>> preInPostTraversal(TreeNode *root)
  {
    vector<int> pre, in, post;

    if (root == NULL)
      return {pre, in, post};

    stack<pair<TreeNode *, int>> st;
    st.push({root, 1});

    while (!st.empty())
    {
      auto it = st.top();
      st.pop();

      // STATE 1 -> Preorder
      if (it.second == 1)
      {
        pre.push_back(it.first->val);
        it.second++;

        st.push(it);

        if (it.first->left != NULL)
        {
          st.push({it.first->left, 1});
        }
      }

      // STATE 2 -> Inorder
      else if (it.second == 2)
      {
        in.push_back(it.first->val);
        it.second++;

        st.push(it);

        if (it.first->right != NULL)
        {
          st.push({it.first->right, 1});
        }
      }

      // STATE 3 -> Postorder
      else
      {
        post.push_back(it.first->val);
      }
    }

    return {pre, in, post};
  }
};

int main()
{
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->right = new TreeNode(4);

  Solution obj;
  vector<vector<int>> res = obj.preInPostTraversal(root);

  cout << "Preorder: ";
  for (int x : res[0])
    cout << x << " ";
  cout << "\nInorder: ";
  for (int x : res[1])
    cout << x << " ";
  cout << "\nPostorder: ";
  for (int x : res[2])
    cout << x << " ";

  return 0;
}