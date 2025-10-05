#include <bits/stdc++.h>
using namespace std;

void merge(long long arr1[], long long arr2[], int n, int m)
{

  // Declare 2 pointers:
  int left = n - 1;
  int right = 0;

  // Swap the elements until arr1[left] is
  //  smaller than arr2[right]:
  while (left >= 0 && right < m)
  {
    if (arr1[left] > arr2[right])
    {
      swap(arr1[left], arr2[right]);
      left--, right++;
    }
    else
    {
      break;
    }
  }

  // Sort arr1[] and arr2[] individually:
  sort(arr1, arr1 + n);
  sort(arr2, arr2 + m);
}

int main()
{
  long long arr1[] = {1, 4, 8, 10};
  long long arr2[] = {2, 3, 9};
  int n = 4, m = 3;
  merge(arr1, arr2, n, m);
  cout << "The merged arrays are: " << "\n";
  cout << "arr1[] = ";
  for (int i = 0; i < n; i++)
  {
    cout << arr1[i] << " ";
  }
  cout << "\narr2[] = ";
  for (int i = 0; i < m; i++)
  {
    cout << arr2[i] << " ";
  }
  cout << endl;
  return 0;
}

// leetcode p ye code likha h

// class Solution {
// public:
//     void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//         int left = m - 1;   // last valid element of nums1
//         int right = 0;      // first element of nums2

//         // Step 1: Swap if nums1[left] > nums2[right]
//         while (left >= 0 && right < n) {
//             if (nums1[left] > nums2[right]) {
//                 swap(nums1[left], nums2[right]);
//                 left--;
//                 right++;
//             } else {
//                 break;
//             }
//         }

//         // Step 2: Sort both parts
//         sort(nums1.begin(), nums1.begin() + m);
//         sort(nums2.begin(), nums2.end());

//         // Step 3: Copy nums2 into nums1
//         for (int i = 0; i < n; i++) {
//             nums1[m + i] = nums2[i];
//         }
//     }
// };
