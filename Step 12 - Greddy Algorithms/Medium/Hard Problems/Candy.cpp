#include <bits/stdc++.h>
using namespace std;

// TC -> O(3N)
// SC -> O(2N)

// int candy(vector<int> &ratings)
// {
//   int n = ratings.size();
//   vector<int> left(n);
//   vector<int> right(n);

//   left[0] = 1;
//   right[n - 1] = 1;

//   for (int i = 1; i < n; i++)
//   {
//     if (ratings[i] > ratings[i - 1])
//     {
//       left[i] = left[i - 1] + 1;
//     }
//     else
//     {
//       left[i] = 1;
//     }
//   }

//   for (int i = n - 2; i >= 0; i--)
//   {
//     if (ratings[i] > ratings[i + 1])
//     {
//       right[i] = right[i + 1] + 1;
//     }
//     else
//     {
//       right[i] = 1;
//     }
//   }

//   int sum = 0;
//   for (int i = 0; i < n; i++)
//   {
//     sum = sum + max(left[i], right[i]);
//   }
//   return sum;
// }

// TC->O(2N)
// SC->O(N);

// int candy(vector<int> &ratings)
// {
//   int n = ratings.size();
//   vector<int> left(n);

//   left[0] = 1;

//   for (int i = 1; i < n; i++)
//   {
//     if (ratings[i] > ratings[i - 1])
//     {
//       left[i] = left[i - 1] + 1;
//     }
//     else
//     {
//       left[i] = 1;
//     }
//   }
//   int curr = 1, right = 1;
//   int sum = max(1, left[n - 1]);

//   for (int i = n - 2; i >= 0; i--)
//   {
//     if (ratings[i] > ratings[i + 1])
//     {
//       curr = curr + 1;
//     }
//     else
//     {
//       curr = 1;
//     }
//     sum = sum + max(left[i], curr);
//   }
//   return sum;
// }

// Optimal Solution

// TC -> O(N)
// SC -> O(1)
int candy(vector<int> &ratings)
{
  int sum = 1, i = 1;
  int n = ratings.size();

  while (i < n)
  {
    if (ratings[i] == ratings[i - 1])
    {
      sum++;
      i++;
      continue;
      ;
    }

    int peak = 1;
    while (i < n && ratings[i] > ratings[i - 1])
    {
      peak++;
      sum += peak;
      i++;
    }
    int down = 1;
    while (i < n && ratings[i] < ratings[i - 1])
    {
      sum += down;
      i++;
      down++;
    }

    if (down > peak)
    {
      sum += down - peak;
    }
  }
  return sum;
}
int main()
{
  vector<int> ratings = {1, 0, 2};
  cout << candy(ratings);
  return 0;
}