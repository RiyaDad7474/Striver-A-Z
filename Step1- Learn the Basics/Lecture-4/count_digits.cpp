#include<iostream>
using namespace std;
class Solution {
    public:
    int evenlyDivides(int n) {
    int count = 0;
    int m=n;
    while(n > 0) {
        int lastDigit = n % 10;
        if(lastDigit!=0 && m%lastDigit==0 )
        count = count + 1;
        n = n / 10;
    }
    return count;
    
    
}
};
       //OR
// int countDigits(int n){
//     int count = 0;
    
//     while(n > 0) {
//         count = count + 1;
//         n = n / 10;
//     }
//     return count;
    
    

// }

int main(){
    Solution sl;
    int result = sl.evenlyDivides(25);
    cout << result;
    return 0;
}