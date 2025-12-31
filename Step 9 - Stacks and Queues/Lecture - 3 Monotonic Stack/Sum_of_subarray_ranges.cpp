#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  long long subArrayRanges(vector<int> &nums)
  {
    int n = nums.size();
    long long sumMin = 0, sumMax = 0;
    stack<int> st;

    // -------- Sum of Subarray Minimums --------
    for (int i = 0; i <= n; i++)
    {
      while (!st.empty() && (i == n || nums[st.top()] > nums[i]))
      {
        int mid = st.top();
        st.pop();
        int left = st.empty() ? -1 : st.top();
        int right = i;
        sumMin += (long long)nums[mid] * (mid - left) * (right - mid);
      }
      st.push(i);
    }

    while (!st.empty())
      st.pop();

    // -------- Sum of Subarray Maximums --------
    for (int i = 0; i <= n; i++)
    {
      while (!st.empty() && (i == n || nums[st.top()] < nums[i]))
      {
        int mid = st.top();
        st.pop();
        int left = st.empty() ? -1 : st.top();
        int right = i;
        sumMax += (long long)nums[mid] * (mid - left) * (right - mid);
      }
      st.push(i);
    }

    return sumMax - sumMin;
  }
};
int main()
{
  Solution obj;
  vector<int> nums = {1, 2, 3};
  cout << "Sum of Subarray Ranges: " << obj.subArrayRanges(nums) << endl;
  return 0;
}
