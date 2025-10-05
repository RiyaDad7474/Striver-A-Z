#include<iostream>
using namespace std;

// void sumOfSeries(int i,int sum){
//     if(i<1){
//         cout<<sum;
//         cout<<sum*sum;
//         return ;
//     }
//     sumOfSeries(i-1,sum+i);
// }
// int main(){
//     int n;
//     cin>>n;
//     sumOfSeries(n,0);
//     return 0;
// }

int sum(int n){
    if(n==0){
        return 0;
    }
    else
    return n+sum(n-1);
}
int main(){
    int n;
    cin>>n;
    cout<<sum(n);
    return 0;
}

