#include <bits/stdc++.h>
using namespace std;

long long maxSubarraySum(int arr[], int n)
{
    long long sum = 0, maxi = LONG_MIN, start, ansStart = -1, ansEnd = -1;
    for (int i = 0; i < n; i++)
    {

        if (sum == 0)
        {
            start = i;
        }

        sum += arr[i];

        if (sum > maxi)
        {
            maxi = sum;
            ansStart = start, ansEnd = i;
        }
    }