#include<iostream>
using namespace std;


// void rev(int arr[],int l,int r){
//     if(l>=r){
//         return;
//     }
//     else{
//         swap(arr[l],arr[r]);
//         rev(arr,l+1,r-1);
//     }
// }
// int main(){
//     int arr[] = {1,2,3,4,5};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     rev(arr,0,n-1);

//     for (int i = 0; i < n; i++) {
//         cout << arr[i] << " ";
//     }

//     return 0;

//  }

void rev(int i,int arr[],int n){
    if(i>=n/2){
        return ;
    }
    else{
        swap(arr[i],arr[n-i-1]);
        rev(i+1,arr,n);
    }
}
int main(){
    int n=5;
    int arr[5] = {1,2,3,4,5};
    rev(0,arr,n);

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;

}