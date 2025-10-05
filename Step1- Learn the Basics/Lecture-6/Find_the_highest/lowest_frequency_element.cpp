#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        long n = nums.size();
        sort(nums.begin(),nums.end());
        long l = 0, r= 0;
        long total = 0,res =0;

        while(r<n){
            total+=nums[r];
            while((nums[r] * (r-l+1)) > (total + k)){
                total -=nums[l];
                l++;
            }
            res = max(res,(r-l+1));
            r++;
        }
        return res;
    }
};

int main(){
  Solution sol;

    vector<int> nums = {1, 2, 4}; 
    int k = 5;

    cout << "Maximum Frequency: " << sol.maxFrequency(nums, k) << endl;

    return 0;
}