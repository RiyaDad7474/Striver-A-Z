#include <bits/stdc++.h>
using namespace std;

//     vector<vector<int>>
//     threesum(int n, vector<int> &num)
// {

//   set<vector<int>> st;
//   for (int i = 0; i < n; i++)
//   {
//     set<int> hashset;
//     for (int j = i + 1; j < n; j++)
//     {
//       int third = -(num[i] + num[j]);
//       if (hashset.find(third) != hashset.end())
//       {
//         vector<int> temp = {num[i], num[j], third};
//         sort(temp.begin(), temp.end());
//         st.insert(temp);
//       }
//       hashset.insert(num[j]);
//     }
//   }
//   vector<vector<int>> ans(st.begin(), st.end());
//   return ans;
// }

// optimal approach
vector<vector<int>> triplet(int n, vector<int> &num)
{
  vector<vector<int>> ans;
  sort(num.begin(), num.end());
  for (int i = 0; i < n; i++)
  {
    if (i > 0 && num[i] == num[i - 1])
      continue;
    int j = i + 1;
    int k = n - 1;
    while (j < k)
    {
      int sum = num[i] + num[j] + num[k];
      if (sum < 0)
      {
        j++;
      }
      else if (sum > 0)
      {
        k--;
      }
      else
      {
        vector<int> temp = {num[i], num[j], num[k]};
        ans.push_back(temp);
        j++;
        k--;
        while (j < k && num[j] == num[j - 1])
          j++;
        while (j < k && num[k] == num[k + 1])
          k--;
      }
    }
  }

  return ans;
}

int main()
{
  vector<int> num = {
      -2,
      -2,
      -2,
      -1,
      -1,
      -1,
      0,
      0,
      0,
      2,
      2,
      2,
      2,
  };
  int n = num.size();

  vector<vector<int>> res = triplet(n, num);
  for (auto &triplet : res)
  {
    for (int x : triplet)
      cout << x << " ";
    cout << "\n";
  }

  return 0;
}