#include <bits/stdc++.h>
using namespace std; 
int findSecondLargest(int n, vector<int> &arr)
{
    int largest = arr[0];
for(int i = 0;i<n;i++){
    if(arr[i]>largest){
        largest = arr[i];
    }
}
int slargest = INT_MIN;
for(int i=0;i<n;i++){
    if((arr[i]>slargest) && (arr[i]!=largest)){
        slargest = arr[i];
    }
}
if (slargest == INT_MIN)
    return -1;
else
    return slargest;

}
int main() {
    int N;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    cout << findSecondLargest(N, arr) << endl;
    return 0;
}