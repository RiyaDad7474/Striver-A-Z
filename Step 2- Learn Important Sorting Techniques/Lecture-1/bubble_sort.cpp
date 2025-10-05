#include <iostream>
using namespace std;

void bubble_Sort(int arr[], int n) {
    for (int i = n-1; i >= 0; i--) {
        int didSwap = 0;
        // Last i elements are already in place
        for (int j = 0; j <=  i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                didSwap = 1;
            }
        }
        if(didSwap == 0){
            break;
        }
        cout << "runs\n";
    }
}

int main(){
    int n;
        cin >> n;
        int arr[n];
        for(int i = 0; i<n; i++){
            cin >> arr[i];
        }
        bubble_Sort(arr,n);
        for(int i = 0; i<n; i++){
            cout << arr[i] << " ";
        }
        return 0;
    }