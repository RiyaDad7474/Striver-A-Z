#include<iostream>
using namespace std;
#include<vector>

void leftRotate(int arr[], int n, int d){
    d = d % n;

    int temp[d];
    for(int i = 0; i<d; i++)           //temp array
    {
        temp[i] = arr[i];
    }

     for(int i = d; i<n; i++)           //shifting
    {
        arr[i - d] = arr[i];
    }

    for(int i = n-d; i<n; i++)          //push back
    {
        arr[i] = temp[i - (n-d)];
    }
}
// class Solution {
// public:
//     void rotate(vector<int>& nums, int k) {
//         int n = nums.size();
//         k = k%n;
//         reverse(nums,0,n-1);
//         reverse(nums,0,k-1);
//         reverse(nums,k,n-1);
//     }
//     private:
//       void reverse(vector<int>& nums,int start,int end){
//         while(start<=end){
//             int temp = nums[start];
//             nums[start] = nums[end];
//             nums[end] = temp;
//             start++;
//             end--;
//         }
//      }
// };

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    int d;
    cin>>d;
    leftRotate(arr,n,d);
    for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
    }

}