#include <bits/stdc++.h>
using namespace std;

int celebrity(vector<vector<int>> &arr, int n)
{
  stack<int> st;

  // Step 1: Push all people
  for (int i = 0; i < n; i++)
  {
    st.push(i);
  }

  // Step 2: Elimination
  while (st.size() > 1)
  {
    int i = st.top();
    st.pop();
    int j = st.top();
    st.pop();

    if (arr[i][j] == 1)
    {
      st.push(j);
    }
    else
    {
      st.push(i);
    }
  }

  // Step 3: Verification
  int candidate = st.top();

  for (int i = 0; i < n; i++)
  {
    if (i != candidate)
    {
      if (arr[candidate][i] == 1 || arr[i][candidate] == 0)
      {
        return -1;
      }
    }
  }

  return candidate;
}

int main()
{
  int n = 4;
  vector<vector<int>> arr = {
      {0, 0, 1, 0},
      {0, 0, 1, 0},
      {0, 0, 0, 0},
      {0, 0, 1, 0}};

  int celeb = celebrity(arr, n);
  if (celeb != -1)
  {
    cout << "The celebrity is person " << celeb << endl;
  }
  else
  {
    cout << "There is no celebrity." << endl;
  }

  return 0;
}