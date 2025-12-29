#include <bits/stdc++.h>
using namespace std;

vector<int> countNGEwithStack(vector<int> &arr)
{
  int n = arr.size();
  vector<int> ans(n);
  stack<int> st;

  // traverse from right to left
  for (int i = n - 1; i >= 0; i--)
  {

    // remove smaller or equal elements
    while (!st.empty() && st.top() <= arr[i])
    {
      st.pop();
    }

    // stack size gives count
    ans[i] = st.size();

    // push current element
    st.push(arr[i]);
  }
  return ans;
}

int main()
{
  vector<int> arr = {3, 4, 9, 6, 1};

  vector<int> result = countNGEwithStack(arr);

  cout << "Number of NGEs to the right (stack): ";
  for (int x : result)
  {
    cout << x << " ";
  }
  cout << endl;

  return 0;
}
