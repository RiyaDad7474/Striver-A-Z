#include<bits/stdc++.h>
using namespace std;

vector<int> superiorElements(vector<int>&a){

  //o(N) - Space
  vector<int> ans;
  int maxi = INT_MIN;
  int n = a.size();
  //O(N)
  for(int i = n-1;i>0;i--){
    if(a[i] > maxi){
      ans.push_back(a[i]);
    }
    //keep track of the right maximum
    maxi = max(maxi,a[i]);
  }

// o(N log N)
  sort(ans.begin() , ans.end());
  return ans;
}

int main(){


  vector<int> a = {4,15,22,8,9,2};
  vector<int> ans = superiorElements(a);

   cout << "Superior elements (descending): ";

  for(int i = ans.size()-1;i>=0;i--){
    cout<<ans[i] << " ";
  }
  

  return 0;

}
