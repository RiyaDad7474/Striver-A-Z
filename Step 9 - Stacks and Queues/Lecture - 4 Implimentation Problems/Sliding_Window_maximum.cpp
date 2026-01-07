#include <bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
  deque<int> dq;
  vector<int> list;
  for (int i = 0; i < nums.size(); i++)
  {
    if (!dq.empty() && dq.front() == i - k)
    {
      dq.pop_front();
    }
    while (!dq.empty() && nums[dq.back()] <= nums[i])
      dq.pop_back();

    dq.push_back(i);

    if (i >= k - 1)
      list.push_back(nums[dq.front()]);
  }
  return list;
}

int main()
{
  int n, k;
  cin >> n >> k;
  vector<int> nums(n);
  for (int i = 0; i < n; i++)
    cin >> nums[i];

  vector<int> result = maxSlidingWindow(nums, k);
  for (int val : result)
    cout << val << " ";
  cout << endl;

  return 0;
}