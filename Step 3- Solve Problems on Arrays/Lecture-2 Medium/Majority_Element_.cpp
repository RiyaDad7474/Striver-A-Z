#include<iostream>
#include<map>
#include<vector>
using namespace std;


// int majorityElement(vector<int> v){
//     map<int,int> mpp;
//     for(int i = 0;i<v.size();i++){
//         mpp[v[i]]++;
//     }
//     for(auto it: mpp){
//         if(it.second > (v.size()/2)){
//             return it.first;
//         }
//     }
//     return -1;
// }

//Moore's Voting Algorithm
int majorityElement(vector<int> v){
int cnt = 0;
int el;
for(int i = 0;i<v.size();i++){
    if(cnt == 0){
        cnt = 1;
        el = v[i];
    }
    else if(v[i] == el){
        cnt++;
    }
    else{
        cnt--;
    }
}
int cnt1 = 0;
for(int i = 0;i<v.size();i++){
    if(v[i] == el) cnt1++;
}
if(cnt1> (v.size() / 2)){
    return el;
}
return -1;
}

int main(){
    vector<int> v = {5,5,7,7,5,5,5,7,5,1,1};

   int result = majorityElement(v);
   
   if(result != -1){
    cout << result;
   }
   else{
    cout<<"not found";
   }

    return 0;
}