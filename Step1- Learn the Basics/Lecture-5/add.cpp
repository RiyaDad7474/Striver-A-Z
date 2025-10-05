#include <iostream>
using namespace std;
int cnt = 0;
void add()
{
    
// int a=1;
// int b=2;
//     cout << a + b;
if(cnt==3){
    return;
}
cout<<cnt<<endl;
cnt++;
    add();
}

int main()
{
    // int a;
    // int b;
    add();

    return 0;
}