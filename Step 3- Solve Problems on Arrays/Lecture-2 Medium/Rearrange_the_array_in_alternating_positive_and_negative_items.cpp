#include <bits/stdc++.h>
using namespace std;

vector<int> rearrrangeArray(vector<int>& nums){
  int n = nums.size();
  vector<int> ans(n,0);
  int posIndex = 0, negIndex = 1;
  for(int i = 0;i<n;i++){
    if(nums[i] < 0){
      ans[negIndex] = nums[i];
      negIndex +=2;
    }
    else{
      ans[posIndex] = nums[i];
      posIndex +=2;
    }
  }
  return ans;
}

int main(){
  vector<int> nums= {-5,4,-8,-2,9,1};
  vector<int> result = rearrrangeArray(nums);
  for(int i = 0;i<result.size();i++){
    cout<<result[i]<<","<<" ";
  }
  return 0;
}

