#include <bits/stdc++.h>
using namespace std;


//same but here positives and negstives and not present in equal number

vector<int> rearrrangeArray(vector<int>& a){
  vector<int> pos,neg;
  int n = a.size();
  for(int i = 0;i<n;i++){
    if(a[i] > 0){
      pos.push_back(a[i]);
    }
    else{
      neg.push_back(a[i]);
    }
  }

  // Case 1: More positives than negatives
  if(pos.size() > neg.size()){
    for(int i = 0;i<neg.size();i++){
     a[2*i] = pos[i];     // positive in even index
        a[2*i+1] = neg[i];   // negative in odd index
    }
    int index = neg.size() * 2;
    for(int i = neg.size();i<pos.size();i++){
        a[index] = pos[i];   // leftover positives at end
      index++;
    }
  }

  // Case 2: More negatives than positives
  else{
    for(int i = 0;i<pos.size();i++){
      a[2*i] = pos[i];
      a[2*i+1] = neg[i];
    }
     int index = pos.size() * 2;
    for(int i = pos.size();i<neg.size();i++){
      a[index]=  neg[i];
      index++;
    }
  }
  return a;
}

int main(){
  vector<int> a = {3,1,-2,-5,2,-4,6};
  vector<int> result = rearrrangeArray(a);

  for(int i = 0;i<result.size();i++){
    cout<< result[i] << " ";
  }
  return 0;
}
