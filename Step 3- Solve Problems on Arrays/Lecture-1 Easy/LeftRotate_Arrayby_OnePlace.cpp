#include<iostream>
#include<vector>
using namespace std;

 class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int temp = nums[0];
        for(int i = 1;i<k;i++){
            nums[i-1] = nums[i];
        }
        nums[k-1] = temp;
        return nums;
    }
};