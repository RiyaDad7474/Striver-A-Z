#include<iostream>
using namespace std;

int main(){
    int cnt = 0;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        if(n%i==0){
            cnt++;
        }
    }
        if(cnt==2){
           cout<<"prime";
        }
        else{
            cout<<"not prime";        
        } 
    
    //   for(int i=1;i*i<=n;i++){
    //     if(n%i==0){
    //         cnt++;
    //     }
    //     if((n/i)!=i){
    //         cnt++;
    //     }
    //   }
    //   if(cnt==2){
    //            cout<<"prime";
    //         }
    //         else{
    //             cout<<"not prime";        
    //         } 

    
    
    return 0;

}