#include <bits/stdc++.h>
using namespace std; 

int removeDuplicates(vector<int> &arr, int n){
    int i = 0;
    for(int j = 1;j<n;j++){
        if(arr[i] !=arr[j]){
        
        i++;
        arr[i] = arr[j];
    }
}
return i+1;
}
int main(){
    int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
    
        int newSize = removeDuplicates(arr, n);
        cout << newSize << endl;
    
        // Optional: print the unique elements
        for (int i = 0; i < newSize; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        return 0;
    
}