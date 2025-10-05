#include<bits/stdc++.h>
using namespace std;

// int longestSuccessiveElements(vector<int>&nums){
//   if(nums.size() == 0)   return 0;
//   sort(nums.begin(), nums.end());
//   int n = nums.size();
//   int lastSmaller = INT_MIN;
//   int cnt = 0;
//   int longest = 1;
//   for(int i = 0;i<n;i++){
//     if(nums[i] - 1 == lastSmaller){
//       cnt = cnt + 1;
//       lastSmaller = nums[i];
//     }
//     else if(lastSmaller != nums[i]){
//       cnt = 1;
//       lastSmaller = nums[i];
//     }
//     longest = max(longest, cnt);
//   }
//   return longest;
// } 

//optimal solution
int longestSuccessiveElements(vector<int>&nums){
  int n = nums.size();
  if(n==0) return 0;
  int longest= 1;
  unordered_set<int> st;
  for(int i = 0;i<n;i++){
    st.insert(nums[i]);
  }

  for(auto iy : st){
    if(st.find(iy - 1) == st.end()){
      int cnt = 1;
      int x = iy;
      while(st.find(x+1) != st.end() ){
        x = x+1;
        cnt = cnt + 1;
      }
      longest = max(longest, cnt);
    }
  }
  return longest;
}

int main(){
  vector<int> nums = {100,2,3,4,102,1};
  
    cout<< "Longest Consecutive Sequence Length = " <<longestSuccessiveElements(nums) << endl;
  
   return 0;
}