#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int largestRectangleArea(vector<int> &h)
  {
    stack<int> st;
    int maxArea = 0;

    for (int i = 0; i <= h.size(); i++)
    {
      int curr = (i == h.size()) ? 0 : h[i];

      while (!st.empty() && curr < h[st.top()])
      {
        int height = h[st.top()];
        st.pop();

        int width;
        if (st.empty())
          width = i;
        else
          width = i - st.top() - 1;

        maxArea = max(maxArea, height * width);
      }
      st.push(i);
    }
    return maxArea;
  }

  int maximalRectangle(vector<vector<char>> &matrix)
  {
    if (matrix.empty())
      return 0;

    int n = matrix.size();
    int m = matrix[0].size();

    vector<int> heights(m, 0);
    int ans = 0;

    // ONLY TWO FOR LOOPS (i, j)
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (matrix[i][j] == '1')
          heights[j]++;
        else
          heights[j] = 0;
      }
      ans = max(ans, largestRectangleArea(heights));
    }
    return ans;
  }
};

int main()
{
  Solution sol;
  vector<vector<char>> matrix = {
      {'1', '0', '1', '0', '0'},
      {'1', '0', '1', '1', '1'},
      {'1', '1', '1', '1', '1'},
      {'1', '0', '0', '1', '0'}};

  cout << "Maximal Rectangle Area: " << sol.maximalRectangle(matrix) << endl;
  return 0;
}