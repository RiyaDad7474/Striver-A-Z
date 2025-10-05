#include<iostream>
using namespace std;

int main(){
    int n = 8;
    int nums = 5;
    int arr[] = {3,56,3,25,6,2,8,5};
    for(int i = 0;i<n;i++){
        if(arr[i] == nums){
             cout << "Found at index: " << i << endl;
          return 0;
        }
    }
           cout << -1 << endl;

    return 0;
}

