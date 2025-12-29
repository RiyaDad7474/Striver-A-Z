#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> nextGreaterElements(vector<int> &nums)
  {
    int n = nums.size();
    vector<int> ans(n, -1);
    stack<int> st; // store indices

    for (int i = 0; i < 2 * n; i++)
    {
      int idx = i % n;

      while (!st.empty() && nums[st.top()] < nums[idx])
      {
        ans[st.top()] = nums[idx];
        st.pop();
      }

      // push index only in first pass
      if (i < n)
      {
        st.push(idx);
      }
    }
    return ans;
  }
};

int main()
{
  Solution obj;

  vector<int> nums = {1, 2, 1};

  vector<int> result = obj.nextGreaterElements(nums);

  cout << "Next Greater Elements: ";
  for (int x : result)
  {
    cout << x << " ";
  }
  cout << endl;

  return 0;
}
