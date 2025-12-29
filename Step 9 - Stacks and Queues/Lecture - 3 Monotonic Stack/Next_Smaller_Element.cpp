#include <bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElement(vector<int> &arr)
{
  int n = arr.size();
  vector<int> ans(n);
  stack<int> st; // stores elements

  for (int i = n - 1; i >= 0; i--)
  {
    // pop until smaller element found
    while (!st.empty() && st.top() >= arr[i])
    {
      st.pop();
    }

    // if stack empty, no smaller element
    ans[i] = st.empty() ? -1 : st.top();

    // push current element
    st.push(arr[i]);
  }
  return ans;
}

int main()
{
  vector<int> arr = {4, 8, 5, 2, 25};

  vector<int> result = nextSmallerElement(arr);

  cout << "Next Smaller Elements: ";
  for (int x : result)
  {
    cout << x << " ";
  }
  cout << endl;

  return 0;
}
