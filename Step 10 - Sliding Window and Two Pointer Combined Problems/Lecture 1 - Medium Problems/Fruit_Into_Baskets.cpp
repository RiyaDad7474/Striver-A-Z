#include <bits/stdc++.h>
using namespace std;

// Bruteforce Approach
// int FruitsIntoBaskets(vector<int> &fruits)
// {
//   int maxlen = 0;
//   for (int i = 0; i < fruits.size(); i++)
//   {
//     set<int> st;
//     for (int j = i; j < fruits.size(); j++)
//     {
//       st.insert(fruits[j]);
//       if (st.size() <= 2)
//       {
//         maxlen = max(maxlen, j - i + 1);
//       }
//       else
//         break;
//     }
//   }
// }

// Better Approach
// int FruitsIntoBaskets(vector<int> &fruits, int k)
// {
//   int maxlen = 0, l = 0, r = 0;
//   unordered_map<int, int> mpp;
//   while (r < fruits.size())
//   {
//     mpp[fruits[r]]++;

//     while (mpp.size() > k)
//     {
//       mpp[fruits[l]]--;
//       if (mpp[fruits[l]] == 0)
//         mpp.erase(fruits[l]);
//       l++;
//     }

//     if (mpp.size() <= k)
//     {
//       maxlen = max(maxlen, r - l + 1);
//     }
//     r++;
//   }
//   return maxlen;
// }

// Optimal Approach
int FruitsIntoBaskets(vector<int> &fruits, int k)
{
  int maxlen = 0, l = 0, r = 0;
  unordered_map<int, int> mpp;

  while (r < fruits.size())
  {
    mpp[fruits[r]]++;

    if (mpp.size() > k)
    {
      mpp[fruits[l]]--;
      if (mpp[fruits[l]] == 0)
        mpp.erase(fruits[l]);
      l++;
    }
    if (mpp.size() <= k)
      maxlen = max(maxlen, r - l + 1);
    r++;
  }
  return maxlen;
}

int main()
{
  int k;
  cin >> k;
  vector<int> fruits = {3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4};
  cout << FruitsIntoBaskets(fruits, k);

  return 0;
}
