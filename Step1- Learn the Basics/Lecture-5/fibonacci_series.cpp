#include<iostream>
using namespace std;

int f(int n){
    if(n <= 1){
        return n;
    }
    int last = f(n-1);
    int slast = f(n-2);   //second last = slast
    return last + slast;
}
int main(){
    cout<<f(4);
    return 0;
}

//series - 0 1 1 2 3 5 8  13 21 34 55
//index -  0 1 2 3 4 5 6 7  8  9  10 11