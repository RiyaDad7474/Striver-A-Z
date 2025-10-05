#include <iostream>
using namespace std;

void selection_Sort(int arr[], int n) {
    for (int i = 0; i <= n - 2; i++) {  // Step 1: Move the boundary of the unsorted subarray
        int minIndex = i;              // Step 2: Assume the first element is the minimum
        for (int j = i ; j <= n-1; j++) {  // Step 3: Find the minimum element in unsorted part
            if (arr[j] < arr[minIndex])   // Step 4: Update minIndex if a smaller element is found
                minIndex = j;
        }
        // Step 5: Swap the found minimum element with the first element
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

int main(){
int n;
    cin >> n; 
    int arr[n];
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }
    selection_Sort(arr,n);
    for(int i = 0; i<n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}