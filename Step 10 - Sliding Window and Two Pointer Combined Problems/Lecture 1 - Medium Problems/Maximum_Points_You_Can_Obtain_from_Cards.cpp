#include <bits/stdc++.h>
using namespace std;

int maxScore(vector<int> &cardPoints, int k)
{
  int lSum = 0, rSum = 0;
  int maxSum = 0;
  int n = cardPoints.size();
  for (int i = 0; i < k; i++)
  {
    lSum = lSum + cardPoints[i];
  }
  maxSum = lSum;

  int rIndex = n - 1;
  for (int i = k - 1; i >= 0; i--)
  {
    lSum = lSum - cardPoints[i];
    rSum = rSum + cardPoints[rIndex];
    rIndex = rIndex - 1;

    maxSum = max(maxSum, lSum + rSum);
  }
  return maxSum;
}

int main()
{
  vector<int> cardPoints = {1, 2, 3, 4, 5, 6, 1};
  int k;
  cin >> k;
  cout << maxScore(cardPoints, k);
  return 0;
}