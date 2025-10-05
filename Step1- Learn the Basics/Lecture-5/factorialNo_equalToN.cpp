#include <iostream>
#include<vector>
using namespace std;

class Solution {
    public:
      vector<long long> factorialNumbers(long long n) {
           vector<long long> v;
          long long fact = 1;
          for(int i=1;;i++){
              fact*=i;
              if(fact>n) break;
  
              v.push_back(fact);
          }
          return v;
      }
  };
int main(){
    long long n;
    cin>>n;
    Solution s;
    vector<long long> result  =s.factorialNumbers(n);
    cout << "Factorial numbers less than or equal to " << n << " are:\n";
    for (long long f : result) {
        cout << f << " ";
    }
    cout << endl;

    return 0;
}