#include <bits/stdc++.h>
using namespace std;

// Function to print all subsequences of arr[] with sum equal to 'sum'

// void printS(int ind, vector<int> &ds, int s, int sum, int arr[], int n)
// {
//   if (ind == n)
//   {
//     if (s == sum)
//     {
//       for (auto it : ds)
//         cout << it << " ";
//       cout << endl;
//     }
//     return;
//   }
//   ds.push_back(arr[ind]);
//   s += arr[ind];
//   printS(ind + 1, ds, s, sum, arr, n);
//   s -= arr[ind];
//   ds.pop_back();
//   printS(ind + 1, ds, s, sum, arr, n);
// }

// give only one subsequence with sum equal to 'sum'

// bool printS(int ind, vector<int> &ds, int s, int sum, int arr[], int n)
// {
//   if (ind == n)
//   {
//     // condition satisfied
//     if (s == sum)
//     {
//       for (auto it : ds)
//         cout << it << " ";
//       cout << endl;
//       return true;
//     }
//     else
//       return false;
//   }
//   ds.push_back(arr[ind]);
//   s += arr[ind];
//   if(printS(ind + 1, ds, s, sum, arr, n) == true)
//   {
//     return true;
//   }
//   s -= arr[ind];
//   ds.pop_back();
//   if (printS(ind + 1, ds, s, sum, arr, n) == true)
//     return true;
//   return false;
// }

// int main()
// {
//   int arr[] = {1, 2, 3};
//   int n = 3;
//   int sum = 2;
//   vector<int> ds;
//   printS(0, ds, 0, sum, arr, n);
//   return 0;
// }

// count number of subsequences with sum equal to 'k'

int printS(int ind, int s, int sum, int arr[], int n)
{
  //condition not satisfied
  // strictly done if array contains positives only
  if(s > sum) return 0;
  
  if (ind == n)
  {
    // condition satisfied
    if (s == sum)
    {
      return 1;
    }
    else
      return 0;
  }

  s += arr[ind];

  int l = printS(ind + 1, s, sum, arr, n);

  s -= arr[ind];

  int r = printS(ind + 1, s, sum, arr, n);

  return l + r;
}

int main()
{
  int arr[] = {1, 1, 2, 3};
  int n = 3;
  int sum = 2;
  cout << printS(0, 0, sum, arr, n);
  return 0;
}