#include <bits/stdc++.h>
using namespace std;

int countStudents(vector<int> &arr, int pages)
{
  int students = 1;
  long long pagesStudent = 0;

  for (int i = 0; i < arr.size(); i++)
  {
    if (pagesStudent + arr[i] <= pages)
    {
      pagesStudent += arr[i];
    }
    else
    {
      students++;
      pagesStudent = arr[i];
    }
  }
  return students;
}

int findPages(vector<int> &arr, int n, int m)
{
  if (m > n)
    return -1;

  int low = *max_element(arr.begin(), arr.end());
  int high = accumulate(arr.begin(), arr.end(), 0);

  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    int students = countStudents(arr, mid);

    if (students > m)
      low = mid + 1;
    else
      high = mid - 1;
  }
  return low;
}

int largestSubarraySumMinimized(vector<int> a, int k)
{
  return findPages(a, a.size(), k);
}

int main()
{
  vector<int> arr = {10, 20, 30, 40};
  int m = 2;

  cout << largestSubarraySumMinimized(arr, m) << endl;
  return 0;
}
