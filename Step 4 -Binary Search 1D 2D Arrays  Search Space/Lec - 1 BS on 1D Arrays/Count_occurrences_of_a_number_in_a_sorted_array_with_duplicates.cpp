#include <bits/stdc++.h>
using namespace std;

int firstOccurrence(const vector<int> &arr, int n, int k)
{
  int low = 0, high = n - 1;
  int first = -1;
  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    if (arr[mid] == k)
    {
      first = mid;
      high = mid - 1;
    }
    else if (arr[mid] < k)
    {
      low = mid + 1;
    }
    else
    {
      high = mid - 1;
    }
  }
  return first;
}

int lastOccurrence(const vector<int> &arr, int n, int k)
{
  int low = 0, high = n - 1;
  int last = -1;
  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    if (arr[mid] == k)
    {
      last = mid;
      low = mid + 1;
    }
    else if (arr[mid] < k)
    {
      low = mid + 1;
    }
    else
    {
      high = mid - 1;
    }
  }
  return last;
}

pair<int, int> firstAndLastPosition(const vector<int> &arr, int n, int k)
{
  int first = firstOccurrence(arr, n, k);
  if (first == -1)
    return {-1, -1};
  int last = lastOccurrence(arr, n, k);
  return {first, last};
}

int countOccurrences(const vector<int> &arr, int n, int x)
{
  auto pos = firstAndLastPosition(arr, n, x);
  if (pos.first == -1)
    return 0;
  return pos.second - pos.first + 1;
}

int main()
{
  vector<int> arr = {1, 2, 4, 7, 7, 9};
  int x = 7;
  int n = arr.size();
  auto pos = firstAndLastPosition(arr, n, x);
  cout << "First occurrence of " << x << " is: " << pos.first << "\n";
  cout << "Last occurrence of " << x << " is: " << pos.second << "\n";
  cout << "Count of " << x << " is: " << countOccurrences(arr, n, x) << "\n";
  return 0;
}
