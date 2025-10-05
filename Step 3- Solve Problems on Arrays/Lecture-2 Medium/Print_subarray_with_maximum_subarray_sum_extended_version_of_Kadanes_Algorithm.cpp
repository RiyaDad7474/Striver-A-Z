#include <bits/stdc++.h>
using namespace std;

long long maxSubarraySum(int arr[], int n){
    long long sum = 0, maxi = LLONG_MIN;
    int start = 0, ansStart = -1, ansEnd = -1;

    for(int i = 0; i < n; i++){
        sum += arr[i];

        if(sum > maxi){
            maxi = sum;
            ansStart = start;
            ansEnd = i;
        }

        if(sum < 0){
            sum = 0;
            start = i + 1;
        }
    }

    // Print subarray (optional)
    cout << "Subarray: ";
    for(int i = ansStart; i <= ansEnd; i++) cout << arr[i] << " ";
    cout << endl;

    return maxi;
}

int main() {
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    long long ans = maxSubarraySum(arr, n);
    cout << "Maximum Subarray Sum = " << ans << endl;
    return 0;
}
