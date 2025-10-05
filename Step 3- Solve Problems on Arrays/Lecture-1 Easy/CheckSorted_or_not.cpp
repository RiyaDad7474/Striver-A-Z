#include <bits/stdc++.h>
using namespace std; 

bool isSorted(int n, vector<int> a){
    for(int i = 1;i<n;i++){
        if(a[i] >= a[i-1]){

        }
        else{
            return false;
        }
    }
    return true;
}

int main() {
    int N;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    cout << isSorted(N, arr) << endl;
    return 0;
}