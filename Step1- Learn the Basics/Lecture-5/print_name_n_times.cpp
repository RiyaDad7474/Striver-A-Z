#include<iostream>
using namespace std;

// void print(int i,int n){
//     if(i>n){
//         return;
//     }
//     cout<<"riya"<<endl;
//     print(i+1,n);
// }
// int main(){
//     int n,i;
//     cin>>n;
//     print(1,n);
//     return 0;
// }


void printGfg(int N) {
    if (N <= 0) { // Base condition: Stop when N reaches 0
        return;
    }
    cout << "GFG" << endl;
    printGfg(N - 1); // Recursive call with N decremented
}

int main() {
    int N;
    cin >> N;
    printGfg(N); // Call function with N
    return 0;
}
